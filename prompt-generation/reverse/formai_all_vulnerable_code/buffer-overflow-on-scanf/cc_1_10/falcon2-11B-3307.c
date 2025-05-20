//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 50
#define MAX_ROWS 8
#define MAX_COLUMNS 8

struct chess_board {
    int board[MAX_ROWS][MAX_COLUMNS];
    int white_turn;
};

void initialize_board(struct chess_board* board) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            board->board[i][j] = 0;
        }
    }
    board->white_turn = 1;
}

void print_board(struct chess_board* board) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int is_move_valid(struct chess_board* board, int row, int column) {
    int result = 1;
    if (row < 0 || row >= MAX_ROWS || column < 0 || column >= MAX_COLUMNS) {
        result = 0;
    }
    else if (board->board[row][column]!= 0) {
        result = 0;
    }
    return result;
}

void move_piece(struct chess_board* board, int row, int column, int new_row, int new_column) {
    if (!is_move_valid(board, row, column) ||!is_move_valid(board, new_row, new_column)) {
        return;
    }
    int temp = board->board[row][column];
    board->board[row][column] = 0;
    board->board[new_row][new_column] = temp;
}

int main() {
    struct chess_board board;
    initialize_board(&board);

    int move;
    do {
        print_board(&board);
        printf("\nEnter a move: ");
        scanf("%d", &move);
        move_piece(&board, move / MAX_COLUMNS, move % MAX_COLUMNS, move / MAX_COLUMNS, move % MAX_COLUMNS);
    } while (move!= -1);

    print_board(&board);

    return 0;
}