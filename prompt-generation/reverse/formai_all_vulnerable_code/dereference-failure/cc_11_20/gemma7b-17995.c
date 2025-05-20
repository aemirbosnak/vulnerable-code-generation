//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int i, j, k, l, m, n;

    // The Matrix A is 2x2
    a = (int **)malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++)
    {
        a[i] = (int *)malloc(2 * sizeof(int));
    }

    // The Matrix B is 2x3
    b = (int **)malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++)
    {
        b[i] = (int *)malloc(3 * sizeof(int));
    }

    // The Matrix C will be 2x3
    c = (int **)malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++)
    {
        c[i] = (int *)malloc(3 * sizeof(int));
    }

    // Filling the matrices
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    b[0][0] = 5;
    b[0][1] = 6;
    b[0][2] = 7;
    b[1][0] = 8;
    b[1][1] = 9;
    b[1][2] = 10;

    // Performing the Matrix Multiplication
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                for (l = 0; l < 2; l++)
                {
                    c[i][j] += a[k][l] * b[k][l];
                }
            }
        }
    }

    // Printing the Result
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Freeing the memory
    for (i = 0; i < 2; i++)
    {
        free(a[i]);
    }
    free(a);

    for (i = 0; i < 2; i++)
    {
        free(b[i]);
    }
    free(b);

    for (i = 0; i < 2; i++)
    {
        free(c[i]);
    }
    free(c);

    return 0;
}