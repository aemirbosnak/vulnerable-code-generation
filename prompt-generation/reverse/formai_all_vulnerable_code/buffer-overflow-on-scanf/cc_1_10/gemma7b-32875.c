//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 5x5 grid of numbers
    int grid[5][5] = {{0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0}};

    // Place the treasure in a random location
    grid[rand() % 5][rand() % 5] = 10;

    // Print the grid
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Get the player's move
    int x, y;
    printf("Enter the coordinates of the treasure: ");
    scanf("%d %d", &x, &y);

    // Check if the player's move is valid
    if (x < 0 || x >= 5 || y < 0 || y >= 5)
    {
        printf("Invalid move.\n");
    }
    else
    {
        // Check if the player has found the treasure
        if (grid[x][y] == 10)
        {
            printf("You have found the treasure!\n");
        }
        else
        {
            printf("The treasure is not there.\n");
        }
    }

    return 0;
}