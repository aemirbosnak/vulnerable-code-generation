//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 3, c = 2, d = 4;
    int **matrixA = NULL, **matrixB = NULL, **result = NULL;

    // Allocate memory for matrices
    matrixA = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++)
    {
        matrixA[i] = (int*)malloc(b * sizeof(int));
    }

    matrixB = (int**)malloc(c * sizeof(int*));
    for (int i = 0; i < c; i++)
    {
        matrixB[i] = (int*)malloc(d * sizeof(int));
    }

    // Populate matrices
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            matrixA[i][j] = i + j;
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            matrixB[i][j] = i - j;
        }
    }

    // Perform matrix multiplication
    result = (int**)malloc((a * c) * sizeof(int*));
    for (int i = 0; i < a; i++)
    {
        result[i] = (int*)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < b; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Print the result
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            free(matrixA[i][j]);
        }
        free(matrixA[i]);
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            free(matrixB[i][j]);
        }
        free(matrixB[i]);
    }

    for (int i = 0; i < a * c; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}