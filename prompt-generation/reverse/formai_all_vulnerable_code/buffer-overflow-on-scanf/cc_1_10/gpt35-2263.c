//FormAI DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Definitions of the board, pieces, and player colors
#define BOARD_SIZE 8
#define RED 'R'
#define BLACK 'B'

// Function to print the initial board setup
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("    ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d   ", i+1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("%d | ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
}

// Function to initialize the board with pieces in starting positions
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i <= 2 && (i+j) % 2 == 0) {
                board[i][j] = BLACK;
            } else if (i >= 5 && (i+j) % 2 == 0) {
                board[i][j] = RED;
            } else {
                board[i][j] = '-';
            }
        }
    }
}

int main() {
    // Variables to keep track of the player turn and the board state
    int playerTurn = 1;
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    // Main game loop
    while (1) {
        printf("\nPlayer %d's turn\n", playerTurn);
        printBoard(board);

        // TODO: Implement game logic here

        // Prompt the player for their move
        int fromRow, fromCol, toRow, toCol;
        printf("Enter your move (row,column to row,column): ");
        scanf("%d,%d to %d,%d", &fromRow, &fromCol, &toRow, &toCol);

        // Validate the player's move
        if (fromRow < 1 || fromRow > BOARD_SIZE || fromCol < 1 || fromCol > BOARD_SIZE ||
            toRow < 1 || toRow > BOARD_SIZE || toCol < 1 || toCol > BOARD_SIZE) {
            printf("Invalid move: out of bounds\n");
            continue;
        }

        if (board[fromRow-1][fromCol-1] == '-' || board[toRow-1][toCol-1] != '-') {
            printf("Invalid move: not a valid piece or destination\n");
            continue;
        }

        // TODO: Implement movement logic here

        // Switch to the other player's turn
        playerTurn = playerTurn == 1 ? 2 : 1;
    }

    return 0;
}