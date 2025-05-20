//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **arr = NULL;
    int i, j, size, iterations = 0;

    printf("Enter the size of the grid (recommended: at least 10): ");
    scanf("%d", &size);

    // Allocate memory for the grid
    arr = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation simulation
    while (!arr[0][0] && iterations < MAX_SIZE)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (arr[i][j] == 1)
                {
                    // Check if the cell is not already saturated
                    if (arr[i - 1][j] == 1 || arr[i + 1][j] == 1 || arr[i][j - 1] == 1 || arr[i][j + 1] == 1)
                    {
                        arr[i][j] = 2;
                    }
                }
            }
        }

        // Mark saturated cells as open
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (arr[i][j] == 2)
                {
                    arr[i][j] = 1;
                }
            }
        }

        // Increment the number of iterations
        iterations++;
    }

    // Print the final grid
    printf("Final grid:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}