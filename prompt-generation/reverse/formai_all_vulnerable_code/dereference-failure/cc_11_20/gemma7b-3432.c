//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

#define ALIVE 1
#define DEAD 0

int main()
{
    int **cells = (int**)malloc(MAX_CELLS * sizeof(int*));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int*)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = DEAD;
        }
    }

    // Set some cells to ALIVE
    cells[5][5] = ALIVE;
    cells[5][6] = ALIVE;
    cells[6][5] = ALIVE;

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int num_neighbors = 0;
                if (cells[i-1][j] == ALIVE) num_neighbors++;
                if (cells[i+1][j] == ALIVE) num_neighbors++;
                if (cells[i][j-1] == ALIVE) num_neighbors++;
                if (cells[i][j+1] == ALIVE) num_neighbors++;

                // Apply the rules of life
                if (cells[i][j] == ALIVE && num_neighbors < 2) cells[i][j] = DEAD;
                if (cells[i][j] == DEAD && num_neighbors == 3) cells[i][j] = ALIVE;
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