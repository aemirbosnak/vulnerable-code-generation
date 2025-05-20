//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = (int **)malloc(WIDTH * sizeof(int *));
    for(int i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Percolation
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            if(grid[i][j] == 0)
            {
                int r = rand() % 2;
                if(r == 0)
                {
                    grid[i][j] = 1;
                }
            }
        }
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