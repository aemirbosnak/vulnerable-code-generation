//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the game of life board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Set some initial cells to 1 (alive)
    cells[2][2] = 1;
    cells[3][2] = 1;
    cells[4][2] = 1;
    cells[5][2] = 1;
    cells[5][3] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
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

                // Apply the Game of Life rules
                if (cells[i][j] == 1)
                {
                    if (num_neighbors < 2)
                    {
                        cells[i][j] = 0;
                    }
                    else if (num_neighbors > 3)
                    {
                        cells[i][j] = 0;
                    }
                }
                else if (num_neighbors == 3)
                {
                    cells[i][j] = 1;
                }
            }
        }

        // Increment the generation number
        generation++;

        // Print the game board
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                printf("%d ", cells[i][j]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (generation > 10)
        {
            break;
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}