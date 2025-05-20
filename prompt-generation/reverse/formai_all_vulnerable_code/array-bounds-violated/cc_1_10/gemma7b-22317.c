//Gemma-7B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main()
{
    char board[MAX_SIZE][MAX_SIZE] = {{0}};
    int player1_turn = 1;
    int game_status = 0;
    int row, column;

    // Initialize the game board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (!game_status)
    {
        // Get the player's move
        printf("Enter row: ");
        scanf("%d", &row);

        printf("Enter column: ");
        scanf("%d", &column);

        // Check if the move is valid
        if (board[row][column] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's mark on the board
        board[row][column] = player1_turn;

        // Check if the player has won
        game_status = check_win(board, player1_turn);

        // Switch turns
        player1_turn *= -1;
    }

    // Game over
    printf("Game over!\n");

    return 0;
}

int check_win(char board[MAX_SIZE][MAX_SIZE], int player_turn)
{
    // Check rows
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_SIZE; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player_turn)
    {
        return 1;
    }

    // No winner
    return 0;
}