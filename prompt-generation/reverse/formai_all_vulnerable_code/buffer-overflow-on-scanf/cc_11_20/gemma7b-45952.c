//Gemma-7B DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    int player_1_turn = 1;
    int game_over = 0;

    while (!game_over)
    {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (move_x < 0 || move_x >= 6)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (move_y < 0 || move_y >= 6)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (board[move_x][move_y] != 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the player's piece on the board
        board[move_x][move_y] = player_1_turn;

        // Check if the player has won
        if (check_win(board, player_1_turn))
        {
            game_over = 1;
            printf("You have won!\n");
        }

        // If it's not the player's turn, switch to the next player
        if (player_1_turn == 1)
        {
            player_1_turn = 2;
        }
        else
        {
            player_1_turn = 1;
        }
    }

    return 0;
}

int check_win(int board[6][6], int player_turn)
{
    // Check rows
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (board[r][c] == player_turn && board[r][c] == board[r][c+1] && board[r][c] == board[r][c+2] && board[r][c] == board[r][c+3] && board[r][c] == board[r][c+4])
            {
                return 1;
            }
        }
    }

    // Check columns
    for (int c = 0; c < 6; c++)
    {
        for (int r = 0; r < 6; r++)
        {
            if (board[r][c] == player_turn && board[r][c] == board[r+1][c] && board[r][c] == board[r+2][c] && board[r][c] == board[r+3][c] && board[r][c] == board[r+4][c])
            {
                return 1;
            }
        }
    }

    // Check diagonals
    for (int d = 0; d < 6; d++)
    {
        for (int r = 0; r < 6; r++)
        {
            for (int c = 0; c < 6; c++)
            {
                if (board[r][c] == player_turn && board[r][c] == board[r+1][c+1] && board[r][c] == board[r+2][c+2] && board[r][c] == board[r+3][c+3] && board[r][c] == board[r+4][c+4])
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}