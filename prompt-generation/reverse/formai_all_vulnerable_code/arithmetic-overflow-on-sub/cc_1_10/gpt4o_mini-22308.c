//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];
char player1 = 'X';
char player2 = 'O';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) { // Only fill the dark squares
                if (i < 3) {
                    board[i][j] = player1; // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = player2; // Player 2 pieces
                } else {
                    board[i][j] = '.'; // Empty squares
                }
            } else {
                board[i][j] = ' '; // Light squares
            }
        }
    }
}

void printBoard() {
    printf("   0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endY < 0 || endX >= SIZE || endY >= SIZE) return 0; // Out of bounds
    if (board[endX][endY] != '.') return 0; // Destination must be empty
    if ((player == player1 && startX - endX != 1) || (player == player2 && endX - startX != 1)) return 0; // Move must be diagonal
    if (abs(startY - endY) != 1) return 0; // Move must be diagonal

    // Check if capturing
    if (abs(startX - endX) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        if (board[midX][midY] == '.' || board[midX][midY] == player || (player == player1 && board[midX][midY] == player1) || (player == player2 && board[midX][midY] == player2)) {
            return 0; // Invalid capture
        }
    }
    return 1; // Valid move
}

void movePiece(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '.';
    // Handle capturing
    if (abs(startX - endX) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        board[midX][midY] = '.'; // Remove the captured piece
    }
}

int main() {
    initializeBoard();
    printBoard();

    char currentPlayer = player1;
    while (1) {
        int startX, startY, endX, endY;
        printf("Player %c, enter your move (startX startY endX endY): ", currentPlayer);
        scanf("%d%d%d%d", &startX, &startY, &endX, &endY);

        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            movePiece(startX, startY, endX, endY);
            printBoard();
            currentPlayer = (currentPlayer == player1) ? player2 : player1; // Switch players
        } else {
            printf("Invalid move! Try again.\n");
        }

        // Simple check for a win condition (you can expand on this)
    }

    return 0;
}