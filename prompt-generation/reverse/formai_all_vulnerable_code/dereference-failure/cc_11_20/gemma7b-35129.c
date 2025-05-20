//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 100

int main()
{
    // Create a 2D array to store the state of the percolating system
    int** grid = (int**)malloc(MAX_PERCOLATION_SIZE * sizeof(int*));
    for (int i = 0; i < MAX_PERCOLATION_SIZE; i++)
    {
        grid[i] = (int*)malloc(MAX_PERCOLATION_SIZE * sizeof(int));
    }

    // Initialize the grid with random values
    srand(time(NULL));
    for (int i = 0; i < MAX_PERCOLATION_SIZE; i++)
    {
        for (int j = 0; j < MAX_PERCOLATION_SIZE; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Percolation process
    for (int iter = 0; iter < MAX_PERCOLATION_SIZE; iter++)
    {
        for (int i = 0; i < MAX_PERCOLATION_SIZE; i++)
        {
            for (int j = 0; j < MAX_PERCOLATION_SIZE; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check if the neighboring cells are wet
                    int is_wet = 0;
                    if (i > 0 && grid[i - 1][j] == 1) is_wet++;
                    if (j > 0 && grid[i][j - 1] == 1) is_wet++;
                    if (i < MAX_PERCOLATION_SIZE - 1 && grid[i + 1][j] == 1) is_wet++;
                    if (j < MAX_PERCOLATION_SIZE - 1 && grid[i][j + 1] == 1) is_wet++;

                    // If all neighboring cells are wet, the current cell becomes wet
                    if (is_wet == 4)
                    {
                        grid[i][j] = 2;
                    }
                }
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < MAX_PERCOLATION_SIZE; i++)
    {
        for (int j = 0; j < MAX_PERCOLATION_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < MAX_PERCOLATION_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}