//FormAI DATASET v1.0 Category: Chess engine ; Style: scalable
// A unique C Chess engine example program 
// Featuring a scalable game loop style

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define WHITE_PAWN 'P'
#define WHITE_ROOK 'R'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define BLACK_ROOK 'r'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    // Clear the board
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            board[x][y] = '.';
        }
    }
    // Place white pieces
    board[0][0] = WHITE_ROOK;
    board[0][1] = WHITE_KNIGHT;
    board[0][2] = WHITE_BISHOP;
    board[0][3] = WHITE_QUEEN;
    board[0][4] = WHITE_KING;
    board[0][5] = WHITE_BISHOP;
    board[0][6] = WHITE_KNIGHT;
    board[0][7] = WHITE_ROOK;
    for (int x = 0; x < BOARD_SIZE; x++) {
        board[1][x] = WHITE_PAWN;
    }
    // Place black pieces
    board[7][0] = BLACK_ROOK;
    board[7][1] = BLACK_KNIGHT;
    board[7][2] = BLACK_BISHOP;
    board[7][3] = BLACK_QUEEN;
    board[7][4] = BLACK_KING;
    board[7][5] = BLACK_BISHOP;
    board[7][6] = BLACK_KNIGHT;
    board[7][7] = BLACK_ROOK;
    for (int x = 0; x < BOARD_SIZE; x++) {
        board[6][x] = BLACK_PAWN;
    }
}

void printBoard() {
    for (int y = BOARD_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }
}

void gameLoop() {
    while (1) {
        printf("Enter your move: ");
        char fromX = getchar();
        char fromY = getchar();
        char toX = getchar();
        char toY = getchar();
        printf("\n");
        // Convert characters to board indices
        int fromXIndex = fromX - 'a';
        int fromYIndex = fromY - '1';
        int toXIndex = toX - 'a';
        int toYIndex = toY - '1';
        // Move piece if valid
        if (board[fromXIndex][fromYIndex] != '.') {
            char piece = board[fromXIndex][fromYIndex];
            board[fromXIndex][fromYIndex] = '.';
            board[toXIndex][toYIndex] = piece;
        } else {
            printf("Invalid move\n");
        }
        // Print board
        printBoard();
        printf("\n");
    }
}

int main() {
    initializeBoard();
    printBoard();
    printf("\n");
    gameLoop();
    return 0;
}