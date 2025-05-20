//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define PIECE_COUNT 16

enum PieceColor {
    WHITE,
    BLACK
};

enum PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

struct Piece {
    enum PieceColor color;
    enum PieceType type;
};

struct Board {
    struct Piece pieces[PIECE_COUNT];
};

void initBoard(struct Board* board) {
    int i;
    for (i = 0; i < PIECE_COUNT; i++) {
        board->pieces[i].color = WHITE;
        board->pieces[i].type = PAWN;
    }
}

void printBoard(const struct Board* board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", 'A' + i * BOARD_SIZE + j);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    struct Board board;
    initBoard(&board);

    while (1) {
        printBoard(&board);

        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
            x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
            printf("Invalid move\n");
            continue;
        }

        if (board.pieces[y1 * BOARD_SIZE + x1].color!= WHITE ||
            board.pieces[y2 * BOARD_SIZE + x2].color!= BLACK) {
            printf("Invalid move\n");
            continue;
        }

        board.pieces[y2 * BOARD_SIZE + x2].color = WHITE;
        board.pieces[y1 * BOARD_SIZE + x1].color = BLACK;
    }

    return 0;
}