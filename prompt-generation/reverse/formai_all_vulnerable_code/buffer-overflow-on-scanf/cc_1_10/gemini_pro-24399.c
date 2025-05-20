//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    bool is_black;
    bool is_king;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} Board;

void print_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j].is_black) {
                printf("B");
            } else if (board->board[i][j].is_king) {
                printf("K");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

bool is_valid_move(Board* board, Position* from, Position* to) {
    if (from->row < 0 || from->row >= BOARD_SIZE || from->col < 0 || from->col >= BOARD_SIZE) {
        return false;
    }
    if (to->row < 0 || to->row >= BOARD_SIZE || to->col < 0 || to->col >= BOARD_SIZE) {
        return false;
    }
    if (board->board[from->row][from->col].is_black == board->board[to->row][to->col].is_black) {
        return false;
    }
    if (abs(from->row - to->row) != 1 && abs(from->col - to->col) != 1) {
        return false;
    }
    if (board->board[from->row][from->col].is_king) {
        return true;
    }
    if (board->board[from->row][from->col].is_black && to->row < from->row) {
        return false;
    }
    if (!board->board[from->row][from->col].is_black && to->row > from->row) {
        return false;
    }
    return true;
}

bool make_move(Board* board, Position* from, Position* to) {
    if (!is_valid_move(board, from, to)) {
        return false;
    }
    board->board[to->row][to->col] = board->board[from->row][from->col];
    board->board[from->row][from->col].is_black = false;
    board->board[from->row][from->col].is_king = false;
    if (to->row == 0 || to->row == BOARD_SIZE - 1) {
        board->board[to->row][to->col].is_king = true;
    }
    return true;
}

int main() {
    Board board;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.board[i][j].is_black = false;
            board.board[i][j].is_king = false;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == 0) {
                board.board[i][j].is_black = true;
            } else {
                board.board[i][j].is_black = true;
            }
        }
    }
    print_board(&board);
    Position from;
    Position to;
    while (true) {
        printf("Enter the coordinates of the piece you want to move (row, column): ");
        scanf("%d %d", &from.row, &from.col);
        printf("Enter the coordinates of the square you want to move to (row, column): ");
        scanf("%d %d", &to.row, &to.col);
        if (make_move(&board, &from, &to)) {
            print_board(&board);
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}