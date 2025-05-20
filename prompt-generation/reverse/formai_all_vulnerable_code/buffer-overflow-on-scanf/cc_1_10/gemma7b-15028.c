//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of points: ");
        scanf("%d", &m);

        for (j = 0; j < m; j++)
        {
            printf("Enter the coordinates of the point: ");
            scanf("%d %d", &a[j], &b[j]);
        }

        for (k = 0; k < m; k++)
        {
            c[k] = a[k] + b[k];
        }

        for (l = 0; l < m; l++)
        {
            d[l] = c[l] * c[l];
        }

        for (m = 0; m < m; m++)
        {
            e[m] = d[m] - a[m] * a[m];
        }

        for (n = 0; n < m; n++)
        {
            f[n] = e[n] / 2;
        }

        for (i = 0; i < m; i++)
        {
            g[i] = f[i] + a[i];
        }

        for (j = 0; j < m; j++)
        {
            h[j] = g[j] - b[j];
        }

        printf("The distance of the points from the center of the circle is: ");

        for (k = 0; k < m; k++)
        {
            printf("%d ", h[k]);
        }

        printf("\n");
    }

    return 0;
}