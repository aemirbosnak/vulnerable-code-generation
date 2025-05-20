//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[4][4] = {{0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0}};

    int n_players = 2;
    int current_player = 0;

    // Game Loop
    while (!board[3][3] && n_players > 0)
    {
        // Get the move
        int move_row, move_col;

        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= 4)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (move_col < 0 || move_col >= 4)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (board[move_row][move_col] != 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[move_row][move_col] = current_player;

        // Check if the player has won
        if (board[move_row][move_col] == current_player)
        {
            printf("You have won!\n");
            n_players--;
        }

        // Switch to the next player
        current_player = (current_player == 0) ? 1 : 0;
    }

    // Game Over
    printf("Game over.\n");

    return 0;
}