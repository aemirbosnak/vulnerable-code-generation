//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = PLAYER1; // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = PLAYER2; // Player 2 pieces
                } else {
                    board[i][j] = EMPTY;     // Empty spaces
                }
            } else {
                board[i][j] = EMPTY;         // Empty spaces
            }
        }
    }
}

void printBoard() {
    printf("  A B C D E F G H\n");
    printf(" +----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n +----------------\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE ||
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    
    if (board[endX][endY] != EMPTY) {
        return 0; // Destination not empty
    }

    int direction = (player == PLAYER1) ? 1 : -1;
    if (endX - startX == direction && abs(endY - startY) == 1) {
        return 1; // Normal move
    }
  
    if (endX - startX == direction * 2 && abs(endY - startY) == 2) {
        int middleX = (startX + endX) / 2;
        int middleY = (startY + endY) / 2;
        if (board[middleX][middleY] != EMPTY && 
            board[middleX][middleY] != player) {
            return 1; // Capture move
        }
    }

    return 0; // Invalid move
}

void makeMove(int startX, int startY, int endX, int endY, char player) {
    board[endX][endY] = board[startX][startY]; // Move the piece
    board[startX][startY] = EMPTY; // Free the previous spot
    if (abs(endX - startX) == 2) { // If it was a capture
        int middleX = (startX + endX) / 2;
        int middleY = (startY + endY) / 2;
        board[middleX][middleY] = EMPTY; // Remove the captured piece
    }
}

int main() {
    initializeBoard();
    char currentPlayer = PLAYER1;
    int startX, startY, endX, endY;
    char colStart, colEnd;
    
    while (1) {
        printBoard();
        printf("Player %c's turn (e.g., A3 B4): ", currentPlayer);
        scanf(" %c%d %c%d", &colStart, &startX, &colEnd, &endX);
        
        startX -= 1; endX -= 1; // Adjust for 0-based index
        int startY = colStart - 'A';
        int endY = colEnd - 'A';

        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            makeMove(startX, startY, endX, endY, currentPlayer);
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1; // Switch turns
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}