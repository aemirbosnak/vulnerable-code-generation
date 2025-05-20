//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char type;
    Position position;
} Piece;

typedef struct {
    Piece pieces[16];
} Board;

void print_board(Board board) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Piece piece = board.pieces[y * BOARD_SIZE + x];
            printf("%c ", piece.type);
        }
        printf("\n");
    }
}

int main() {
    Board board;

    // Initialize the board with the starting position.
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Piece piece;
            piece.position.x = x;
            piece.position.y = y;

            if (y == 1 || y == 6) {
                piece.type = 'P';
            } else if (y == 0 || y == 7) {
                switch (x) {
                    case 0:
                    case 7:
                        piece.type = 'R';
                        break;
                    case 1:
                    case 6:
                        piece.type = 'N';
                        break;
                    case 2:
                    case 5:
                        piece.type = 'B';
                        break;
                    case 3:
                        piece.type = 'Q';
                        break;
                    case 4:
                        piece.type = 'K';
                        break;
                }
            } else {
                piece.type = ' ';
            }

            board.pieces[y * BOARD_SIZE + x] = piece;
        }
    }

    // Print the board.
    print_board(board);

    return 0;
}