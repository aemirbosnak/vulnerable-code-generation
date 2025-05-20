//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define FULL 1

int main()
{
    int **grid = NULL;
    int seed = time(NULL);
    int x, y;

    // Allocate memory for the grid
    grid = (int **)malloc(WIDTH * sizeof(int *));
    for (x = 0; x < WIDTH; x++)
    {
        grid[x] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = EMPTY;
        }
    }

    // Percolation simulation
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (grid[x][y] == EMPTY)
            {
                // Randomly fill the cell
                if (rand() % 2 == 0)
                {
                    grid[x][y] = FULL;
                }
            }
        }
    }

    // Print the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free memory
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}