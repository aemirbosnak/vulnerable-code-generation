//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

void main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of cells
    int **cells = (int**)malloc(10 * sizeof(int*));
    for (int i = 0; i < 10; i++)
    {
        cells[i] = (int*)malloc(10 * sizeof(int));
    }

    // Initialize the cells
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Percolation process
    for (int iter = 0; iter < 1000; iter++)
    {
        // Randomly select a cell
        int x = rand() % 10;
        int y = rand() % 10;

        // If the cell is not already wet and there is a chance of it becoming wet
        if (cells[x][y] == 0 && rand() % 20 == 0)
        {
            // Set the cell to wet
            cells[x][y] = 1;

            // Spread water to neighboring cells
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    // If the neighboring cell is not wet and it is within the bounds of the grid
                    if (cells[x + dx][y + dy] == 0 && dx >= 0 && dy >= 0)
                    {
                        cells[x + dx][y + dy] = 1;
                    }
                }
            }
        }
    }

    // Print the wet cells
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < 10; i++)
    {
        free(cells[i]);
    }
    free(cells);
}