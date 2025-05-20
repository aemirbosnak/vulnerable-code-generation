//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define BLACK 1
#define RED 2
#define EMPTY 0

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int player;
    Position position;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} Board;

void init_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3) {
                board->board[i][j].player = RED;
            } else if (i > 4) {
                board->board[i][j].player = BLACK;
            } else {
                board->board[i][j].player = EMPTY;
            }
            board->board[i][j].position.row = i;
            board->board[i][j].position.col = j;
        }
    }
}

void print_board(Board *board) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j].player == BLACK) {
                printf("B ");
            } else if (board->board[i][j].player == RED) {
                printf("R ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(Board *board, Position from, Position to) {
    Piece piece = board->board[from.row][from.col];
    if (piece.player == EMPTY) {
        return 0;
    }
    if (to.row < 0 || to.row >= BOARD_SIZE || to.col < 0 || to.col >= BOARD_SIZE) {
        return 0;
    }
    if (board->board[to.row][to.col].player != EMPTY) {
        return 0;
    }
    if (piece.player == BLACK) {
        if (to.row - from.row != -1) {
            return 0;
        }
        if (abs(to.col - from.col) != 1) {
            return 0;
        }
    } else if (piece.player == RED) {
        if (to.row - from.row != 1) {
            return 0;
        }
        if (abs(to.col - from.col) != 1) {
            return 0;
        }
    }
    return 1;
}

void make_move(Board *board, Position from, Position to) {
    Piece piece = board->board[from.row][from.col];
    board->board[to.row][to.col] = piece;
    board->board[from.row][from.col].player = EMPTY;
}

int main() {
    Board board;
    init_board(&board);
    print_board(&board);

    while (1) {
        Position from, to;
        printf("From (row, col): ");
        scanf("%d %d", &from.row, &from.col);
        printf("To (row, col): ");
        scanf("%d %d", &to.row, &to.col);

        if (is_valid_move(&board, from, to)) {
            make_move(&board, from, to);
            print_board(&board);
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}