//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

#define EMPTY 0

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = { { EMPTY, EMPTY, EMPTY },
                                 { EMPTY, EMPTY, EMPTY },
                                 { EMPTY, EMPTY, EMPTY } };

    int player = PLAYER_X;
    int game_over = 0;

    // Game loop
    while (!game_over)
    {
        int row, column;

        // Get the player's move
        printf("Enter row (1-2-3): ");
        scanf("%d", &row);

        printf("Enter column (1-2-3): ");
        scanf("%d", &column);

        // Check if the move is valid
        if (board[row][column] != EMPTY)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][column] = player;

        // Check if the player has won
        game_over = check_win(board, player);

        // If the player has not won, switch to the next player
        if (!game_over)
        {
            player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    // Game over
    printf("Game over!\n");

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // No win
    return 0;
}