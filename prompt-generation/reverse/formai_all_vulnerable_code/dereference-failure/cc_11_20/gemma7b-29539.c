//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Percolation Simulation
int main()
{
    int **arr = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = (int *)malloc(SIZE * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Randomly set some sites to 1
    for (int i = 0; i < 10; i++)
    {
        arr[rand() % SIZE][rand() % SIZE] = 1;
    }

    // Perform Percolation
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (arr[i][j] == 1)
            {
                // Check the four neighbors
                if (arr[i - 1][j] == 1)
                {
                    arr[i - 1][j] = 1;
                }
                if (arr[i + 1][j] == 1)
                {
                    arr[i + 1][j] = 1;
                }
                if (arr[i][j - 1] == 1)
                {
                    arr[i][j - 1] = 1;
                }
                if (arr[i][j + 1] == 1)
                {
                    arr[i][j + 1] = 1;
                }
            }
        }
    }

    // Print the final array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < SIZE; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}