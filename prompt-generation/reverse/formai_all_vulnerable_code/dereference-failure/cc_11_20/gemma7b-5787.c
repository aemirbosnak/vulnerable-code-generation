//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int w, h, n, t, i, j, k;
    scanf("Enter the dimensions of the grid (w,h): ", &w, &h);
    scanf("Enter the number of iterations: ", &t);

    // Allocate memory for the grid
    int **grid = (int **)malloc(h * sizeof(int *));
    for (i = 0; i < h; i++)
    {
        grid[i] = (int *)malloc(w * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate the percolation
    for (k = 0; k < t; k++)
    {
        // Randomly choose a cell
        i = rand() % h;
        j = rand() % w;

        // If the cell is not already saturated and there is a chance of saturation
        if (grid[i][j] == 0 && rand() % 10 == 0)
        {
            // Saturate the cell
            grid[i][j] = 1;

            // Check if the cell is a corner cell
            if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
            {
                // Mark the cell as a boundary cell
                grid[i][j] = 2;
            }
        }
    }

    // Print the grid
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < h; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}