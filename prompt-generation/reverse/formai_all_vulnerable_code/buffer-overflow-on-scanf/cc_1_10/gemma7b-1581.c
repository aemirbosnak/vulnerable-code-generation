//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CELLS 20

// Define the Game of Life rules
void game_of_life(int **cells, int x, int y)
{
    int i, j, k, l, alive_neighbors = 0;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            // Check the number of alive neighbors
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (cells[i + k][j + l] == 1 && cells[i][j] != -1)
                    {
                        alive_neighbors++;
                    }
                }
            }

            // Apply the rules of life
            if (cells[i][j] == -1 && alive_neighbors >= 3)
            {
                cells[i][j] = 1;
            }
            else if (cells[i][j] == 1 && alive_neighbors < 2)
            {
                cells[i][j] = -1;
            }

            alive_neighbors = 0;
        }
    }
}

int main()
{
    int x, y, t, **cells;

    printf("Enter the dimensions of the grid (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the number of iterations: ");
    scanf("%d", &t);

    cells = (int **)malloc(x * sizeof(int *) + y * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        cells[i] = (int *)malloc(y * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cells[i][j] = -1;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create the initial pattern
    cells[5][5] = 1;
    cells[5][6] = 1;
    cells[6][5] = 1;
    cells[6][6] = 1;

    // Simulate the game of life
    for (int i = 0; i < t; i++)
    {
        game_of_life(cells, x, y);
    }

    // Print the final pattern
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    return 0;
}