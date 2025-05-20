//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Position;

typedef struct {
    char type;
    Position position;
} Piece;

typedef struct {
    Piece pieces[16];
    int turn;
} Board;

void printBoard(Board board) {
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            Piece piece = board.pieces[y * 8 + x];
            printf("%c ", piece.type);
        }
        printf("\n");
    }
}

int main() {
    Board board;
    board.turn = 0;

    // Initialize the board
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Piece piece;
            piece.position.x = x;
            piece.position.y = y;
            if (y == 1 || y == 6) {
                piece.type = 'P';
            } else if (y == 0 || y == 7) {
                if (x == 0 || x == 7) {
                    piece.type = 'R';
                } else if (x == 1 || x == 6) {
                    piece.type = 'N';
                } else if (x == 2 || x == 5) {
                    piece.type = 'B';
                } else if (x == 3) {
                    piece.type = 'Q';
                } else if (x == 4) {
                    piece.type = 'K';
                }
            } else {
                piece.type = ' ';
            }
            board.pieces[y * 8 + x] = piece;
        }
    }

    // Print the board
    printBoard(board);

    return 0;
}