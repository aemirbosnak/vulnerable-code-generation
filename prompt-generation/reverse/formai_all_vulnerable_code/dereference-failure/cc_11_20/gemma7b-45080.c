//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main()
{
    int **grid;
    int rows, cols, iterations;
    int seed;

    // Allocate memory for the grid
    rows = 20;
    cols = 20;
    grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Set the seed for the random number generator
    seed = time(NULL);
    srand(seed);

    // Simulate percolations
    iterations = 0;
    while (iterations < MAX_ITERATIONS)
    {
        // Randomly choose a cell
        int r = rand() % rows;
        int c = rand() % cols;

        // If the cell is not already wet and the neighboring cells are wet,
        // then make the cell wet
        if (grid[r][c] == 0 && (grid[r-1][c] || grid[r+1][c] || grid[r][c-1] || grid[r][c+1]))
        {
            grid[r][c] = 1;
            iterations++;
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

    // Free the memory allocated for the grid
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}