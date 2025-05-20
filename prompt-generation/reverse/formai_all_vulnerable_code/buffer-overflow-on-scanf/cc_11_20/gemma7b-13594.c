//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int i, j, k, l, m, n, a, b, c, d, e, f, g, h, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5;

    printf("Enter the number of rows of the matrix:");
    scanf("%d", &n);

    printf("Enter the number of columns of the matrix:");
    scanf("%d", &m);

    printf("Enter the elements of the matrix:");
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The elements of the matrix are:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of rows of the second matrix:");
    scanf("%d", &i1);

    printf("Enter the number of columns of the second matrix:");
    scanf("%d", &j1);

    printf("Enter the elements of the second matrix:");
    int **arr2 = (int **)malloc(i1 * sizeof(int *));
    for (i = 0; i < i1; i++)
    {
        arr2[i] = (int *)malloc(j1 * sizeof(int));
        for (j = 0; j < j1; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("The elements of the second matrix are:");
    for (i = 0; i < i1; i++)
    {
        for (j = 0; j < j1; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    printf("The product of the two matrices is:");
    int **arr3 = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr3[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            arr3[i][j] = 0;
            for (k = 0; k < i1; k++)
            {
                for (l = 0; l < j1; l++)
                {
                    arr3[i][j] += arr[i][k] * arr2[k][l];
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}