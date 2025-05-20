//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for(int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game of life board
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            cells[r][c] = rand() % 2;
        }
    }

    // Simulate the game of life
    for(int t = 0; t < 10; t++)
    {
        // Calculate the number of neighbors for each cell
        for(int r = 0; r < MAX_CELLS; r++)
        {
            for(int c = 0; c < MAX_CELLS; c++)
            {
                int neighbors = 0;
                if(cells[r-1][c] == 1) neighbors++;
                if(cells[r+1][c] == 1) neighbors++;
                if(cells[r][c-1] == 1) neighbors++;
                if(cells[r][c+1] == 1) neighbors++;

                // Apply the game of life rules
                if(cells[r][c] == 1 && neighbors < 2) cells[r][c] = 0;
                if(cells[r][c] == 0 && neighbors == 3) cells[r][c] = 1;
            }
        }
    }

    // Print the final game board
    for(int r = 0; r < MAX_CELLS; r++)
    {
        for(int c = 0; c < MAX_CELLS; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for(int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}