//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 3;
    int b = 4;
    int c = 5;

    int **matrixA = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        matrixA[i] = (int *)malloc(b * sizeof(int));
    }

    int **matrixB = (int **)malloc(c * sizeof(int *));
    for (int i = 0; i < c; i++)
    {
        matrixB[i] = (int *)malloc(b * sizeof(int));
    }

    int **result = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        result[i] = (int *)malloc(b * sizeof(int));
    }

    // Matrix A
    matrixA[0][0] = 1;
    matrixA[0][1] = 2;
    matrixA[0][2] = 3;
    matrixA[1][0] = 4;
    matrixA[1][1] = 5;
    matrixA[1][2] = 6;

    // Matrix B
    matrixB[0][0] = 7;
    matrixB[0][1] = 8;
    matrixB[0][2] = 9;
    matrixB[1][0] = 10;
    matrixB[1][1] = 11;
    matrixB[1][2] = 12;

    // Multiplication Operation
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Print the Result
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free Memory
    for (int i = 0; i < a; i++)
    {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < c; i++)
    {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < a; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}