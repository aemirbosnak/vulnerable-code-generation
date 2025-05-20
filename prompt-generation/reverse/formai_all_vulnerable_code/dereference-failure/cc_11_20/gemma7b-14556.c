//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, iteration = 0;
    srand(time(NULL));

    // Allocate memory for the grid
    grid = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    if (grid == NULL)
    {
        return -1;
    }

    // Initialize the grid
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    while (iteration < MAX_ITERATIONS)
    {
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == 0)
                {
                    // Randomly decide if the cell becomes wet
                    if (rand() % 2 == 0)
                    {
                        grid[i][j] = 1;
                    }
                }
            }
        }

        // Count the number of wet cells
        int num_wet_cells = 0;
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == 1)
                {
                    num_wet_cells++;
                }
            }
        }

        // Print the number of wet cells
        printf("Iteration %d: %d wet cells\n", iteration, num_wet_cells);

        iteration++;
    }

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}