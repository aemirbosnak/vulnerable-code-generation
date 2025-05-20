//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Create a matrix with random values
    int rows = 3, cols = 4;
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 10;

    // Print the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Transpose the matrix
    int* transpose = (int*)malloc(cols * rows * sizeof(int));
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            transpose[i + j * cols] = matrix[j][i];
        }
    }

    // Multiply the matrix by 2
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[i][j] *= 2;
        }
    }

    // Print the matrix after multiplication
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(transpose);

    return 0;
}