//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

// Function to initialize the board
void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = 'B'; // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R'; // Red pieces
                } else {
                    board[i][j] = '.'; // Empty space
                }
            } else {
                board[i][j] = ' '; // Non-playable squares
            }
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a piece
int movePiece(int startX, int startY, int endX, int endY, char player) {
    if (board[startX][startY] != player) {
        printf("You cannot move a piece that is not yours!\n");
        return 0;
    }
    
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE || board[endX][endY] != '.') {
        printf("Invalid move!\n");
        return 0;
    }

    // Move the piece to the destination
    board[endX][endY] = player;
    board[startX][startY] = '.';
    return 1;
}

// Function to command a player turn
void playerTurn(char player) {
    char startCol, endCol;
    int startRow, endRow;

    printf("Player %c, enter your move (e.g., A3 B4): ", player);
    scanf(" %c%d %c%d", &startCol, &startRow, &endCol, &endRow);

    int startX = startRow - 1;
    int startY = startCol - 'A';
    int endX = endRow - 1;
    int endY = endCol - 'A';

    if (movePiece(startX, startY, endX, endY, player)) {
        displayBoard();
    }
}

int main() {
    initBoard();
    displayBoard();
    char currentPlayer = 'R';

    while (1) {
        playerTurn(currentPlayer);
        currentPlayer = (currentPlayer == 'R') ? 'B' : 'R'; // Switch player
    }

    return 0;
}