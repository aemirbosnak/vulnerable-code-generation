//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Board representation
char board[BOARD_SIZE][BOARD_SIZE];

// Check if a move is valid
int validMove(char player, int row, int col, int newRow, int newCol) {
    int i, j;
    // Check if new position is a valid position on the board
    if ((newRow < 0) || (newRow > 7) || (newCol < 0) || (newCol > 7)) {
        return 0;
    }
    // Check if new position is empty
    if (board[newRow][newCol] != '-') {
        return 0;
    }
    // Check if player is moving their own piece
    if (player == 'B') {
        if (board[row][col] == 'w' || board[row][col] == 'W') {
            return 0;
        }
        // Check if move is diagonal
        if (!((newRow == row + 1 || newRow == row - 1) && 
            (newCol == col + 1 || newCol == col - 1))) {
                // Check if move is a jump
                if (!((newRow == row + 2 || newRow == row - 2) && 
                    (newCol == col + 2 || newCol == col - 2))) {
                    return 0;
                }
                // Check if player is jumping opponent's piece
                if (board[(row + newRow)/2][(col + newCol)/2] != 'w' && 
                    board[(row + newRow)/2][(col + newCol)/2] != 'W') {
                    return 0;
                }
        }
    } else if (player == 'W') {
        if (board[row][col] == 'b' || board[row][col] == 'B') {
            return 0;
        }
        // Check if move is diagonal
        if (!((newRow == row + 1 || newRow == row - 1) && 
            (newCol == col + 1 || newCol == col - 1))) {
                // Check if move is a jump
                if (!((newRow == row + 2 || newRow == row - 2) && 
                    (newCol == col + 2 || newCol == col - 2))) {
                    return 0;
                }
                // Check if player is jumping opponent's piece
                if (board[(row + newRow)/2][(col + newCol)/2] != 'b' && 
                    board[(row + newRow)/2][(col + newCol)/2] != 'B') {
                    return 0;
                }
        }
    } else {
        return 0;
    }
    return 1;
}

// Make a move on the board
void makeMove(char player, int row, int col, int newRow, int newCol) {
    // Update board with new position of piece
    board[newRow][newCol] = board[row][col];
    board[row][col] = '-';
    // Check if piece has reached opponent's end of board
    if ((newRow == 0 && player == 'B') || (newRow == 7 && player == 'W')) {
        if (board[newRow][newCol] == 'b' || board[newRow][newCol] == 'w') {
            board[newRow][newCol] = (player == 'B') ? 'B' : 'W';
        }
    }
    // Check if move was a jump
    if (((newRow == row + 2) || (newRow == row - 2)) && 
        ((newCol == col + 2) || (newCol == col - 2))) {
            // Remove opponent's piece from board
            board[(row + newRow)/2][(col + newCol)/2] = '-';
    }
}

// Print the board on the console
void printBoard() {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    // Initialize board with starting position of pieces
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = 'b';
                } else if (i > 4) {
                    board[i][j] = 'w';
                } else {
                    board[i][j] = '-';
                }
            } else {
                board[i][j] = '-';
            }
        }
    }
    char player = 'B';
    int row, col, newRow, newCol;
    int moveValid;
    while (1) {
        printBoard();
        printf("%c's turn.\n", player);
        printf("Enter row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);
        printf("Enter row and column of the position you want to move to: ");
        scanf("%d %d", &newRow, &newCol);
        moveValid = validMove(player, row, col, newRow, newCol);
        if (moveValid) {
            makeMove(player, row, col, newRow, newCol);
            // Switch to the other player
            player = (player == 'B') ? 'W' : 'B';
        } else {
            printf("That move is invalid. Please try again.\n");
        }
    }
    return 0;
}