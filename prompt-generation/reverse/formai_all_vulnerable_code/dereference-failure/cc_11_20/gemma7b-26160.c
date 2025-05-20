//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;

    // Allocate memory for the grid
    grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    int num_percolation = 0;
    while (num_percolation < MAX_SIZE * MAX_SIZE)
    {
        // Randomly select two cells
        int x1 = rand() % size;
        int y1 = rand() % size;
        int x2 = rand() % size;
        int y2 = rand() % size;

        // If both cells are empty and not adjacent, fill them
        if (grid[x1][y1] == 0 && grid[x2][y2] == 0 && (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == 0)
        {
            grid[x1][y1] = grid[x2][y2] = 1;
            num_percolation++;
        }
    }

    // Print the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}