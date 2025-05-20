//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int x, y;
    int seed = time(NULL);

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

    // Percolation
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (grid[x][y] == 0)
            {
                int r = rand() % 100;
                if (r < seed)
                {
                    grid[x][y] = 1;
                }
            }
        }
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