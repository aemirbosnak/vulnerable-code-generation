//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define DIM 50

int main()
{
    int **arr = (int **)malloc(DIM * sizeof(int *));
    for (int i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the array with random numbers
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    // Percolation algorithm
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (arr[i][j] == 1)
            {
                // Check the four neighbors
                if (arr[i - 1][j] == 1)
                {
                    arr[i][j] = 2;
                }
                if (arr[i + 1][j] == 1)
                {
                    arr[i][j] = 2;
                }
                if (arr[i][j - 1] == 1)
                {
                    arr[i][j] = 2;
                }
                if (arr[i][j + 1] == 1)
                {
                    arr[i][j] = 2;
                }
            }
        }
    }

    // Print the final array
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < DIM; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}