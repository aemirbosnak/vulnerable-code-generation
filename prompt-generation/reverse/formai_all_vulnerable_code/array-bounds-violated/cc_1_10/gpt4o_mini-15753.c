//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Board representation
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = 'B';  // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R';  // Red pieces
                } else {
                    board[i][j] = ' ';  // Empty squares
                }
            } else {
                board[i][j] = ' ';  // Empty squares
            }
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a piece can move
int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    if (board[endX][endY] != ' ') {
        return 0; // Destination not empty
    }
    int direction = (player == 'R') ? -1 : 1; // direction of movement for each color
    if (startX + direction == endX && (startY + 1 == endY || startY - 1 == endY)) {
        return 1; // Regular move
    }
    return 0; // Invalid move
}

// Function to move a piece
void movePiece(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = ' ';
}

// Function to get the player's input
void getPlayerInput(char player, int *startX, int *startY, int *endX, int *endY) {
    char startCol, endCol;
    int startRow, endRow;
    printf("Player %c, enter your move (e.g., A3 B4): ", player);
    scanf(" %c%d %c%d", &startCol, &startRow, &endCol, &endRow);
    *startX = startRow - 1; // Convert to 0-based index
    *startY = startCol - 'A'; // Convert to 0-based index
    *endX = endRow - 1; // Convert to 0-based index
    *endY = endCol - 'A'; // Convert to 0-based index
}

// Main game loop
int main() {
    initializeBoard();
    char currentPlayer = 'R'; // Start with player Red
    int startX, startY, endX, endY;
    
    while (1) {
        displayBoard();
        getPlayerInput(currentPlayer, &startX, &startY, &endX, &endY);
      
        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            movePiece(startX, startY, endX, endY); // Move the piece
            currentPlayer = (currentPlayer == 'R') ? 'B' : 'R'; // Switch players
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
    return 0;
}