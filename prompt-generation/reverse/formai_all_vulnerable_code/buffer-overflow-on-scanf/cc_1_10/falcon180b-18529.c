//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define PIECE_EMPTY 0
#define PIECE_BLACK -1
#define PIECE_WHITE 1

typedef struct {
    int piece;
    int x;
    int y;
} Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].piece = PIECE_EMPTY;
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
}

int isLegalMove(int fromX, int fromY, int toX, int toY) {
    if (fromX < 0 || fromX >= BOARD_SIZE || fromY < 0 || fromY >= BOARD_SIZE ||
        toX < 0 || toX >= BOARD_SIZE || toY < 0 || toY >= BOARD_SIZE) {
        return 0;
    }

    if (board[fromX][fromY].piece!= PIECE_EMPTY) {
        return 0;
    }

    if (board[toX][toY].piece!= PIECE_EMPTY) {
        return 0;
    }

    return 1;
}

void movePiece(int fromX, int fromY, int toX, int toY) {
    board[toX][toY].piece = board[fromX][fromY].piece;
    board[toX][toY].x = toX;
    board[toX][toY].y = toY;
    board[fromX][fromY].piece = PIECE_EMPTY;
}

int getPiece(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return PIECE_EMPTY;
    }
    return board[x][y].piece;
}

void printBoard() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].piece == PIECE_BLACK) {
                printf("B");
            } else if (board[i][j].piece == PIECE_WHITE) {
                printf("W");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initBoard();

    int player = PIECE_WHITE;
    int x = 0, y = 0;

    while (1) {
        printBoard();
        printf("Player %d's turn.\n", player + 1);
        scanf("%d%d", &x, &y);
        if (!isLegalMove(x, y, x, y)) {
            printf("Invalid move.\n");
            continue;
        }
        movePiece(x, y, x, y);
        player =!player;
        if (checkmate(player)) {
            printf("Checkmate!\n");
            break;
        }
    }

    return 0;
}

int checkmate(int player) {
    // TODO: Implement checkmate detection
    return 0;
}