//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define MAX_ITERATIONS 1000

int main()
{
    // Allocate memory for the grid
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        grid[i] = malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        // Randomly choose a cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is empty and the neighborhood is full, fill the cell
        if (grid[y][x] == 0 &&
            (grid[y-1][x] || grid[y+1][x] || grid[y][x-1] || grid[y][x+1]))
        {
            grid[y][x] = 1;
        }
    }

    // Print the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}