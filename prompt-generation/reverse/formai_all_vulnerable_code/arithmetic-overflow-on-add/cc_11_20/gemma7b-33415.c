//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int i, j, k, l, m, n;

    printf("Enter the number of rows for matrix A:");
    scanf("%d", &n);

    printf("Enter the number of columns for matrix A:");
    scanf("%d", &m);

    printf("Enter the number of rows for matrix B:");
    scanf("%d", &l);

    printf("Enter the number of columns for matrix B:");
    scanf("%d", &k);

    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    b = (int **)malloc(l * sizeof(int *));
    for (i = 0; i < l; i++)
    {
        b[i] = (int *)malloc(k * sizeof(int));
    }

    c = (int **)malloc((n + l) * sizeof(int *));
    for (i = 0; i < n + l; i++)
    {
        c[i] = (int *)malloc((m + k) * sizeof(int));
    }

    printf("Enter the elements of matrix A:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < n + l; i++)
    {
        for (j = 0; j < m + k; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < l; k++)
            {
                for (l = 0; l < m; l++)
                {
                    c[i][j] += a[k][l] * b[k][l];
                }
            }
        }
    }

    printf("The product of the two matrices is:");
    for (i = 0; i < n + l; i++)
    {
        for (j = 0; j < m + k; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}