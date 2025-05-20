//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define MAX_MOVES 128

typedef enum { EMPTY, WHITE_PAWN, BLACK_PAWN } Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard* cb) {
    memset(cb->board, EMPTY, sizeof(cb->board));
    for (int i = 0; i < BOARD_SIZE; i++) {
        cb->board[1][i] = WHITE_PAWN;
        cb->board[6][i] = BLACK_PAWN;
    }
}

void printBoard(const ChessBoard* cb) {
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        printf("%d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (cb->board[row][col]) {
                case WHITE_PAWN: printf("P "); break;
                case BLACK_PAWN: printf("p "); break;
                default: printf(". ");
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

bool isValidMove(int startX, int startY, int endX, int endY, Piece player, ChessBoard* cb) {
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return false;
    }
    if (cb->board[endX][endY] != EMPTY && (cb->board[endX][endY] == player)) {
        return false;
    }
    if (player == WHITE_PAWN) {
        return (startX + 1 == endX && startY == endY && cb->board[endX][endY] == EMPTY) ||
               (startX + 1 == endX && abs(startY - endY) == 1 && cb->board[endX][endY] == BLACK_PAWN);
    } else {
        return (startX - 1 == endX && startY == endY && cb->board[endX][endY] == EMPTY) ||
               (startX - 1 == endX && abs(startY - endY) == 1 && cb->board[endX][endY] == WHITE_PAWN);
    }
}

void makeMove(int startX, int startY, int endX, int endY, ChessBoard* cb) {
    cb->board[endX][endY] = cb->board[startX][startY];
    cb->board[startX][startY] = EMPTY;
}

void getMove(int* startX, int* startY, int* endX, int* endY) {
    char start[3], end[3];
    printf("Enter move (ex: e2 e4): ");
    scanf("%s %s", start, end);
    *startX = start[1] - '1';
    *startY = start[0] - 'a';
    *endX = end[1] - '1';
    *endY = end[0] - 'a';
}

void playChess() {
    ChessBoard cb;
    initializeBoard(&cb);
    Piece currentPlayer = WHITE_PAWN;

    while (true) {
        printBoard(&cb);
        int startX, startY, endX, endY;
        getMove(&startX, &startY, &endX, &endY);

        if (isValidMove(startX, startY, endX, endY, currentPlayer, &cb)) {
            makeMove(startX, startY, endX, endY, &cb);
            currentPlayer = (currentPlayer == WHITE_PAWN) ? BLACK_PAWN : WHITE_PAWN;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    playChess();
    return 0;
}