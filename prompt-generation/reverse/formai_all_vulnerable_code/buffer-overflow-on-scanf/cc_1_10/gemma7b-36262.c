//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

int main()
{
    // Define a 2D array to store the game grid
    int grid[GRID_SIZE][GRID_SIZE] = {{0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 0, 0, 1}};

    // Print the game grid
    for (int r = 0; r < GRID_SIZE; r++)
    {
        for (int c = 0; c < GRID_SIZE; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Get the user's move
    int move_x, move_y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    // Check if the move is valid
    if (move_x < 0 || move_x >= GRID_SIZE || move_y < 0 || move_y >= GRID_SIZE)
    {
        printf("Invalid move.\n");
    }
    else
    {
        // Mark the move on the grid
        grid[move_x][move_y] = 2;

        // Print the updated game grid
        for (int r = 0; r < GRID_SIZE; r++)
        {
            for (int c = 0; c < GRID_SIZE; c++)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }

        // Check if the player has won
        if (grid[move_x][move_y] == 2)
        {
            printf("You won!\n");
        }
        else
        {
            printf("Continue playing.\n");
        }
    }

    return 0;
}