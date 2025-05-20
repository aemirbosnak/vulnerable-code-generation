//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the cells
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = rand() % 2;
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
                int num_neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (r == 0 && c == 0) continue;
                        if (cells[i + r][j + c] == 1) num_neighbors++;
                    }
                }
                cells[i][j] = (num_neighbors == 2) || (num_neighbors == 3) ? 1 : 0;
            }
        }

        // Update the cells
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                cells[i][j] = cells[i][j] * 2 - 1;
            }
        }
    }

    // Print the final cells
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