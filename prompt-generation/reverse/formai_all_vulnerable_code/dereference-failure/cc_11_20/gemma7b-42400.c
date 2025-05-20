//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int x, y, seed, percolate = 0;

    // Allocate memory for the grid
    grid = malloc(HEIGHT * sizeof(int *));
    for (y = 0; y < HEIGHT; y++)
    {
        grid[y] = malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            grid[y][x] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolation
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            if (grid[y][x] == 0)
            {
                percolate = rand() % 2;
                if (percolate == 0)
                {
                    grid[y][x] = 1;
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