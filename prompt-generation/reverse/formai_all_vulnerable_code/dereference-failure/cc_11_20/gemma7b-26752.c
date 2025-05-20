//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

#define WATER_LEVEL 5

int main()
{
    int **grid = (int **)malloc(ROWS * sizeof(int *));
    for(int r = 0; r < ROWS; r++)
    {
        grid[r] = (int *)malloc(COLS * sizeof(int));
    }

    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Place water in the center
    grid[WATER_LEVEL][WATER_LEVEL] = 1;

    // Simulate Percolation
    for(int t = 0; t < 1000; t++)
    {
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == 1)
                {
                    int dr = rand() % 4 - 1;
                    int dc = rand() % 4 - 1;

                    if(dr != 0 && grid[r + dr][c] == 0)
                    {
                        grid[r + dr][c] = 1;
                    }

                    if(dc != 0 && grid[r][c + dc] == 0)
                    {
                        grid[r][c + dc] = 1;
                    }
                }
            }
        }
    }

    // Print the grid
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for(int r = 0; r < ROWS; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}