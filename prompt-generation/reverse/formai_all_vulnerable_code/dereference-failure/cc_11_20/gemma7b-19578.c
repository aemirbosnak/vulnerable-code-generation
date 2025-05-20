//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define the Matrix dimensions
    int rows = 3;
    int cols = 4;

    // Allocate memory for the Matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the Matrix with values
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            matrix[r][c] = rand() % 10;
        }
    }

    // Print the Matrix
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    // Transpose the Matrix
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++)
    {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    for (int r = 0; r < cols; r++)
    {
        for (int c = 0; c < rows; c++)
        {
            transpose[r][c] = matrix[c][r];
        }
    }

    // Print the Transpose Matrix
    for (int r = 0; r < cols; r++)
    {
        for (int c = 0; c < rows; c++)
        {
            printf("%d ", transpose[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the Matrix and Transpose Matrix
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++)
    {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}