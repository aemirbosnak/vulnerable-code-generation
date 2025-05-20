//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void matrix_operations()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int rows, cols, i, j, k;

    printf("Enter the number of rows and columns for matrix A:");
    scanf("%d %d", &rows, &cols);

    a = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of matrix A:");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B:");
    scanf("%d %d", &rows, &cols);

    b = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        b[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of matrix B:");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }

    c = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        c[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < cols; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The product of matrix A and matrix B is:");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);
}

int main()
{
    matrix_operations();

    return 0;
}