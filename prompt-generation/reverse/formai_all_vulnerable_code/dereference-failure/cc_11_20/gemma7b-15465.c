//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define MAX_ITERATIONS 1000

int main()
{
    // Create a 2D array to store the grid of cells
    int **grid = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid with random values
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate Percolation
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        // Iterate over the grid
        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < HEIGHT; j++)
            {
                // Check if the cell is wet and if it has any wet neighbors
                if (grid[i][j] == 1 && (grid[i-1][j] == 1 || grid[i+1][j] == 1 || grid[i][j-1] == 1 || grid[i][j+1] == 1))
                {
                    // If the cell is not already wet, make it wet
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}