//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_NUM 2

int main()
{
    int player_num = 0;
    char board[6][6] = {{' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '}};

    // Initialize the game board
    for (int i = 0; i < MAX_PLAYER_NUM; i++)
    {
        board[0][i] = 'X';
    }

    // Play the game
    while (1)
    {
        // Get the player's move
        int move = 0;
        printf("Enter your move (1-6): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 6)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's mark on the board
        board[move][player_num] = 'O';

        // Check if the player has won
        if (check_win(board, player_num) == 1)
        {
            printf("You have won!\n");
            break;
        }

        // Check if the board is full
        if (is_board_full(board) == 1)
        {
            printf("It's a draw.\n");
            break;
        }

        // Switch to the next player
        player_num = (player_num == 0) ? 1 : 0;
    }

    return 0;
}

int check_win(char **board, int player_num)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == player_num)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 6; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == player_num)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player_num)
    {
        return 1;
    }

    // Check if the board is full
    if (is_board_full(board) == 1)
    {
        return 1;
    }

    return 0;
}

int is_board_full(char **board)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }

    return 1;
}