//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8 // Board size
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[SIZE][SIZE];
// Initialize the game board with players' pieces
void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (i < 3 && (i + j) % 2 != 0)
                board[i][j] = PLAYER1; // Player 1 pieces
            else if (i > 4 && (i + j) % 2 != 0)
                board[i][j] = PLAYER2; // Player 2 pieces
            else
                board[i][j] = EMPTY; // Empty space
}

// Prints the current state of the board
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

// Check if the move is valid
int isValidMove(int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE)
        return 0; // Out of bounds
    if (board[endX][endY] != EMPTY)
        return 0; // Target not empty
    if (player == PLAYER1) {
        return (endX == startX + 1 && abs(endY - startY) == 1); // Regular move
    } else {
        return (endX == startX - 1 && abs(endY - startY) == 1); // Regular move
    }
}

// Move a piece from one position to another
void movePiece(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY]; // Move piece
    board[startX][startY] = EMPTY; // Empty the original spot
}

// Main game logic
void playGame() {
    int currentPlayer = 1; // Start with player 1
    char playerSymbol;
    int startX, startY, endX, endY;
    char startCol, endCol;

    while (1) {
        printBoard();
        playerSymbol = (currentPlayer == 1) ? PLAYER1 : PLAYER2;
        printf("Player %d (%c), enter your move (e.g., A1 B2): ", currentPlayer, playerSymbol);
        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);
        
        startY = startCol - 'A';
        endY = endCol - 'A';
        startX -= 1;
        endX -= 1;

        if (!isValidMove(startX, startY, endX, endY, playerSymbol)) {
            printf("Invalid move, try again.\n");
            continue;
        }
        
        movePiece(startX, startY, endX, endY);
        currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch players
    } 
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}