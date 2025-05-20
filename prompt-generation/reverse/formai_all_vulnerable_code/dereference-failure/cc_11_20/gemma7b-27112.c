//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the matrix
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            arr[r][c] = rand() % 10;
        }
    }

    // Print the original matrix
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }

    // Transpose the matrix
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            int tmp = arr[r][c];
            arr[r][c] = arr[c][r];
            arr[c][r] = tmp;
        }
    }

    // Print the transposed matrix
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}