//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0}};
    int player_1_turn = 1;
    int game_over = 0;
    int i, j, move_x, move_y;

    // Initialize the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (!game_over)
    {
        // Get the player's move
        printf("Enter move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (move_x < 0 || move_x >= MAX_SIZE || move_y < 0 || move_y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is valid
        if (board[move_x][move_y] != 0)
        {
            printf("Move already made.\n");
            continue;
        }

        // Make the move
        board[move_x][move_y] = player_1_turn;

        // Check if the player has won
        if (check_win(board, player_1_turn) == 1)
        {
            game_over = 1;
            printf("Player %d has won!\n", player_1_turn);
        }

        // Switch turns
        player_1_turn *= -1;
    }

    return 0;
}

int check_win(int **board, int player_turn)
{
    // Check rows
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (board[0][i] == player_turn && board[1][i] == player_turn && board[2][i] == player_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_SIZE; j++)
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

    // Check for draw
    if (board[0][0] != 0 && board[0][1] != 0 && board[0][2] != 0 && board[1][0] != 0 && board[1][1] != 0 && board[1][2] != 0 && board[2][0] != 0 && board[2][1] != 0 && board[2][2] != 0)
    {
        return 2;
    }

    return 0;
}