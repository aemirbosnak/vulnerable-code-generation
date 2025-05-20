//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int value;
} Piece;

typedef struct {
    Piece pieces[32];
    int turn;
} Board;

void print_board(Board board) {
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            Piece piece = board.pieces[y * 8 + x];
            if (piece.value == 0) {
                printf("  ");
            } else {
                printf("%c ", piece.value);
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;

    // Initialize the board.
    for (int i = 0; i < 32; i++) {
        board.pieces[i].point.x = i % 8;
        board.pieces[i].point.y = i / 8;
        board.pieces[i].value = 0;
    }

    // Place the pieces on the board.
    board.pieces[0].value = 'R';
    board.pieces[1].value = 'N';
    board.pieces[2].value = 'B';
    board.pieces[3].value = 'Q';
    board.pieces[4].value = 'K';
    board.pieces[5].value = 'B';
    board.pieces[6].value = 'N';
    board.pieces[7].value = 'R';
    for (int i = 8; i < 16; i++) {
        board.pieces[i].value = 'P';
    }
    for (int i = 24; i < 32; i++) {
        board.pieces[i].value = 'p';
    }

    // Set the turn to white.
    board.turn = 'w';

    // Print the board.
    print_board(board);

    return 0;
}