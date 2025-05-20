//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 20

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of alive cells
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Play the game of life
    for (int t = 0; t < 10; t++)
    {
        // Calculate the number of alive neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int num_alive_neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                            continue;
                        if (cells[i + x][j + y] == 1)
                            num_alive_neighbors++;
                    }
                }
                cells[i][j] = (num_alive_neighbors == 2) || (num_alive_neighbors == 3);
            }
        }

        // Update the game board
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                cells[i][j] = cells[i][j] * 2 - 1;
            }
        }
    }

    // Print the final game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}