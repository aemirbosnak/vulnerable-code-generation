//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int i, j, x, y;

    // Allocate memory for the grid
    grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    x = rand() % size;
    y = rand() % size;
    grid[x][y] = 1;

    // Iterate over the grid and check if the cell is connected to the boundary
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (grid[i][j] == 1)
            {
                // Check if the cell is connected to the top boundary
                if (i == 0)
                {
                    grid[i][j] = 2;
                }
                // Check if the cell is connected to the left boundary
                else if (j == 0)
                {
                    grid[i][j] = 2;
                }
                // Check if the cell is connected to the right boundary
                else if (j == size - 1)
                {
                    grid[i][j] = 2;
                }
                // Check if the cell is connected to the bottom boundary
                else if (i == size - 1)
                {
                    grid[i][j] = 2;
                }
            }
        }
    }

    // Print the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}