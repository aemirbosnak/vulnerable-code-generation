//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int **percolation = NULL;
    int i, j, k, size, iterations = 0;

    // Allocate memory for the grid and percolation array
    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    percolation = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        percolation[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid and percolation array
    size = MAX_SIZE;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
            percolation[i][j] = 0;
        }
    }

    // Simulate perculation
    while (!percolation[size - 1][size - 1])
    {
        iterations++;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (grid[i][j] == 1)
                {
                    k = i - 1;
                    while (k >= 0 && grid[k][j] == 0)
                    {
                        grid[k][j] = 1;
                        percolation[k][j] = 1;
                        k--;
                    }

                    k = i + 1;
                    while (k < size && grid[k][j] == 0)
                    {
                        grid[k][j] = 1;
                        percolation[k][j] = 1;
                        k++;
                    }

                    k = j - 1;
                    while (k >= 0 && grid[i][k] == 0)
                    {
                        grid[i][k] = 1;
                        percolation[i][k] = 1;
                        k--;
                    }

                    k = j + 1;
                    while (k < size && grid[i][k] == 0)
                    {
                        grid[i][k] = 1;
                        percolation[i][k] = 1;
                        k++;
                    }
                }
            }
        }
    }

    // Print the results
    printf("Number of iterations: %d\n", iterations);
    printf("Percolation status:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", percolation[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
        free(percolation[i]);
    }
    free(grid);
    free(percolation);

    return 0;
}