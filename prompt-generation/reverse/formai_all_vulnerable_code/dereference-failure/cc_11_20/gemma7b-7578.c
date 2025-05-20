//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 10

int main()
{
    int **cells = (int**)malloc(MAX_CELLS * sizeof(int*));
    for(int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int*)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the game of life board
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            cells[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of living cells
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            cells[r][c] = rand() % 2;
        }
    }

    // Run the game of life for 10 generations
    for(int gen = 0; gen < 10; gen++)
    {
        // Calculate the number of living neighbors for each cell
        for(int r = 0; r < MAX_CELLS; r++)
        {
            for(int c = 0; c < MAX_CELLS; c++)
            {
                int num_neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(cells[r + dr][c + dc] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                // Apply the game of life rules
                if(cells[r][c] == 1 && num_neighbors < 2)
                {
                    cells[r][c] = 0;
                }
                else if(cells[r][c] == 0 && num_neighbors == 3)
                {
                    cells[r][c] = 1;
                }
            }
        }
    }

    // Print the final board
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game of life board
    for(int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}