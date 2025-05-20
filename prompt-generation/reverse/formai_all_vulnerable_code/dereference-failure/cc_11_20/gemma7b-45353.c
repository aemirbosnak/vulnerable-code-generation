//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_GENERATIONS 10

int main()
{
    int **grid = NULL;
    int rows, cols;
    int generation = 0;

    // Allocate memory for the grid
    rows = 10;
    cols = 10;
    grid = (int **)malloc(rows * sizeof(int *) + rows);
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int) + cols);
    }

    // Initialize the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Set some initial cells to 1
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[6][5] = 1;
    grid[6][6] = 1;

    // Game of Life loop
    for (generation = 0; generation < MAX_GENERATIONS; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                // Check the four directions
                if (r > 0) neighbors++;
                if (r < rows - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < cols - 1) neighbors++;

                // Update the cell's state
                if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
                else if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            }
        }

        // Print the grid
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }
    }

    // Free memory
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            free(grid[r][c]);
        }
        free(grid[r]);
    }
    free(grid);

    return 0;
}