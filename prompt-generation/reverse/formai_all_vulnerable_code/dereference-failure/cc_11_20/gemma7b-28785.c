//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, iteration = 0;
    srand(time(NULL));

    // Allocate memory for the grid
    grid = (int**)malloc(WIDTH * sizeof(int*));
    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    while (iteration < MAX_ITERATIONS)
    {
        // Randomly select a cell
        i = rand() % WIDTH;
        j = rand() % HEIGHT;

        // If the cell is not already saturated and has a neighbor to the right or below
        if (grid[i][j] == 0 && (grid[i + 1][j] || grid[i][j + 1]))
        {
            // Saturate the cell
            grid[i][j] = 1;
        }

        iteration++;
    }

    // Print the grid
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}