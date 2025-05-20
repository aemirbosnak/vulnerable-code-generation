//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK -1

typedef struct {
    int x;
    int y;
} Square;

typedef struct {
    Square position;
    int color;
    int type;
} Piece;

typedef struct {
    Piece pieces[16];
} Side;

typedef struct {
    Side white;
    Side black;
} Board;

void print_board(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board.white.pieces[i * BOARD_SIZE + j];
            if (piece.type != 0) {
                printf("%c", piece.type == 1 ? 'P' : 'K');
            } else {
                piece = board.black.pieces[i * BOARD_SIZE + j];
                if (piece.type != 0) {
                    printf("%c", piece.type == 1 ? 'p' : 'k');
                } else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;

    // Initialize the board.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.white.pieces[i * BOARD_SIZE + j].type = 0;
            board.white.pieces[i * BOARD_SIZE + j].color = WHITE;
            board.black.pieces[i * BOARD_SIZE + j].type = 0;
            board.black.pieces[i * BOARD_SIZE + j].color = BLACK;
        }
    }

    // Place the pawns.
    for (int i = 0; i < BOARD_SIZE; i++) {
        board.white.pieces[i].type = 1;
        board.black.pieces[i + BOARD_SIZE * (BOARD_SIZE - 2)].type = 1;
    }

    // Place the kings.
    board.white.pieces[4].type = 2;
    board.black.pieces[4 + BOARD_SIZE * (BOARD_SIZE - 1)].type = 2;

    // Print the board.
    print_board(board);

    return 0;
}