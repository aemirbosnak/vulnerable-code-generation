//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define DELAY 100

int main()
{
    int **grid = NULL;
    int x, y, i, j, seed, water_pos, drop_pos;

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
            grid[x][y] = 0;
        }
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Place the initial water droplet
    water_pos = rand() % (WIDTH * HEIGHT);
    grid[water_pos / WIDTH][water_pos % WIDTH] = 1;

    // Simulate water percolation
    for (i = 0; i < DELAY; i++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                if (grid[x][y] == 1)
                {
                    // Check the four neighbors
                    if (grid[x - 1][y] == 0 && rand() % 2 == 0)
                        grid[x - 1][y] = 1;
                    if (grid[x + 1][y] == 0 && rand() % 2 == 0)
                        grid[x + 1][y] = 1;
                    if (grid[x][y - 1] == 0 && rand() % 2 == 0)
                        grid[x][y - 1] = 1;
                    if (grid[x][y + 1] == 0 && rand() % 2 == 0)
                        grid[x][y + 1] = 1;
                }
            }
        }
    }

    // Print the final grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}