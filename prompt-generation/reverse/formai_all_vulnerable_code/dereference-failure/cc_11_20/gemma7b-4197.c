//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main()
{
    // Define a 2D array of doubles
    double **a = (double**)malloc(DIM * sizeof(double*));
    for (int i = 0; i < DIM; i++)
    {
        a[i] = (double*)malloc(DIM * sizeof(double));
    }

    // Initialize the matrix with random numbers
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    // Transpose the matrix
    double **b = (double**)malloc(DIM * sizeof(double*));
    for (int i = 0; i < DIM; i++)
    {
        b[i] = (double*)malloc(DIM * sizeof(double));
    }
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%f ", b[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < DIM; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < DIM; i++)
    {
        free(b[i]);
    }
    free(b);

    return 0;
}