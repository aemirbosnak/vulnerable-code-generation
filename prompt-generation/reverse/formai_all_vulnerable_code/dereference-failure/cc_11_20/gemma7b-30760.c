//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int iterations = 0;
    int seed = time(NULL);

    grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation
    while (!grid[size - 1][size - 1])
    {
        iterations++;
        seed = time(NULL) + iterations;
        srand(seed);

        // Randomly select a cell
        int x = rand() % size;
        int y = rand() % size;

        // If the cell is empty and its neighbors are wet, fill it
        if (grid[x][y] == 0 && (grid[x - 1][y] || grid[x + 1][y] || grid[x][y - 1] || grid[x][y + 1]))
        {
            grid[x][y] = 1;
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

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}