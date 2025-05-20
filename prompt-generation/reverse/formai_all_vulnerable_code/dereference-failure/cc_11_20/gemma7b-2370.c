//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            arr[r][c] = rand() % 10;
        }
    }

    // Transpose the matrix
    int **arr_t = (int **)malloc(COLS * sizeof(int *));
    for (int i = 0; i < COLS; i++)
    {
        arr_t[i] = (int *)malloc(ROWS * sizeof(int));
    }

    for (int r = 0; r < COLS; r++)
    {
        for (int c = 0; c < ROWS; c++)
        {
            arr_t[r][c] = arr[c][r];
        }
    }

    // Print the original and transposed matrices
    printf("Original matrix:\n");
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }

    printf("Transposed matrix:\n");
    for (int r = 0; r < COLS; r++)
    {
        for (int c = 0; c < ROWS; c++)
        {
            printf("%d ", arr_t[r][c]);
        }
        printf("\n");
    }

    free(arr);
    free(arr_t);

    return 0;
}