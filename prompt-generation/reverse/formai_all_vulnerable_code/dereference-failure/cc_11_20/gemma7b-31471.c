//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y;
    int seed = time(NULL);
    int iterations = 0;

    // Allocate memory for the grid
    grid = (int**)malloc(WIDTH * sizeof(int*));
    for (x = 0; x < WIDTH; x++)
    {
        grid[x] = (int*)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Percolation simulation
    while (!grid[WIDTH - 1][HEIGHT - 1] && iterations < 1000)
    {
        // Generate a random number between 0 and 1
        int rand_num = rand() % 2;

        // If the cell is empty and the random number is 0, fill it
        if (grid[x][y] == 0 && rand_num == 0)
        {
            grid[x][y] = 1;
        }

        // Increment the number of iterations
        iterations++;
    }

    // Print the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}