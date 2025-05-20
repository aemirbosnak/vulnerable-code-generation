//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define FILLED 1

int main()
{
    int **grid = NULL;
    int seed = time(NULL);
    int x, y;

    // Allocate memory for the grid
    grid = malloc(WIDTH * sizeof(int *));
    for (x = 0; x < WIDTH; x++)
    {
        grid[x] = malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = EMPTY;
        }
    }

    // Randomly fill some cells
    srand(seed);
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (rand() % 10 == 0)
            {
                grid[x][y] = FILLED;
            }
        }
    }

    // Percolation simulation
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (grid[x][y] == FILLED)
            {
                // Check the four neighbors
                if (grid[x-1][y] == FILLED)
                {
                    grid[x][y] = FILLED;
                }
                if (grid[x+1][y] == FILLED)
                {
                    grid[x][y] = FILLED;
                }
                if (grid[x][y-1] == FILLED)
                {
                    grid[x][y] = FILLED;
                }
                if (grid[x][y+1] == FILLED)
                {
                    grid[x][y] = FILLED;
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

    // Free the memory
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}