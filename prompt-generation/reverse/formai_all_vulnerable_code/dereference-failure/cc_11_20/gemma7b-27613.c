//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game of life cells
    int **cells = (int **)malloc(5 * sizeof(int *));
    for(int i = 0; i < 5; i++)
    {
        cells[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the cells with random values
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life for 10 generations
    for(int generation = 0; generation < 10; generation++)
    {
        // Calculate the number of neighbors for each cell
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                int neighbors = 0;
                if(i > 0) neighbors++;
                if(i < 4) neighbors++;
                if(j > 0) neighbors++;
                if(j < 4) neighbors++;

                // Apply the game of life rules
                if(cells[i][j] == 1 && neighbors < 2) cells[i][j] = 0;
                if(cells[i][j] == 0 && neighbors == 3) cells[i][j] = 1;
            }
        }
    }

    // Print the final game board
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for(int i = 0; i < 5; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}