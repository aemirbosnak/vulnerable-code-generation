//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Create a 2D array to store the grid
    int **grid = NULL;
    int rows = 10;
    int cols = 10;
    grid = (int **)malloc(rows * sizeof(int *) + rows);
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int) + cols);
    }

    // Initialize the grid with random values
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Percolation simulation
    int iteration = 0;
    while (1)
    {
        int percolates = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                // Check if the cell is wet and if it has any wet neighbors
                if (grid[r][c] == 1 && (grid[r-1][c] == 1 || grid[r+1][c] == 1 || grid[r][c-1] == 1 || grid[r][c+1] == 1))
                {
                    // If the cell is not wet, make it wet
                    grid[r][c] = 1;
                    percolates++;
                }
            }
        }

        // If no cells percolated, break out of the loop
        if (percolates == 0)
        {
            break;
        }

        // Increment the iteration count
        iteration++;
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