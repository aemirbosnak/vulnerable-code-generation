//Gemma-7B DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, n, m, a[10][10], b[10][10], c[10][10], d[10][10], e[10][10], f[10][10];

    printf("Enter the number of rows and columns:");
    scanf("%d %d", &n, &m);

    printf("Enter the elements of the matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    // Calculate the transpose of the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    // Calculate the sum of the transpose of the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += b[k][j];
            }
        }
    }

    // Print the sum of the transpose of the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}