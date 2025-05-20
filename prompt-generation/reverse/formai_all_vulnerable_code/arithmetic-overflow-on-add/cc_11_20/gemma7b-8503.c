//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int i, j, k, l, m, n, o;

    printf("Enter the number of rows for matrix A:");
    scanf("%d", &n);

    printf("Enter the number of columns for matrix A:");
    scanf("%d", &m);

    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the number of rows for matrix B:");
    scanf("%d", &l);

    printf("Enter the number of columns for matrix B:");
    scanf("%d", &o);

    b = (int **)malloc(l * sizeof(int *));
    for (i = 0; i < l; i++)
    {
        b[i] = (int *)malloc(o * sizeof(int));
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
        for (j = 0; j < o; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    c = (int **)malloc((n + l) * sizeof(int *));
    for (i = 0; i < n + l; i++)
    {
        c[i] = (int *)malloc((m + o) * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < l; k++)
            {
                for (l = 0; l < o; l++)
                {
                    c[i][j] += a[k][l] * b[k][l];
                }
            }
        }
    }

    printf("The product of the two matrices is:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
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