//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a, **b, **c, n, m, i, j, k;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &n, &m);
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &n, &m);
    b = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    c = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("The product of the two matrices is:\n");
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