//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int seed = time(NULL);

    // Allocate memory for the grid
    grid = malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i] = malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    for (int i = 0; i < 1000; i++)
    {
        // Randomly choose a cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is not already wet and there is a chance of it becoming wet
        if (grid[x][y] == 0 && rand() % 5 == 0)
        {
            // Make the cell wet
            grid[x][y] = 1;

            // Spread water to neighboring cells
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    // If the neighboring cell is not wet and within the bounds of the grid
                    if (grid[x + dx][y + dy] == 0 && x + dx >= 0 && x + dx < WIDTH && y + dy >= 0 && y + dy < HEIGHT)
                    {
                        // Make the neighboring cell wet
                        grid[x + dx][y + dy] = 1;
                    }
                }
            }
        }
    }

    // Print the grid
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}