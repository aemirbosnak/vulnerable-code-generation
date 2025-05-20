//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int seed = time(NULL);

    // Allocate memory for the grid
    grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    for (int iter = 0; iter < 1000; iter++)
    {
        // Randomly select a cell
        int x = rand() % size;
        int y = rand() % size;

        // If the cell is not already saturated and there is a chance of saturation
        if (grid[x][y] == 0 && rand() % 2 == 0)
        {
            // Saturate the cell
            grid[x][y] = 1;

            // Spread water to neighboring cells
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    // Check if the neighboring cell is within the bounds of the grid and if it is not already saturated
                    if (x + dx >= 0 && x + dx < size && y + dy >= 0 && y + dy < size && grid[x + dx][y + dy] == 0)
                    {
                        // Saturate the neighboring cell
                        grid[x + dx][y + dy] = 1;
                    }
                }
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}