//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENERATIONS 100
#define CELL_SIZE 20

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the game of life cells
    int **cells = (int **)malloc(CELL_SIZE * sizeof(int *));
    for (int i = 0; i < CELL_SIZE; i++)
    {
        cells[i] = (int *)malloc(CELL_SIZE * sizeof(int));
    }

    // Initialize the cells
    for (int i = 0; i < CELL_SIZE; i++)
    {
        for (int j = 0; j < CELL_SIZE; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life for a number of generations
    for (int generation = 0; generation < MAX_GENERATIONS; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < CELL_SIZE; i++)
        {
            for (int j = 0; j < CELL_SIZE; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                        {
                            continue;
                        }
                        if (cells[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Update the cell's state based on its number of neighbors
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

    // Print the final game of life
    for (int i = 0; i < CELL_SIZE; i++)
    {
        for (int j = 0; j < CELL_SIZE; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the cells
    for (int i = 0; i < CELL_SIZE; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}