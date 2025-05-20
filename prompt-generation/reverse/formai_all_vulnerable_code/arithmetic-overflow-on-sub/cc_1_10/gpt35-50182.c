//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define NO_PIECE 0
#define BLACK 1
#define WHITE 2

int board[BOARD_SIZE][BOARD_SIZE];
int turn = BLACK;

void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3) {
                    board[row][col] = WHITE;
                } else if (row > 4) {
                    board[row][col] = BLACK;
                } else {
                    board[row][col] = NO_PIECE;
                }
            } else {
                board[row][col] = NO_PIECE;
            }
        }
    }
}

int is_valid_move(int start_row, int start_col, int end_row, int end_col) {
    if (board[end_row][end_col] != NO_PIECE) {
        return 0;
    }

    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;

    if (turn == BLACK) {
        if (row_diff != 1) {
            return 0;
        }
    } else {
        if (row_diff != -1) {
            return 0;
        }
    }

    if (abs(col_diff) != 1) {
        return 0;
    }

    return 1;
}

int make_move(int start_row, int start_col, int end_row, int end_col) {
    if (!is_valid_move(start_row, start_col, end_row, end_col)) {
        return 0;
    }

    board[start_row][start_col] = NO_PIECE;
    board[end_row][end_col] = turn;

    return 1;
}

void display_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == BLACK) {
                printf("B ");
            } else if (board[row][col] == WHITE) {
                printf("W ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to C Checkers!\n");

    initialize_board();

    while (1) {
        display_board();

        if (turn == BLACK) {
            printf("Black's turn!\n");
        } else {
            printf("White's turn!\n");
        }

        int start_row, start_col, end_row, end_col;

        printf("Enter the start row: ");
        scanf("%d", &start_row);

        printf("Enter the start col: ");
        scanf("%d", &start_col);

        printf("Enter the end row: ");
        scanf("%d", &end_row);

        printf("Enter the end col: ");
        scanf("%d", &end_col);

        if (make_move(start_row, start_col, end_row, end_col)) {
            if (turn == BLACK) {
                turn = WHITE;
            } else {
                turn = BLACK;
            }
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}