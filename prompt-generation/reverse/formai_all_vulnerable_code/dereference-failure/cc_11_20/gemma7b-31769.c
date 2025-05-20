//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int seed = time(NULL);

    // Allocate memory for the grid
    grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j] == 0)
            {
                // Randomly choose a neighbor
                int r = rand() % 4;
                switch (r)
                {
                    case 0:
                        if (grid[i - 1][j] == 1)
                            grid[i][j] = 1;
                        break;
                    case 1:
                        if (grid[i + 1][j] == 1)
                            grid[i][j] = 1;
                        break;
                    case 2:
                        if (grid[i][j - 1] == 1)
                            grid[i][j] = 1;
                        break;
                    case 3:
                        if (grid[i][j + 1] == 1)
                            grid[i][j] = 1;
                        break;
                }
            }
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