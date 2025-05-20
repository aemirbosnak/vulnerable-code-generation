//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    int player1_turn = 1;
    int game_over = 0;

    // Game loop
    while (!game_over)
    {
        // Get the player's move
        int row, col;
        printf("Enter row (1-5): ");
        scanf("%d", &row);
        printf("Enter column (1-5): ");
        scanf("%d", &col);

        // Check if the move is valid
        if (row < 1 || row > 5 || col < 1 || col > 5)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        board[row - 1][col - 1] = player1_turn;

        // Check if the player has won
        if (check_win(board, player1_turn))
        {
            game_over = 1;
            printf("Player %d has won!\n", player1_turn);
        }

        // Switch turns
        player1_turn *= -1;
    }

    return 0;
}

int check_win(char board[][6], int player_turn)
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

    // Check if the board is full
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (board[r][c] == 0)
            {
                return 0;
            }
        }
    }

    // No winner or full board
    return 0;
}