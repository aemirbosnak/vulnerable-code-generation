//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

// Function to initialize the game board
void initializeBoard() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3)
                    board[i][j] = 'b'; // black pieces
                else if (i > 4)
                    board[i][j] = 'r'; // red pieces
                else
                    board[i][j] = '.';
            } else {
                board[i][j] = '.';
            }
        }
    }
}

// Function to print the board
void printBoard() {
    printf("  a b c d e f g h\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return 0; // move out of bounds
    }
    if (board[endX][endY] != '.') {
        return 0; // target square must be empty
    }
    
    if (player == 'r') {
        if (startX - endX == 1 && abs(startY - endY) == 1) {
            return 1; // valid simple move for red
        }
        if (startX - endX == 2 && abs(startY - endY) == 2 && 
            board[(startX + endX) / 2][(startY + endY) / 2] == 'b') {
            return 1; // valid capture move for red
        }
    } else if (player == 'b') {
        if (endX - startX == 1 && abs(startY - endY) == 1) {
            return 1; // valid simple move for black
        }
        if (endX - startX == 2 && abs(startY - endY) == 2 && 
            board[(startX + endX) / 2][(startY + endY) / 2] == 'r') {
            return 1; // valid capture move for black
        }
    }
    
    return 0; // move is invalid
}

// Function for the current player to make a move
void makeMove(int startX, int startY, int endX, int endY, char player) {
    board[endX][endY] = board[startX][startY]; // move piece
    board[startX][startY] = '.'; // empty the original spot
    
    // Check for capture
    if (abs(startX - endX) == 2) {
        int capturedX = (startX + endX) / 2;
        int capturedY = (startY + endY) / 2;
        board[capturedX][capturedY] = '.'; // remove captured piece
    }
}

// Game loop
void playGame() {
    char player = 'r'; // Start with red
    int startX, startY, endX, endY;
    while (1) {
        printBoard();
        printf("Player %c's turn. Enter your move (e.g., 'a3 b4'): ", player);
        
        char startCol, endCol;
        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);
        
        startY = startCol - 'a';
        endY = endCol - 'a';
        startX--; // Adjust to zero-indexing
        endX--;

        if (isValidMove(startX, startY, endX, endY, player)) {
            makeMove(startX, startY, endX, endY, player);
            player = (player == 'r') ? 'b' : 'r'; // Switch player
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}