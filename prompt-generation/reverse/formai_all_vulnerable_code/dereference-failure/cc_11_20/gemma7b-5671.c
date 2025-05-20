//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int x, y, i, j, water_amount = 0;

    // Allocate memory for the grid
    grid = (int *)malloc(size * size * sizeof(int));
    if (grid == NULL)
    {
        return -1;
    }

    // Initialize the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Randomly fill some cells with water
    srand(time(NULL));
    for (i = 0; i < water_amount; i++)
    {
        x = rand() % size;
        y = rand() % size;
        grid[x][y] = 1;
    }

    // Simulate the percolation process
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (grid[i][j] == 1)
            {
                // Check the four neighbors of the current cell
                if (grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                }
                if (grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                }
                if (grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                }
                if (grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                }
            }
        }
    }

    // Print the final grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}