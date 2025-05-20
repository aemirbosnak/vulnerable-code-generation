//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    // Define the grid size
    int x_size = 50;
    int y_size = 50;

    // Allocate the grid
    int **grid = (int**)malloc(x_size * sizeof(int*));
    for (int i = 0; i < x_size; i++)
    {
        grid[i] = (int*)malloc(y_size * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate the percolation
    int num_steps = 1000;
    for (int step = 0; step < num_steps; step++)
    {
        // Randomly select two cells
        int x1 = rand() % x_size;
        int y1 = rand() % y_size;
        int x2 = rand() % x_size;
        int y2 = rand() % y_size;

        // If both cells are not occupied and they are adjacent, then occupy them
        if (grid[x1][y1] == 0 && grid[x2][y2] == 0 && abs(x1 - x2) + abs(y1 - y2) <= 1)
        {
            grid[x1][y1] = grid[x2][y2] = 1;
        }
    }

    // Print the grid
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < x_size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}