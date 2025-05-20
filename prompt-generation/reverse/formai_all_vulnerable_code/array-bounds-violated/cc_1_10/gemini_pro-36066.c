//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    char piece;
} Piece;

typedef struct {
    Piece pieces[16];
    int turn;
} Board;

void print_board(Board *board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board->pieces[i * 8 + j];
            printf("%c", piece.piece);
        }
        printf("\n");
    }
}

int main() {
    Board board;

    // Initialize the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board.pieces[i * 8 + j].position.x = i;
            board.pieces[i * 8 + j].position.y = j;
            if (i == 1) {
                board.pieces[i * 8 + j].piece = 'p';
            } else if (i == 6) {
                board.pieces[i * 8 + j].piece = 'P';
            } else if (i == 0 || i == 7) {
                switch (j) {
                    case 0:
                    case 7:
                        board.pieces[i * 8 + j].piece = 'r';
                        break;
                    case 1:
                    case 6:
                        board.pieces[i * 8 + j].piece = 'n';
                        break;
                    case 2:
                    case 5:
                        board.pieces[i * 8 + j].piece = 'b';
                        break;
                    case 3:
                        board.pieces[i * 8 + j].piece = 'q';
                        break;
                    case 4:
                        board.pieces[i * 8 + j].piece = 'k';
                        break;
                }
            } else {
                board.pieces[i * 8 + j].piece = ' ';
            }
        }
    }

    // Print the board
    print_board(&board);

    return 0;
}