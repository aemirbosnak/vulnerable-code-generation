//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: genius
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, iteration = 0;
    srand(time(NULL));

    // Allocate memory for the grid
    grid = (int **)malloc(WIDTH * sizeof(int *));
    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate percolations
    while (iteration < MAX_ITERATIONS)
    {
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the four neighbors
                    if (grid[i - 1][j] == 1)
                        grid[i - 1][j] = 2;
                    if (grid[i + 1][j] == 1)
                        grid[i + 1][j] = 2;
                    if (grid[i][j - 1] == 1)
                        grid[i][j - 1] = 2;
                    if (grid[i][j + 1] == 1)
                        grid[i][j + 1] = 2;
                }
            }
        }

        // Count the number of saturated cells
        int num_saturated = 0;
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == 2)
                    num_saturated++;
            }
        }

        // Increment the iteration if the number of saturated cells is greater than 50% of the total number of cells
        if ((double)num_saturated / (WIDTH * HEIGHT) * 100.0 > 50.0)
            iteration++;
    }

    // Free the memory
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            free(grid[i][j]);
        }
        free(grid[i]);
    }
    free(grid);

    return 0;
}