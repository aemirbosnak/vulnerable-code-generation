//FormAI DATASET v1.0 Category: Chess engine ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define WHITE 'w'
#define BLACK 'b'

struct Board {
    char squares[8][8];
    char turn;
    int whiteCastlingK;
    int whiteCastlingQ;
    int blackCastlingK;
    int blackCastlingQ;
    int epSquare;
    int halfMoveClock;
    int fullMoveClock;
};

struct Move {
    int fromSquare;
    int toSquare;
    char promotion;
};

void initializeBoard(struct Board *board) {
    int i, j;

    board->turn = WHITE;
    board->whiteCastlingK = 1;
    board->whiteCastlingQ = 1;
    board->blackCastlingK = 1;
    board->blackCastlingQ = 1;
    board->epSquare = -1;
    board->halfMoveClock = 0;
    board->fullMoveClock = 1;

    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(i == 0 && (j == 0 || j == 7)) {
                board->squares[i][j] = 'R';
            } else if(i == 0 && (j == 1 || j == 6)) {
                board->squares[i][j] = 'N';
            } else if(i == 0 && (j == 2 || j == 5)) {
                board->squares[i][j] = 'B';
            } else if(i == 0 && j == 3) {
                board->squares[i][j] = 'Q';
            } else if(i == 0 && j == 4) {
                board->squares[i][j] = 'K';
            } else if(i == 1) {
                board->squares[i][j] = 'P';
            } else if(i == 6) {
                board->squares[i][j] = 'p';
            } else if(i == 7 && (j == 0 || j == 7)) {
                board->squares[i][j] = 'r';
            } else if(i == 7 && (j == 1 || j == 6)) {
                board->squares[i][j] = 'n';
            } else if(i == 7 && (j == 2 || j == 5)) {
                board->squares[i][j] = 'b';
            } else if(i == 7 && j == 3) {
                board->squares[i][j] = 'q';
            } else if(i == 7 && j == 4) {
                board->squares[i][j] = 'k';
            } else {
                board->squares[i][j] = ' ';
            }
        }
    }
}

void printBoard(struct Board *board) {
    int i, j;

    printf("\n   a b c d e f g h\n");
    printf("  +-----------------+\n");

    for(i = 0; i < 8; i++) {
        printf("%d |", 8 - i);
        for(j = 0; j < 8; j++) {
            printf("%c|", board->squares[i][j]);
        }
        printf(" %d\n", 8 - i);
        printf("  +-----------------+\n");
    }

    printf("   a b c d e f g h\n\n");
}

int main() {
    struct Board *board = (struct Board*) malloc(sizeof(struct Board));
    initializeBoard(board);
    printBoard(board);
    return 0;
}