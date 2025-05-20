//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    // Allocate memory for the grid
    int **grid = (int**)malloc(WIDTH * sizeof(int*));
    for(int i = 0; i < WIDTH; i++)
    {
        grid[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate the percolation process
    int num_iter = 0;
    while(num_iter < 100)
    {
        // Randomly choose a cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is not already wet and it has a neighbor to the north
        if(grid[x][y] == 0 && grid[x][y-1] == 1)
        {
            // Set the cell to wet
            grid[x][y] = 1;

            // Spread the water to the east and west
            if(grid[x+1][y] == 0) grid[x+1][y] = 1;
            if(grid[x-1][y] == 0) grid[x-1][y] = 1;
        }

        num_iter++;
    }

    // Print the grid
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}