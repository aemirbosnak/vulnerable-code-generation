//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

#define MAX_ITERATIONS 1000

int main()
{
    // Create a 2D array of integers to store the state of the percolating grid
    int **grid = NULL;
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the grid
    grid = malloc(rows * sizeof(int *) + cols * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = malloc(cols * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Simulate percolations
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        // For each cell in the grid
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                // If the cell is not already wet and it has at least one wet neighbor
                if (grid[r][c] == 0 && (grid[r-1][c] == 1 || grid[r][c-1] == 1 || grid[r+1][c] == 1 || grid[r][c+1] == 1))
                {
                    // Make the cell wet
                    grid[r][c] = 1;
                }
            }
        }
    }

    // Print the final state of the grid
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