//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array of integers to store the grid of cells
    int **grid = NULL;
    int rows = 10;
    int cols = 10;
    grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid with random values
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Percolation algorithm
    int i = 0;
    int j = 0;
    while (i < rows && j < cols)
    {
        int current = grid[i][j];
        int neighbors = 0;
        // Check the four neighbors
        if (i > 0)
        {
            neighbors++;
            if (grid[i - 1][j] == current)
            {
                grid[i][j] = 2;
            }
        }
        if (j > 0)
        {
            neighbors++;
            if (grid[i][j - 1] == current)
            {
                grid[i][j] = 2;
            }
        }
        if (i < rows - 1)
        {
            neighbors++;
            if (grid[i + 1][j] == current)
            {
                grid[i][j] = 2;
            }
        }
        if (j < cols - 1)
        {
            neighbors++;
            if (grid[i][j + 1] == current)
            {
                grid[i][j] = 2;
            }
        }
        // If the current cell is wet and has no neighbors, it becomes dry
        if (current == 1 && neighbors == 0)
        {
            grid[i][j] = 0;
        }
        // Increment i and j to move to the next cell
        i++;
        j++;
    }

    // Print the final grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}