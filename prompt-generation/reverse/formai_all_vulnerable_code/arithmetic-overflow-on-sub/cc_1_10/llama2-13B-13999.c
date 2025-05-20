//LLAMA2-13B DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8
#define PIECE_SIZE 30
#define SQUARE_SIZE 10

typedef struct {
    char color;  // Either 'X' or 'O'
    int row;
    int col;
} Piece;

Piece make_piece(char color) {
    Piece p;
    p.color = color;
    p.row = rand() % ROWS;
    p.col = rand() % COLS;
    return p;
}

void print_board(Piece board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j].color == 'X') {
                printf("X");
            } else if (board[i][j].color == 'O') {
                printf("O");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void move_piece(Piece board[ROWS][COLS], int row, int col, char color) {
    Piece piece = board[row][col];
    board[row][col] = make_piece(color);
    board[piece.row][piece.col] = piece;
}

void game_loop(Piece board[ROWS][COLS]) {
    char player = 'X';
    int turn = 1;
    while (1) {
        print_board(board);
        printf("Player %c's turn (1-3): ", player);
        int move = scanf("%d", &turn);
        if (move == 0) {
            break;
        }
        move_piece(board, turn - 1, 0, player);
        player = player == 'X' ? 'O' : 'X';
    }
}

int main() {
    Piece board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = make_piece('X');
        }
    }
    game_loop(board);
    return 0;
}