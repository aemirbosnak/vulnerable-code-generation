//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_GENERATIONS 100

int main()
{
    int generation = 0;
    int **grid = NULL;
    int rows, cols;

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

    // Game of Life rules
    while (generation < MAX_GENERATIONS)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < rows - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < cols - 1) neighbors++;

                // Update the cell's state based on the number of neighbors
                if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
                if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            }
        }

        // Increment the generation
        generation++;
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

    // Free the memory
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