//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define EMPTY_CELL -1

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
                                {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
                                {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}};

    int player_turn = 0;
    int game_status = 0;

    // Game loop
    while (!game_status)
    {
        // Get the player's move
        int move_x = -1;
        int move_y = -1;

        // Validate the move
        while (move_x < 0 || move_x >= BOARD_SIZE || move_y < 0 || move_y >= BOARD_SIZE || board[move_x][move_y] != EMPTY_CELL)
        {
            printf("Invalid move. Please try again:");
            scanf("%d %d", &move_x, &move_y);
        }

        // Place the player's mark on the board
        board[move_x][move_y] = player_turn;

        // Check if the player has won or if the game is a draw
        game_status = check_win(board, player_turn) || draw_game(board);

        // Switch turns
        player_turn = (player_turn == 0) ? 1 : 0;
    }

    // Game over message
    printf("Game over! The winner is: ");

    // Print the winner or draw message
    if (game_status)
    {
        printf("Player %d", player_turn);
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}

int check_win(int **board, int player_turn)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
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

    // No win, so return 0
    return 0;
}

int draw_game(int **board)
{
    // Check if all cells are filled
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_CELL)
            {
                return 0;
            }
        }
    }

    // All cells are filled, so it's a draw
    return 1;
}