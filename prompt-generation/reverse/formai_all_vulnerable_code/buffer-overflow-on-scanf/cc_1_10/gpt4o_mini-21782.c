//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Function Declarations
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int isValidMove(char piece, int startX, int startY, int endX, int endY, char board[BOARD_SIZE][BOARD_SIZE]);
void movePiece(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY);
int isInBounds(int x, int y);
int isGameOver(char board[BOARD_SIZE][BOARD_SIZE], char player);

// Main Function
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer = 'W'; // 'W' for White, 'B' for Black
    int startX, startY, endX, endY;
    int gameEnded = 0;

    initializeBoard(board);

    while (!gameEnded) {
        printBoard(board);
        printf("Current Player: %c\n", currentPlayer);
        printf("Enter move (startX startY endX endY): ");
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (isValidMove(board[startX][startY], startX, startY, endX, endY, board)) {
            movePiece(board, startX, startY, endX, endY);
            gameEnded = isGameOver(board, currentPlayer);
            currentPlayer = (currentPlayer == 'W') ? 'B' : 'W'; // Switch players
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    printBoard(board);
    printf("Game Over\n");
    return 0;
}

// Initializes the chess board with pieces
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    const char *initialRow[] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        strncpy(board[i], initialRow[i], BOARD_SIZE);
    }
}

// Prints the current state of the chess board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if a move is valid for the given piece
int isValidMove(char piece, int startX, int startY, int endX, int endY, char board[BOARD_SIZE][BOARD_SIZE]) {
    if (!isInBounds(startX, startY) || !isInBounds(endX, endY)) return 0;
    char targetPiece = board[endX][endY];
    if ((piece >= 'A' && piece <= 'Z' && targetPiece >= 'A' && targetPiece <= 'Z') || 
        (piece >= 'a' && piece <= 'z' && targetPiece >= 'a' && targetPiece <= 'z')) {
        return 0; // Can't capture own piece
    }
    return 1; // Simplified validation
}

// Moves a piece on the board
void movePiece(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '.';
}

// Checks if the coordinates are within board bounds
int isInBounds(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

// Checks if the game is over (currently simplified)
int isGameOver(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // A basic check to end the game if a king is missing from the board for either player
    // Note: This is a placeholder, real game over logic is more complex
    int whiteKing = 0, blackKing = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'K') whiteKing = 1;
            if (board[i][j] == 'k') blackKing = 1;
        }
    }
    return !(whiteKing && blackKing);
}