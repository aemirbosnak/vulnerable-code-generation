//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY);
int isValidMove(char board[SIZE][SIZE], int startX, int startY, int endX, int endY);
void playGame();

int main() {
    printf("Welcome to the Happy Checkers Game! Let's have fun!\n");
    playGame();
    return 0;
}

void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);

    int startX, startY, endX, endY;
    char currentPlayer = 'X';

    while (1) {
        printf("Player %c, enter your move (startX startY endX endY): ", currentPlayer);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (movePiece(board, startX, startY, endX, endY)) {
            printBoard(board);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        } else {
            printf("Invalid move, try again!\n");
        }
    }
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = 'X'; // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = 'O'; // Player 2 pieces
                } else {
                    board[i][j] = '-'; // Empty squares
                }
            } else {
                board[i][j] = ' '; // Non-playable squares
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  A B C D E F G H\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +-----------------+\n");
    }
}

int movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    if (isValidMove(board, startX, startY, endX, endY)) {
        board[endX][endY] = board[startX][startY];
        board[startX][startY] = '-';
        return 1;
    }
    return 0;
}

int isValidMove(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE || 
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return 0; // Out of bounds
    }
    if (board[startX][startY] != 'X' && board[startX][startY] != 'O') {
        return 0; // No piece to move
    }
    if (board[endX][endY] != '-') {
        return 0; // Target square is not empty
    }
    if ((board[startX][startY] == 'X' && (endX <= startX || endX - startX != 1)) ||
        (board[startX][startY] == 'O' && (endX >= startX || startX - endX != 1))) {
        return 0; // Invalid movement direction
    }
    return 1; // Valid move
}