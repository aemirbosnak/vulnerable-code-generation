//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

int main()
{
    int **cells = (int *)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the cells
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Simulate life
    for (int t = 0; t < 10; t++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int neighbors = 0;
                // Check the four neighboring cells
                if (cells[i - 1][j] == 1) neighbors++;
                if (cells[i + 1][j] == 1) neighbors++;
                if (cells[i][j - 1] == 1) neighbors++;
                if (cells[i][j + 1] == 1) neighbors++;

                // Update the cell's state
                if (cells[i][j] == 1 && neighbors < 2) cells[i][j] = 0;
                if (cells[i][j] == 0 && neighbors == 3) cells[i][j] = 1;
            }
        }

        // Print the cells
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                printf("%d ", cells[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            free(cells[i][j]);
        }
        free(cells[i]);
    }
    free(cells);

    return 0;
}