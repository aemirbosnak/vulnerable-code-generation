//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY ' '
#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard() {
    char initialBoard[SIZE][SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = initialBoard[i][j];
        }
    }
}

void printBoard() {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return false;
    }
    if (board[startX][startY] == EMPTY) {
        return false;
    }
    if (board[endX][endY] != EMPTY) {
        return false; // Simple rule: can't move to occupied square
    }
    return true;
}

void makeMove(int startX, int startY, int endX, int endY) {
    if (isValidMove(startX, startY, endX, endY)) {
        board[endX][endY] = board[startX][startY];
        board[startX][startY] = EMPTY;
    } else {
        printf("Invalid move!\n");
    }
}

bool isGameOver() {
    bool whiteKing = false, blackKing = false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'K') whiteKing = true;
            if (board[i][j] == 'k') blackKing = true;
        }
    }
    return !(whiteKing && blackKing);
}

void playGame() {
    char from[3], to[3];
    int startX, startY, endX, endY;
    while (!isGameOver()) {
        printBoard();
        printf("Enter your move (e.g., e2 e4): ");
        scanf("%s %s", from, to);
        startX = SIZE - (from[1] - '0');
        startY = from[0] - 'a';
        endX = SIZE - (to[1] - '0');
        endY = to[0] - 'a';
        makeMove(startX, startY, endX, endY);
    }
    printf("Game over! Thank you for playing.\n");
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}