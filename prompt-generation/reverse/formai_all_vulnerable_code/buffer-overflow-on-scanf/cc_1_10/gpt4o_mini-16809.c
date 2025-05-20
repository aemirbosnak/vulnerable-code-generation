//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];
char player1 = 'X', player2 = 'O';
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) { // Checkerboard pattern
                if (i < 3) {
                    board[i][j] = player1; // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = player2; // Player 2 pieces
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' '; // Empty squares
            }
        }
    }
}

void printBoard() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int srcRow, int srcCol, int destRow, int destCol) {
    if (srcRow < 0 || srcRow >= SIZE || srcCol < 0 || srcCol >= SIZE ||
        destRow < 0 || destRow >= SIZE || destCol < 0 || destCol >= SIZE) {
        return 0; // Out of bounds
    }
    if (board[srcRow][srcCol] != currentPlayer || board[destRow][destCol] != ' ') {
        return 0; // Invalid piece or destination not empty
    }
    
    int rowDiff = destRow - srcRow;
    int colDiff = destCol - srcCol;
    if (abs(rowDiff) == 1 && abs(colDiff) == 1) {
        return 1; // Regular move
    } else if (abs(rowDiff) == 2 && abs(colDiff) == 2) {
        // Capture move, assume valid capture piece
        int midRow = (srcRow + destRow) / 2;
        int midCol = (srcCol + destCol) / 2;
        if (board[midRow][midCol] != ' ' && board[midRow][midCol] != currentPlayer) {
            return 1; // Valid capture
        }
    }
    return 0; // Invalid move
}

void makeMove(int srcRow, int srcCol, int destRow, int destCol) {
    board[destRow][destCol] = currentPlayer; // Move piece
    board[srcRow][srcCol] = ' '; // Empty the source
    if (abs(destRow - srcRow) == 2) {
        // Capture move, remove the captured piece
        int midRow = (srcRow + destRow) / 2;
        int midCol = (srcCol + destCol) / 2;
        board[midRow][midCol] = ' '; // Remove captured piece
    }
}

void switchPlayer() {
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

int main() {
    initializeBoard();
    currentPlayer = player1;

    while (1) {
        printBoard();
        printf("Player %c's turn. Enter move (e.g., A3 B4): ", currentPlayer);
        
        char src[3], dest[3];
        scanf("%s %s", src, dest); // Read source and destination

        int srcRow = src[1] - '1';
        int srcCol = src[0] - 'A';
        int destRow = dest[1] - '1';
        int destCol = dest[0] - 'A';

        if (isValidMove(srcRow, srcCol, destRow, destCol)) {
            makeMove(srcRow, srcCol, destRow, destCol);
            switchPlayer();
        } else {
            printf("Invalid move. Try again.\n");
        }

        // Check for winning conditions... (not implemented for brevity)
    }
    return 0;
}