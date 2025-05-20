//Gemma-7B DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char board[6][6] = {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {'g', 'h', 'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p', 'q', 'r'},
        {'s', 't', 'u', 'v', 'w', 'x'},
        {'y', 'z', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_'}
    };

    int player_1_turn = 1;
    int game_won = 0;

    // Game loop
    while (!game_won)
    {
        // Get the player's move
        char move;
        printf("Enter your move: ");
        scanf("%c", &move);

        // Validate the move
        if (move < 'a' || move > 'f')
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        board[move - 'a'][0] = player_1_turn;

        // Check if the player has won
        game_won = check_win(board, player_1_turn);

        // Switch turns
        player_1_turn = (player_1_turn == 1) ? 2 : 1;
    }

    // Game over
    printf("Game over! The winner is: ");
    printf(board[0][0] == 1 ? "Player 1" : "Player 2");

    return 0;
}

int check_win(char **board, int player_turn)
{
    // Check rows
    for (int r = 0; r < 6; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 6; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player_turn)
    {
        return 1;
    }

    // No win
    return 0;
}