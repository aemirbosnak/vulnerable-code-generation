//Gemma-7B DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seed = 12;
    srand(seed);

    // Create a 5x5 grid of flowers
    int grid[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Print the grid
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Simulate the wind blowing
    int direction = rand() % 4; // North, South, East, West
    int distance = rand() % 3; // Short, Medium, Long

    // Move the flowers
    switch (direction)
    {
        case 0: // North
            for (int r = 0; r < distance; r++)
            {
                for (int c = 0; c < 5; c++)
                {
                    if (grid[r][c] == 1)
                    {
                        grid[r][c] = 0;
                        grid[r-1][c] = 1;
                    }
                }
            }
            break;
        case 1: // South
            for (int r = 4; r >= 0; r--)
            {
                for (int c = 0; c < 5; c++)
                {
                    if (grid[r][c] == 1)
                    {
                        grid[r][c] = 0;
                        grid[r+1][c] = 1;
                    }
                }
            }
            break;
        case 2: // East
            for (int c = 0; c < 5; c++)
            {
                for (int r = 0; r < 5; r++)
                {
                    if (grid[r][c] == 1)
                    {
                        grid[r][c] = 0;
                        grid[r][c+1] = 1;
                    }
                }
            }
            break;
        case 3: // West
            for (int c = 4; c >= 0; c--)
            {
                for (int r = 0; r < 5; r++)
                {
                    if (grid[r][c] == 1)
                    {
                        grid[r][c] = 0;
                        grid[r][c-1] = 1;
                    }
                }
            }
            break;
    }

    // Print the updated grid
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    return 0;
}