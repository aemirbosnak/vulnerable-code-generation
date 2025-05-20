//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 10

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    int seed = time(NULL);
    srand(seed);

    // Initialize the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Calculate the next generation
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int num_alive = 0;
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
                            num_alive++;
                        }
                    }
                }
                cells[i][j] = (num_alive == 2) || (num_alive == 3);
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

        // Increment the generation counter
        generation++;

        // Check if the game is over
        if (generation == 10)
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