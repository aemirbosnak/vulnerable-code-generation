//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_GENERATIONS 1000

int main()
{
    // Initialize a 2D array to store the state of the grid
    int **grid = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int i = 0; i < WIDTH * HEIGHT; i++)
    {
        grid[i] = 0;
    }

    // Generate the initial state of the grid randomly
    srand(time(NULL));
    for (int i = 0; i < WIDTH * HEIGHT; i++)
    {
        grid[i] = rand() % 2;
    }

    // Simulate the Percolation process for a number of generations
    for (int generation = 0; generation < MAX_GENERATIONS; generation++)
    {
        // Iterate over the grid and check if the current cell is a sink
        for (int x = 0; x < WIDTH; x++)
        {
            for (int y = 0; y < HEIGHT; y++)
            {
                if (grid[x][y] == 0)
                {
                    // Check if the four neighbors are all saturated
                    int is_saturated = 1;
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (grid[x + dx][y + dy] == 0)
                            {
                                is_saturated = 0;
                            }
                        }
                    }

                    // If the cell is saturated, set it to 1
                    if (is_saturated)
                    {
                        grid[x][y] = 1;
                    }
                }
            }
        }
    }

    // Print the final state of the grid
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}