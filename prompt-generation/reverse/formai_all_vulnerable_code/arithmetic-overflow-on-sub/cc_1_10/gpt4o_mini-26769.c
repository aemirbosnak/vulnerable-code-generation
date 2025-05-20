//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'
#define SIZE 8

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = PLAYER1; // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = PLAYER2; // Player 2 pieces
                } else {
                    board[i][j] = EMPTY; 
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n  +");
    for (int i = 0; i < SIZE; i++) {
        printf("-+");
    }
    printf("\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n  +");
        for (int j = 0; j < SIZE; j++) {
            printf("-+");
        }
        printf("\n");
    }
}

int validMove(char board[SIZE][SIZE], int startX, int startY, int endX, int endY, char player) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE)
        return 0; // Out of bounds
    if (board[endX][endY] != EMPTY)
        return 0; // Destination not empty
    if ((player == PLAYER1 && endX <= startX) || (player == PLAYER2 && endX >= startX))
        return 0; // Wrong direction for the player
    if (abs(endX - startX) != 1 || abs(endY - startY) != 1)
        return 0; // Move not diagonal

    // Check for capturing opponent's piece
    if (abs(endX - startX) == 2 && abs(endY - startY) == 2) {
        int captureX = (startX + endX) / 2;
        int captureY = (startY + endY) / 2;
        if (board[captureX][captureY] != EMPTY && board[captureX][captureY] != player)
            return 1; // Valid capture
        return 0; // Invalid capture
    }
    return 1; // Valid normal move
}

void movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    char player = board[startX][startY];
    board[endX][endY] = player; // Move the piece
    board[startX][startY] = EMPTY; // Empty the starting position
    
    // Check for captures
    if (abs(endX - startX) == 2 && abs(endY - startY) == 2) {
        int captureX = (startX + endX) / 2;
        int captureY = (startY + endY) / 2;
        board[captureX][captureY] = EMPTY; // Remove captured piece
    }
}

int main() {
    char board[SIZE][SIZE];
    int startX, startY, endX, endY;
    char currentPlayer = PLAYER1;
    initializeBoard(board);

    while (1) {
        printBoard(board);
        printf("Player %c, enter your move (startX startY endX endY): ", currentPlayer);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (validMove(board, startX, startY, endX, endY, currentPlayer)) {
            movePiece(board, startX, startY, endX, endY);
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1; // Switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}