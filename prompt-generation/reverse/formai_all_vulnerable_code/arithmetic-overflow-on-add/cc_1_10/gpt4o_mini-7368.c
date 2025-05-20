//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>

#define SIZE 8

char board[SIZE][SIZE];
char player1 = 'X';
char player2 = 'O';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = player2; // Player 2 pieces
                } else if (i > 4) {
                    board[i][j] = player1; // Player 1 pieces
                } else {
                    board[i][j] = ' '; // Empty squares
                }
            } else {
                board[i][j] = ' '; // Empty squares
            }
        }
    }
}

void printBoard() {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY, char currentPlayer) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) return 0; // Out of bounds
    if (board[endX][endY] != ' ') return 0; // Target square not empty

    int direction = (currentPlayer == player1) ? -1 : 1; // Player 1 moves up, Player 2 down
    if (startX + direction == endX && (startY + 1 == endY || startY - 1 == endY)) {
        return 1; // Simple move
    }

    // Capture
    if (startX + 2 * direction == endX && (startY + 2 == endY || startY - 2 == endY)) {
        int midX = startX + direction;
        int midY = (startY + endY) / 2;
        if (board[midX][midY] != ' ' && board[midX][midY] != currentPlayer) {
            return 2; // Capture possible
        }
    }

    return 0; // Invalid move
}

void makeMove(int startX, int startY, int endX, int endY, char currentPlayer) {
    board[endX][endY] = currentPlayer;
    board[startX][startY] = ' ';
    if (isValidMove(startX, startY, endX, endY, currentPlayer) == 2) {
        // Capture occurred
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        board[midX][midY] = ' '; // Remove the captured piece
    }
}

int main() {
    initializeBoard();
    char currentPlayer = player1;
    int startX, startY, endX, endY;

    printf("Welcome to the Checkers Game!\n");
    printBoard();

    while (1) {
        printf("Player %c, enter your move (e.g., A3 B4): ", currentPlayer);
        char startCol, endCol;
        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);

        startY = startCol - 'A'; // Calculate column index
        endY = endCol - 'A'; // Calculate column index
        startX--; // Adjust to array index
        endX--;

        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            makeMove(startX, startY, endX, endY, currentPlayer);
            printBoard();
            currentPlayer = (currentPlayer == player1) ? player2 : player1; // Switch player
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }

    return 0;
}