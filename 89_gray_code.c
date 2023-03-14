/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   89_gray_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:56:21 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/14 11:42:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* char	ft_xor(char a, char b)
{
	if (a == b)
		return ('0');
	else
		return ('1');
}

char	ft_flip(char c)
{
	if (c == '0')
		return ('1');
	else
		return ('0');
} */

/* This function returns all 32 bits of a number, assuming a 32-bit integer.*/
int	decimal_to_binary(int num)
{
	int	i;
	int	mask;
	int	rtrn;

	i = 31;
	rtrn = 0;
	while (i >= 0)
	{
		mask = (1 << i);
		rtrn = rtrn >> 1;
		if (num & mask)
			rtrn = rtrn | 1;
		i--;
	}
	return (rtrn);
}

int	*graycode(int n, int *returnsize)
{
	int	*arr;
	int	i;
	int	a;

	arr = malloc(*returnsize * sizeof(int));
	i = 0;
	while (i < (1 << n))
	{
		a = i ^ (i >> 1);
		arr[i] = decimal_to_binary(a);
		i++;
	}
	return (arr);
}

int	main(void)
{
	int		i;
	int		n;
	int		*arr;
	int		rs;

	i = -1;
	n = 2;
	rs = pow(2.0, (double)n);
	arr = graycode(n, &rs);
	while (++i < rs)
		printf("%d\n", arr[i]);
	free(arr);
	return (0);
}
