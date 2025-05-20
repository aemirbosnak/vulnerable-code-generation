//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[1000], b[1000], c[1000], d[1000], e[1000], f[1000];

    printf("Enter the number of test cases:");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the number of points:");
        scanf("%d", &m);

        for(j = 0; j < m; j++)
        {
            printf("Enter the coordinates of the point:");
            scanf("%d %d", &a[j], &b[j]);
        }

        for(k = 0; k < m; k++)
        {
            c[k] = a[k] + b[k];
        }

        for(l = 0; l < m; l++)
        {
            d[l] = c[l] / 2;
        }

        for(m = 0; m < m; m++)
        {
            e[m] = d[m] * d[m];
        }

        for(n = 0; n < m; n++)
        {
            f[n] = e[n] - 1;
        }

        printf("The distances of the points from the center of the circle are:");
        for(i = 0; i < m; i++)
        {
            printf("%d ", f[i]);
        }

        printf("\n");
    }

    return 0;
}