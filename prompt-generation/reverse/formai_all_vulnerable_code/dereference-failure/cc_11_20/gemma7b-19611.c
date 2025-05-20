//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y;

    // Allocate memory for the grid
    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for(x = 0; x < HEIGHT; x++)
    {
        grid[x] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for(x = 0; x < HEIGHT; x++)
    {
        for(y = 0; y < WIDTH; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Randomly fill some cells
    srand(time(NULL));
    for(x = 0; x < HEIGHT; x++)
    {
        for(y = 0; y < WIDTH; y++)
        {
            if(rand() % 10 == 0)
            {
                grid[x][y] = 1;
            }
        }
    }

    // Percolation algorithm
    for(x = 0; x < HEIGHT; x++)
    {
        for(y = 0; y < WIDTH; y++)
        {
            if(grid[x][y] == 1)
            {
                // Check the four neighbors
                if(grid[x-1][y] == 1)
                {
                    grid[x][y] = 2;
                }
                if(grid[x+1][y] == 1)
                {
                    grid[x][y] = 2;
                }
                if(grid[x][y-1] == 1)
                {
                    grid[x][y] = 2;
                }
                if(grid[x][y+1] == 1)
                {
                    grid[x][y] = 2;
                }
            }
        }
    }

    // Print the final grid
    for(x = 0; x < HEIGHT; x++)
    {
        for(y = 0; y < WIDTH; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for(x = 0; x < HEIGHT; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}