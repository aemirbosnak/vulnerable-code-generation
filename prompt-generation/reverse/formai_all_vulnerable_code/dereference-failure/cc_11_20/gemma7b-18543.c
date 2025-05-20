//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int rowsA = 3, colsA = 2, rowsB = 2, colsB = 4, rowsC = 4, colsC = 3;

    a = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++)
    {
        a[i] = (int *)malloc(colsA * sizeof(int));
    }

    b = (int **)malloc(rowsB * sizeof(int *));
    for (int i = 0; i < rowsB; i++)
    {
        b[i] = (int *)malloc(colsB * sizeof(int));
    }

    c = (int **)malloc(rowsC * sizeof(int *));
    for (int i = 0; i < rowsC; i++)
    {
        c[i] = (int *)malloc(colsC * sizeof(int));
    }

    // Initializing the matrices
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            a[i][j] = 2 * i - j;
        }
    }

    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            b[i][j] = 3 * i + j;
        }
    }

    // Performing the matrix multiplication
    for (int i = 0; i < rowsC; i++)
    {
        for (int j = 0; j < colsC; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < rowsA; k++)
            {
                for (int l = 0; l < colsB; l++)
                {
                    c[i][j] += a[k][l] * b[k][l];
                }
            }
        }
    }

    // Printing the result
    for (int i = 0; i < rowsC; i++)
    {
        for (int j = 0; j < colsC; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Freeing the memory
    for (int i = 0; i < rowsA; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < rowsB; i++)
    {
        free(b[i]);
    }
    free(b);

    for (int i = 0; i < rowsC; i++)
    {
        free(c[i]);
    }
    free(c);

    return 0;
}