//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Create a 6x6 checkerboard
    int board[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    // Place the checkers
    board[1][2] = 1;
    board[2][2] = 1;
    board[3][2] = 1;
    board[4][2] = 1;

    // Game loop
    int game_on = 1;
    while (game_on)
    {
        // Get the player's move
        int move_row, move_col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Check if the move is valid
        if (board[move_row][move_col] == 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Move the checker
        board[move_row][move_col] = 1;
        board[move_row - 1][move_col] = 0;

        // Check if the player has won
        if (board[move_row - 1][move_col] == 0)
        {
            game_on = 0;
            printf("You have won!\n");
        }
    }

    // End of game
    printf("Thank you for playing.\n");
}