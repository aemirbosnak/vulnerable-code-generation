//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 1) {
                board[i][j] = PLAYER1;
            } else if (i > 4 && (i + j) % 2 == 1) {
                board[i][j] = PLAYER2;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endY < 0 || endX >= SIZE || endY >= SIZE || board[endX][endY] != EMPTY) {
        return 0; // Out of bounds or not empty
    }

    int direction = (player == PLAYER1) ? 1 : -1; // Player 1 moves down, Player 2 moves up

    return (endX - startX == direction && abs(endY - startY) == 1) || 
           (endX - startX == direction * 2 && abs(endY - startY) == 2); // Normal or jumping
}

void movePiece(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = EMPTY;

    // Check for jump
    if (abs(endX - startX) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        board[midX][midY] = EMPTY; // Remove the jumped piece
    }
}

int playGame() {
    char currentPlayer = PLAYER1;
    int startX, startY, endX, endY;

    while (1) {
        printBoard();
        printf("Player %c's turn. Enter move (startX startY endX endY): ", currentPlayer);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            movePiece(startX, startY, endX, endY);
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1; // Switch player
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}