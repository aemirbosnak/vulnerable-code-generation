//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY},
                                 {EMPTY, EMPTY, EMPTY},
                                 {EMPTY, EMPTY, EMPTY}};

    int player = PLAYER_X;
    int game_on = 1;

    // Game loop
    while (game_on)
    {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (board[move_x][move_y] != EMPTY)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        board[move_x][move_y] = player;

        // Check if the player has won
        if (check_win(board, player) || draw(board))
        {
            game_on = 0;
        }

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over message
    printf("Game over! The winner is: ");
    if (board[0][0] == PLAYER_X)
    {
        printf("Player X\n");
    }
    else if (board[0][0] == PLAYER_O)
    {
        printf("Player O\n");
    }
    else
    {
        printf("It's a draw.\n");
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
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
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

int draw(int **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                return 0;
            }
        }
    }

    return 1;
}