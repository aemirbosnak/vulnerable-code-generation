//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE ' '

char board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
    {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
    {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}
};

int is_board_full() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == EMPTY_SPACE) {
                return 0;
            }
        }
    }

    return 1;
}

int has_player_won(char player) {
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

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char current_player = PLAYER_X;
    int game_won = 0;

    // Initialize the board
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c] = EMPTY_SPACE;
        }
    }

    // Game loop
    while (!game_won && !is_board_full()) {
        // Get the player's move
        int move_row, move_column;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move_row, &move_column);

        // Check if the move is valid
        if (board[move_row][move_column] != EMPTY_SPACE) {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[move_row][move_column] = current_player;

        // Check if the player has won
        game_won = has_player_won(current_player);

        // Switch to the next player
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over
    if (game_won) {
        printf("Congratulations! You won!\n");
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}