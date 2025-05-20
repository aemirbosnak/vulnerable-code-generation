//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of cells
    int **cells = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        cells[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the cells
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Simulate life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the next generation of cells
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int num_neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (cells[i + r][j + c] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                cells[i][j] = (num_neighbors == 2 || num_neighbors == 3) ? 1 : 0;
            }
        }
    }

    // Print the final generation of cells
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the cells
    for (int i = 0; i < 5; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}