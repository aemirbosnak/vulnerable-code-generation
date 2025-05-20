//Gemma-7B DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int main()
{
    int board[MAX_NUM][MAX_NUM] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                                {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                                {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                                {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                            };

    int player_1_turn = 1;
    int game_over = 0;

    while (!game_over)
    {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d, %d", &move_x, &move_y);

        // Check if the move is valid
        if (move_x < 0 || move_x >= MAX_NUM || move_y < 0 || move_y >= MAX_NUM)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is free
        if (board[move_x][move_y] != 0)
        {
            printf("That move is already taken.\n");
            continue;
        }

        // Make the move
        board[move_x][move_y] = player_1_turn;

        // Check if the player has won
        if (check_win(board, player_1_turn))
        {
            game_over = 1;
            printf("You have won!\n");
        }

        // If the player has not won, switch turns
        player_1_turn = (player_1_turn == 1) ? 2 : 1;
    }

    return 0;
}

int check_win(int **board, int player_turn)
{
    // Check rows
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (board[0][i] == player_turn && board[1][i] == player_turn && board[2][i] == player_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_NUM; j++)
    {
        if (board[j][0] == player_turn && board[j][1] == player_turn && board[j][2] == player_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player_turn && board[1][1] == player_turn && board[2][2] == player_turn)
    {
        return 1;
    }

    if (board[0][2] == player_turn && board[1][1] == player_turn && board[2][0] == player_turn)
    {
        return 1;
    }

    // If there has not been a win, return 0
    return 0;
}