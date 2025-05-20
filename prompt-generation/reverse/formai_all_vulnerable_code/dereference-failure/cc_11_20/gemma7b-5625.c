//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    int x = 0, y = 0, direction = 1;
    while (grid[x][y] != -1)
    {
        switch (direction)
        {
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
            case 4:
                y--;
                break;
        }

        // Check if the cell is wet
        if (grid[x][y] == 1)
        {
            // Mark the cell as wet
            grid[x][y] = -1;

            // Simulate the flow of water
            switch (direction)
            {
                case 1:
                    grid[x][y] = 2;
                    break;
                case 2:
                    grid[x][y] = 2;
                    break;
                case 3:
                    grid[x][y] = 2;
                    break;
                case 4:
                    grid[x][y] = 2;
                    break;
            }
        }
    }

    // Print the results
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}