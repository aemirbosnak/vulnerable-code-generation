//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define WHITE 'O'
#define BLACK 'X'
#define EMPTY '.'

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int isMoveValid(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY, char player);
int movePiece(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY);
int checkVictory(char board[SIZE][SIZE], char player);
int isKingRow(char player);
void makeKing(char board[SIZE][SIZE], int x, int y, char player);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    
    char currentPlayer = WHITE;
    int gameActive = 1;
    
    while (gameActive) {
        printBoard(board);
        int srcX, srcY, destX, destY;
        
        printf("Current Player: %c\n", currentPlayer);
        printf("Enter move (srcX srcY destX destY): ");
        scanf("%d %d %d %d", &srcX, &srcY, &destX, &destY);

        if (isMoveValid(board, srcX, srcY, destX, destY, currentPlayer)) {
            movePiece(board, srcX, srcY, destX, destY);
            makeKing(board, destX, destY, currentPlayer);
            if (checkVictory(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                gameActive = 0;
            }
            currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = EMPTY; // Only dark squares can hold pieces
            } else {
                if (i < 3) board[i][j] = BLACK; // Black player's pieces
                else if (i > 4) board[i][j] = WHITE; // White player's pieces
                else board[i][j] = EMPTY; // Empty field
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isMoveValid(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY, char player) {
    // Simple bounds and type checking
    if (srcX < 0 || srcY < 0 || destX < 0 || destY < 0 || 
        srcX >= SIZE || srcY >= SIZE || destX >= SIZE || destY >= SIZE) return 0;
    
    if (board[srcX][srcY] != player) return 0; // Must be player's piece
    if (board[destX][destY] != EMPTY) return 0; // Destination must be empty

    // Diagonal move
    if (abs(srcX - destX) == 1 && abs(srcY - destY) == 1) return 1;

    // For jumps
    if (abs(srcX - destX) == 2 && abs(srcY - destY) == 2) {
        int capturedX = (srcX + destX) / 2;
        int capturedY = (srcY + destY) / 2;
        if (board[capturedX][capturedY] != EMPTY && board[capturedX][capturedY] != player) {
            return 1; // Valid jump
        }
    }
    return 0; // Invalid move
}

int movePiece(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY) {
    board[destX][destY] = board[srcX][srcY]; // Move piece
    board[srcX][srcY] = EMPTY; // Empty src position

    // Remove captured piece if jumped
    if (abs(srcX - destX) == 2 && abs(srcY - destY) == 2) {
        int capturedX = (srcX + destX) / 2;
        int capturedY = (srcY + destY) / 2;
        board[capturedX][capturedY] = EMPTY;
    }
    return 1; // Move successful
}

int checkVictory(char board[SIZE][SIZE], char player) {
    char opponent = (player == WHITE) ? BLACK : WHITE;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == opponent) return 0; // Opponent still has pieces
        }
    }
    return 1; // Victory condition met
}

void makeKing(char board[SIZE][SIZE], int x, int y, char player) {
    if (player == WHITE && x == 0) {
        board[x][y] = 'K'; // Promote to king
    } else if (player == BLACK && x == SIZE - 1) {
        board[x][y] = 'K'; // Promote to king
    }
}