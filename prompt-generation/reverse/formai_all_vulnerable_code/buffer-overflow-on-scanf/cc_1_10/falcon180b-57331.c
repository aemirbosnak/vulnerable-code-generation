//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY = 0,
    WHITE = 1,
    BLACK = -1
} PieceColor;

typedef struct {
    int row;
    int col;
    PieceColor color;
} Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            board[row][col].color = EMPTY;
        }
    }
}

void printBoard() {
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col].color == WHITE) {
                printf("W ");
            } else if (board[row][col].color == BLACK) {
                printf("B ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int isLegalMove(int row, int col, PieceColor color) {
    int dx, dy;
    if (color == WHITE) {
        dx = 1;
        dy = 0;
    } else {
        dx = -1;
        dy = 0;
    }

    int x = row + dx;
    int y = col + dy;

    while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        if (board[x][y].color!= EMPTY) {
            return 0;
        }
        x += dx;
        y += dy;
    }

    return 1;
}

int getOppositeColor(PieceColor color) {
    if (color == WHITE) {
        return BLACK;
    } else {
        return WHITE;
    }
}

void makeMove(int row, int col, PieceColor color) {
    board[row][col].color = color;
}

int main() {
    srand(time(NULL));

    initBoard();

    int player = 1;
    while (1) {
        printBoard();
        int row, col;
        scanf("%d %d", &row, &col);
        row--; col--;

        if (board[row][col].color == EMPTY) {
            makeMove(row, col, player == 1? WHITE : BLACK);
            player =!player;
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}