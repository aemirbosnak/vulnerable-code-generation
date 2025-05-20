//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Defining constants
#define SIZE 8
#define RED 'R'
#define BLACK 'B'
#define EMPTY ' '

// Function to initialize the board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = BLACK;
                } else if (i > 4) {
                    board[i][j] = RED;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Function to print the board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a piece
int movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    if (board[startX][startY] == EMPTY || board[endX][endY] != EMPTY) {
        return 0; // Invalid move
    }
    
    int piece = board[startX][startY];
    // Move the piece
    board[endX][endY] = piece;
    board[startX][startY] = EMPTY;
    
    // Check for capturing
    if (abs(endX - startX) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        board[midX][midY] = EMPTY; // Remove the captured piece
    }
    return 1; // Move successful
}

// Main game loop
int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    
    int playerTurn = 0; // 0 for RED, 1 for BLACK
    char playerPieces[2] = {RED, BLACK};
    
    while (1) {
        printBoard(board);
        printf("Player %d (%c) Turn: Enter your move (e.g., A1 B2): ", playerTurn + 1, playerPieces[playerTurn]);
        
        char start[3], end[3];
        scanf("%s %s", start, end);
        
        int startX = start[1] - '1';
        int startY = start[0] - 'A';
        int endX = end[1] - '1';
        int endY = end[0] - 'A';
        
        printf("\nMoving: %c from %s to %s...\n", playerPieces[playerTurn], start, end);
        
        // Validating input
        if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE || 
            endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Attempt to move
        if (movePiece(board, startX, startY, endX, endY)) {
            playerTurn = (playerTurn + 1) % 2; // Change turn
            printf("Move successful!\n");
        } else {
            printf("Move failed! Try again.\n");
        }
    }
    
    return 0;
}