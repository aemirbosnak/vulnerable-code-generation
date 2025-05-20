//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT 0
#define PLAYER_X 1
#define PLAYER_O 2

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = { { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT },
                                 { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT },
                                 { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT } };

    int player = PLAYER_X;
    int move_count = 0;

    // Game loop
    while (!board[1][1] && move_count < 9) {
        int move_row, move_col;

        // Get the player's move
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the spot is empty
        if (board[move_row][move_col] != EMPTY_SPOT) {
            printf("That spot is already taken.\n");
            continue;
        }

        // Make the move
        board[move_row][move_col] = player;

        // Increment the move count
        move_count++;

        // Check if the player has won
        if (check_win(board, player) || move_count == 9) {
            break;
        }

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // End game
    printf("Game over!\n");

    return 0;
}

int check_win(int **board, int player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // No win
    return 0;
}