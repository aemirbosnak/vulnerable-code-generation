//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int x, y;

    grid = (int**)malloc(WIDTH * sizeof(int *));
    for(x = 0; x < WIDTH; x++)
    {
        grid[x] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Simulate Percolation
    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            if(grid[x][y] == 0)
            {
                // Check the neighbors
                int neighbors = 0;
                if(grid[x-1][y] == 1) neighbors++;
                if(grid[x+1][y] == 1) neighbors++;
                if(grid[x][y-1] == 1) neighbors++;
                if(grid[x][y+1] == 1) neighbors++;

                // If the number of neighbors is greater than a threshold,
                // the cell becomes wet
                if(neighbors > 3)
                {
                    grid[x][y] = 1;
                }
            }
        }
    }

    // Print the results
    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for(x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}