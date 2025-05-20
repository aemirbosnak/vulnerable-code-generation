//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_ITERATIONS 1000

int main()
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Randomly fill the grid
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Percolation algorithm
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the four neighbors
                    if (grid[i - 1][j] == 1)
                    {
                        grid[i][j] = 2;
                    }
                    if (grid[i + 1][j] == 1)
                    {
                        grid[i][j] = 2;
                    }
                    if (grid[i][j - 1] == 1)
                    {
                        grid[i][j] = 2;
                    }
                    if (grid[i][j + 1] == 1)
                    {
                        grid[i][j] = 2;
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

    // Free the memory
    for (int i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}