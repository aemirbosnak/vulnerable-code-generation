//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8
#define PIECES 16

enum { WHITE, BLACK, EMPTY };

struct Piece {
    int color;
    int type;
    int row;
    int col;
};

struct Board {
    int pieces[ROWS][COLS];
};

void initBoard(struct Board* board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board->pieces[i][j] = EMPTY;
        }
    }
}

void printBoard(struct Board* board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board->pieces[i][j] == WHITE) {
                printf("W ");
            } else if (board->pieces[i][j] == BLACK) {
                printf("B ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int isValidMove(struct Board* board, int fromRow, int fromCol, int toRow, int toCol) {
    int deltaRow = toRow - fromRow;
    int deltaCol = toCol - fromCol;

    if (deltaRow == 0 && deltaCol == 0) {
        return 0;
    }

    if (deltaRow == 0) {
        return (toCol > fromCol)? 1 : -1;
    }

    if (deltaCol == 0) {
        return (toRow > fromRow)? 1 : -1;
    }

    return 0;
}

int main() {
    struct Board board;
    initBoard(&board);

    int moves = 0;
    while (moves < PIECES) {
        printBoard(&board);
        int fromRow, fromCol, toRow, toCol;
        printf("Enter move from (row,col) to (row,col): ");
        scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);

        if (isValidMove(&board, fromRow, fromCol, toRow, toCol)) {
            board.pieces[toRow][toCol] = board.pieces[fromRow][fromCol];
            board.pieces[fromRow][fromCol] = EMPTY;
            moves++;
        }
    }

    return 0;
}