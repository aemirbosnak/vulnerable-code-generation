//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 4, b = 3, c = 2;
    int **matrixA = NULL, **matrixB = NULL, **result = NULL;

    // Allocate memory for matrices A and B
    matrixA = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++)
    {
        matrixA[i] = (int*)malloc(b * sizeof(int));
    }

    matrixB = (int**)malloc(b * sizeof(int*));
    for (int i = 0; i < b; i++)
    {
        matrixB[i] = (int*)malloc(c * sizeof(int));
    }

    // Initialize matrices A and B
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            matrixA[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrixB[i][j] = rand() % 10;
        }
    }

    // Calculate the product of matrices A and B
    result = (int**)malloc((a) * sizeof(int*));
    for (int i = 0; i < a; i++)
    {
        result[i] = (int*)malloc(c * sizeof(int));
    }

    for (int i = 0; i < a; i++)
    {
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
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < b; i++)
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