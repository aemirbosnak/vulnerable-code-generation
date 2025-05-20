//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdlib.h>
#include <time.h>

#define DIM 10

int main()
{
    int **grid = NULL;
    int i, j, k, seed;

    // Allocate memory for the grid
    grid = malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolation simulation
    for (k = 0; k < 1000; k++)
    {
        // Randomly choose a cell
        i = rand() % DIM;
        j = rand() % DIM;

        // If the cell is not already saturated and the probability of saturation is high
        if (grid[i][j] == 0 && rand() % 2 == 0)
        {
            // Saturate the cell
            grid[i][j] = 1;

            // Check if the cell is a border cell
            if (i == 0 || j == 0 || i == DIM - 1 || j == DIM - 1)
            {
                // Saturate the border cells
                grid[i][j] = 2;
            }
        }
    }

    // Print the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}