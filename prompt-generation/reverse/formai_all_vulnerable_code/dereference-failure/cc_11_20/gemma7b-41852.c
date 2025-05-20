//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Randomly choose a number of cells to be wet
    int numWetCells = rand() % MAX_SIZE * MAX_SIZE;
    for (int i = 0; i < numWetCells; i++)
    {
        int x = rand() % MAX_SIZE;
        int y = rand() % MAX_SIZE;
        grid[x][y] = 1;
    }

    // Simulate the percolation
    int numDrops = 0;
    while (numWetCells > 0)
    {
        numWetCells = 0;
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                if (grid[i][j] == 1)
                {
                    numWetCells++;
                    grid[i][j] = 2;
                    if (i > 0 && grid[i - 1][j] == 0)
                    {
                        grid[i - 1][j] = 1;
                    }
                    if (j > 0 && grid[i][j - 1] == 0)
                    {
                        grid[i][j - 1] = 1;
                    }
                }
            }
        }
        numDrops++;
    }

    // Print the results
    printf("Number of drops: %d\n", numDrops);
    printf("Number of wet cells: %d\n", numWetCells);

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}