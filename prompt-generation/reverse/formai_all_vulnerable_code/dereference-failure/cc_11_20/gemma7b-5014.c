//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y, water_level = 0;

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
            grid[y][x] = 0;
        }
    }

    // Plant water seeds
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        grid[y][x] = 1;
    }

    // Spread the water
    while (water_level < 10)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            for (x = 0; x < WIDTH; x++)
            {
                if (grid[y][x] == 1)
                {
                    // Check the four neighbors
                    if (grid[y-1][x] == 0 && rand() % 2 == 0)
                        grid[y-1][x] = 1;
                    if (grid[y+1][x] == 0 && rand() % 2 == 0)
                        grid[y+1][x] = 1;
                    if (grid[y][x-1] == 0 && rand() % 2 == 0)
                        grid[y][x-1] = 1;
                    if (grid[y][x+1] == 0 && rand() % 2 == 0)
                        grid[y][x+1] = 1;
                }
            }
        }

        water_level++;
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

    // Free the memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(grid[y]);
    }
    free(grid);

    return 0;
}