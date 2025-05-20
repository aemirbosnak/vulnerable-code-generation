//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y;
    int seed = time(NULL);
    srand(seed);

    // Allocate memory for the grid
    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (y = 0; y < HEIGHT; y++)
    {
        grid[y] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            grid[y][x] = rand() % 2;
        }
    }

    // Percolation
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            if (grid[y][x] == 1)
            {
                // Check if the cell is connected to the top
                if (grid[y - 1][x] == 1)
                {
                    grid[y][x] = 2;
                }

                // Check if the cell is connected to the left
                if (grid[y][x - 1] == 1)
                {
                    grid[y][x] = 2;
                }
            }
        }
    }

    // Print the grid
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("%d ", grid[y][x]);
        }
        printf("\n");
    }

    // Free memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(grid[y]);
    }
    free(grid);

    return 0;
}