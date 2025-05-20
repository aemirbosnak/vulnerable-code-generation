//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum player_type {
    PLAYER_ONE = 1,
    PLAYER_TWO = 2
};

enum piece_type {
    EMPTY = 0,
    RED_PIECE = 1,
    BLACK_PIECE = 2,
    RED_KING = 3,
    BLACK_KING = 4
};

typedef struct {
    int row;
    int col;
} move_t;

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j] = BLACK_PIECE;
            } else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j] = RED_PIECE;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   0  1  2  3  4  5  6  7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf("|  ");
                    break;
                case RED_PIECE:
                    printf("| r");
                    break;
                case BLACK_PIECE:
                    printf("| b");
                    break;
                case RED_KING:
                    printf("| R");
                    break;
                case BLACK_KING:
                    printf("| B");
                    break;
            }
        }
        printf("|\n");
    }
}

int is_move_valid(int player, int board[BOARD_SIZE][BOARD_SIZE], move_t move) {
    int piece = board[move.row][move.col];
    if (piece == EMPTY) {
        return 0;
    }
    if (piece == RED_PIECE && player == PLAYER_TWO) {
        return 0;
    }
    if (piece == BLACK_PIECE && player == PLAYER_ONE) {
        return 0;
    }
    return 1;
}

move_t get_move() {
    move_t move;
    printf("Enter a move (row, col): ");
    scanf("%d %d", &move.row, &move.col);
    return move;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player_turn = PLAYER_ONE;
    int game_over = 0;
    initialize_board(board);

    while (!game_over) {
        printf("Player %d's turn.\n", player_turn);
        print_board(board);
        move_t move = get_move();
        if (!is_move_valid(player_turn, board, move)) {
            printf("Invalid move!\n");
            continue;
        }
        // apply move
        board[move.row][move.col] = EMPTY;
        if (player_turn == PLAYER_ONE) {
            board[move.row - 1][move.col - 1] = BLACK_PIECE;
        } else if (player_turn == PLAYER_TWO) {
            board[move.row + 1][move.col + 1] = RED_PIECE;
        }
        // check for game over
        game_over = 1;
    }
    printf("Game over!\n");

    return 0;
}