//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) board[i][j] = WHITE; // White Pawns
            else if (i == 6) board[i][j] = BLACK; // Black Pawns
            else board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endY < 0 || endX >= BOARD_SIZE || endY >= BOARD_SIZE) 
        return false; // Move out of bounds

    if (board[endX][endY] != ' ' && board[endX][endY] == player) 
        return false; // Occupied by own piece

    int direction = (player == WHITE) ? 1 : -1; // Determine move direction

    // For simplicity, pawns only move one step forward and capture diagonally
    if (startY == endY) {
        if (endX - startX == direction && board[endX][endY] == ' ') return true; // Move forward
    } else if (abs(startY - endY) == 1 && endX - startX == direction) {
        if (board[endX][endY] != ' ') return true; // Capture diagonally
    }

    return false; // Invalid move
}

void makeMove(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = ' ';
}

int main() {
    initializeBoard();
    printBoard();

    char player = WHITE;
    char input[5];
    int startX, startY, endX, endY;

    while (true) {
        printf("%c's turn. Enter move (e.g., e2 e4): ", player);
        fgets(input, sizeof(input), stdin);
        
        // Convert algebraic notation to indices
        startX = 8 - (input[1] - '0');
        startY = input[0] - 'a';
        endX = 8 - (input[4] - '0');
        endY = input[3] - 'a';

        if (isValidMove(startX, startY, endX, endY, player)) {
            makeMove(startX, startY, endX, endY);
            printBoard();
            player = (player == WHITE) ? BLACK : WHITE; // Switch turns
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;
}