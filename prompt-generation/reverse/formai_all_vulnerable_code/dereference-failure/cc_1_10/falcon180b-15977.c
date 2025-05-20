//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 1000
#define NUM_COLS 1000

int main()
{
    int i, j;
    int **matrix;
    int sum = 0;

    // Allocate memory for the matrix
    matrix = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (i = 0; i < NUM_ROWS; i++)
    {
        matrix[i] = (int *)malloc(NUM_COLS * sizeof(int));
    }

    // Initialize the matrix with random values
    srand(time(NULL));
    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLS; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    // Compute the sum of all elements in the matrix
    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLS; j++)
        {
            sum += matrix[i][j];
        }
    }

    printf("The sum of all elements in the matrix is %d\n", sum);

    // Free the memory allocated for the matrix
    for (i = 0; i < NUM_ROWS; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}