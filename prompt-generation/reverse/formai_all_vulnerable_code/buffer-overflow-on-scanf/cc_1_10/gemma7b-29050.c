//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

int main()
{
    int grid[GRID_SIZE][GRID_SIZE] = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};

    int player_x = 0, player_y = 0, target_x = 2, target_y = 2;

    // Initialize the game
    grid[player_x][player_y] = 1;
    grid[target_x][target_y] = 2;

    // Game loop
    while (grid[target_x][target_y] != 3)
    {
        int move_x = 0, move_y = 0;

        // Get the player's move
        printf("Enter move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (move_x < 0 || move_x >= GRID_SIZE || move_y < 0 || move_y >= GRID_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Move the player
        player_x += move_x;
        player_y += move_y;

        // Place the player's mark
        grid[player_x][player_y] = 1;

        // Check if the target has been reached
        if (player_x == target_x && player_y == target_y)
        {
            grid[target_x][target_y] = 3;
            printf("Congratulations! You won!\n");
        }
    }

    return 0;
}