//Gemma-7B DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char board[6][6] = {{' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', 'S', ' ', ' ', ' ', ' '},
                              {' ', ' ', 'T', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', 'O', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' '}};

    int player_1_turn = 1;
    int game_over = 0;

    while (!game_over)
    {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Check if the move is valid
        if (move_x < 0 || move_x >= 6 || move_y < 0 || move_y >= 6)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is already taken
        if (board[move_x][move_y] != ' ')
        {
            printf("That move has already been taken.\n");
            continue;
        }

        // Make the move
        board[move_x][move_y] = 'X';

        // Check if the player has won
        if (check_win(board, player_1_turn))
        {
            game_over = 1;
            printf("You have won!\n");
        }

        // Check if the game is over
        else if (board[5][5] == 'O' || board[5][5] == 'X')
        {
            game_over = 1;
            printf("It's a draw.\n");
        }

        // Switch turns
        player_1_turn = !player_1_turn;
    }

    return 0;
}

int check_win(char board[6][6], int player_1_turn)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player_1_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 6; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player_1_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player_1_turn)
    {
        return 1;
    }

    // Check for draw
    if (board[5][5] == 'O' || board[5][5] == 'X')
    {
        return 1;
    }

    return 0;
}