//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int board[BOARD_SIZE][BOARD_SIZE];
    int current_player;
    int game_status;
} Board;

void initialize_board(Board *board) {
    board->current_player = 1;
    board->game_status = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

int is_board_full(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i] * 2;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0] * 2;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0] * 2;
    }

    // If all else fails, it's a draw
    return 0;
}

int main() {
    Board board;
    initialize_board(&board);

    // Play the game
    while (!is_board_full(&board) && check_win(&board) == 0) {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Place the marker on the board
        board.board[move_x][move_y] = board.current_player;

        // Switch players
        board.current_player *= -1;
    }

    // Check if the player won or it's a draw
    if (check_win(&board) != 0) {
        printf("Congratulations! You won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}