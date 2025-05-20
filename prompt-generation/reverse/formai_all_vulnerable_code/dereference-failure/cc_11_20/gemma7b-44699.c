//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 5, b = 10, c = 20, d = 30;
    int **matrixA = NULL, **matrixB = NULL, **matrixC = NULL;

    // Allocate memory for matrices
    matrixA = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        matrixA[i] = (int *)malloc(b * sizeof(int));
    }

    matrixB = (int **)malloc(c * sizeof(int *));
    for (int i = 0; i < c; i++)
    {
        matrixB[i] = (int *)malloc(d * sizeof(int));
    }

    matrixC = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        matrixC[i] = (int *)malloc(b * sizeof(int));
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
            matrixB[i][j] = i * j;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < d; k++)
            {
                int sum = 0;
                for (int l = 0; l < c; l++)
                {
                    sum += matrixA[i][l] * matrixB[l][k];
                }
                matrixC[i][j] = sum;
            }
        }
    }

    // Print the result
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    // Free memory
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
        free(matrixC[i]);
    }
    free(matrixC);

    return 0;
}