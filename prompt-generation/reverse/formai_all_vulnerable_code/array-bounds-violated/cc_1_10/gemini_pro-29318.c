//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Position;

typedef struct {
    int type;
    Position position;
} Piece;

typedef struct {
    Piece pieces[32];
    int turn;
} Board;

void print_board(Board *board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board->pieces[i * 8 + j];
            switch (piece.type) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("P");
                    break;
                case 2:
                    printf("R");
                    break;
                case 3:
                    printf("N");
                    break;
                case 4:
                    printf("B");
                    break;
                case 5:
                    printf("Q");
                    break;
                case 6:
                    printf("K");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;

    // Initialize the board
    for (int i = 0; i < 32; i++) {
        board.pieces[i].type = 0;
    }

    // Place the white pieces
    for (int i = 0; i < 8; i++) {
        board.pieces[i].type = 1;
        board.pieces[i].position.x = i;
        board.pieces[i].position.y = 1;

        board.pieces[16 + i].type = 2;
        board.pieces[16 + i].position.x = i;
        board.pieces[16 + i].position.y = 0;

        board.pieces[24 + i].type = 3;
        board.pieces[24 + i].position.x = i;
        board.pieces[24 + i].position.y = 2;

        board.pieces[32 + i].type = 4;
        board.pieces[32 + i].position.x = i;
        board.pieces[32 + i].position.y = 3;

        board.pieces[40].type = 5;
        board.pieces[40].position.x = 3;
        board.pieces[40].position.y = 0;

        board.pieces[41].type = 6;
        board.pieces[41].position.x = 4;
        board.pieces[41].position.y = 0;
    }

    // Place the black pieces
    for (int i = 0; i < 8; i++) {
        board.pieces[48 + i].type = 1;
        board.pieces[48 + i].position.x = i;
        board.pieces[48 + i].position.y = 6;

        board.pieces[64 + i].type = 2;
        board.pieces[64 + i].position.x = i;
        board.pieces[64 + i].position.y = 7;

        board.pieces[72 + i].type = 3;
        board.pieces[72 + i].position.x = i;
        board.pieces[72 + i].position.y = 5;

        board.pieces[80 + i].type = 4;
        board.pieces[80 + i].position.x = i;
        board.pieces[80 + i].position.y = 4;

        board.pieces[88].type = 5;
        board.pieces[88].position.x = 3;
        board.pieces[88].position.y = 7;

        board.pieces[89].type = 6;
        board.pieces[89].position.x = 4;
        board.pieces[89].position.y = 7;
    }

    // Print the board
    print_board(&board);

    return 0;
}