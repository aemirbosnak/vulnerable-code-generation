//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

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

    // Create some random cells
    for (int i = 0; i < 10; i++)
    {
        cells[rand() % MAX_CELLS][rand() % MAX_CELLS] = 1;
    }

    // Simulate the game of life
    for (int t = 0; t < 100; t++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0) continue;
                        if (cells[i + x][j + y] == 1) neighbors++;
                    }
                }
                cells[i][j] = (neighbors == 2) || (neighbors == 3);
            }
        }

        // Print the game board
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                printf("%d ", cells[i][j]);
            }
            printf("\n");
        }

        // Pause the game
        system("pause");
    }

    // Free the memory
    for (int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}