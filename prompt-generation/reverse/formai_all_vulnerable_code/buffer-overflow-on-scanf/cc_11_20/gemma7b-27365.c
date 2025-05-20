//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define DELAY 500

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0}};
    int player = 1, turn = 0, win = 0;

    // Initialize the board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    while (!win)
    {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (move_x < 0 || move_x >= MAX_SIZE || move_y < 0 || move_y >= MAX_SIZE)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece
        board[move_x][move_y] = player;

        // Check if the player has won
        win = check_win(board, player);

        // Next turn
        turn++;
    }

    // Game over
    printf("Game over! The winner is: ");
    printf("Player %d\n", player);

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_SIZE; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    // No win
    return 0;
}