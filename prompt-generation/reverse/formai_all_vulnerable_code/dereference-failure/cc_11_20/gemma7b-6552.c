//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENERATIONS 100

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the game of life cells
    int **cells = (int **)malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++)
    {
        cells[i] = (int *)malloc(sizeof(int) * 10);
    }

    // Initialize the cells
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Randomly set some cells to 1 (alive)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (rand() % 2 == 0)
            {
                cells[i][j] = 1;
            }
        }
    }

    // Simulate multiple generations
    for (int generation = 0; generation < MAX_GENERATIONS; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                int neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (cells[i + r][j + c] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Update the cell's state based on the number of neighbors
                if (cells[i][j] == 1 && neighbors < 2)
                {
                    cells[i][j] = 0;
                }
                else if (cells[i][j] == 0 && neighbors == 3)
                {
                    cells[i][j] = 1;
                }
            }
        }
    }

    // Print the final state of the cells
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the cells
    for (int i = 0; i < 10; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}