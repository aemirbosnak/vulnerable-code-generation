//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for the grid
    int **grid = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        grid[i] = malloc(5 * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Place the heart in a random position
    grid[rand() % 5][rand() % 5] = 1;

    // Game loop
    while (!grid[0][0] && grid[4][4] != 1)
    {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Validate the move
        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is valid
        if (grid[x][y] == 1)
        {
            printf("You already occupied that position.\n");
            continue;
        }

        // Make the move
        grid[x][y] = 1;

        // Check if the player has won
        if (grid[0][0] == 1 || grid[4][4] == 1)
        {
            printf("You won!\n");
            break;
        }
    }

    // Free the memory
    for (int i = 0; i < 5; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}