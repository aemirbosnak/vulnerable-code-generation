//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 10

int main()
{
    int dim1, dim2, dim3;
    int **a, **b, **c;

    // Get dimensions of matrices a and b
    printf("Enter the number of rows for matrix a: ");
    scanf("%d", &dim1);

    printf("Enter the number of columns for matrix a: ");
    scanf("%d", &dim2);

    // Allocate memory for matrices a, b, and c
    a = (int **)malloc(dim1 * sizeof(int *));
    for (int i = 0; i < dim1; i++)
    {
        a[i] = (int *)malloc(dim2 * sizeof(int));
    }

    b = (int **)malloc(dim2 * sizeof(int *));
    for (int i = 0; i < dim2; i++)
    {
        b[i] = (int *)malloc(dim2 * sizeof(int));
    }

    c = (int **)malloc(dim1 * sizeof(int *));
    for (int i = 0; i < dim1; i++)
    {
        c[i] = (int *)malloc(dim2 * sizeof(int));
    }

    // Get the elements of matrix a and b
    printf("Enter the elements of matrix a: ");
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix b: ");
    for (int i = 0; i < dim2; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < dim2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print the elements of matrix c
    printf("The elements of matrix c are: ");
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < dim1; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < dim2; i++)
    {
        free(b[i]);
    }
    free(b);

    for (int i = 0; i < dim1; i++)
    {
        free(c[i]);
    }
    free(c);

    return 0;
}