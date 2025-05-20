//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the board size
#define BOARD_SIZE 8

// Define the game board
int board[BOARD_SIZE][BOARD_SIZE];

// Function to print the game board
void printBoard() {
    printf("    a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %c %c %c %c %c %c %c %c\n", 'a' + i, 'b' + i, 'c' + i, 'd' + i, 'e' + i, 'f' + i, 'g' + i, 'h' + i);
    }
}

// Function to check if a move is legal
bool isLegalMove(int x, int y) {
    // Check if the move is in bounds and is empty
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == 0) {
        return true;
    }
    return false;
}

// Function to make a move
void makeMove(int x, int y, int player) {
    // Check if the move is legal
    if (!isLegalMove(x, y)) {
        printf("Invalid move!\n");
        return;
    }
    // Check if the move is a capture
    if (board[x][y]!= player && board[x][y]!= 0) {
        board[x][y] = player;
    } else {
        board[x][y] = player;
    }
    // Update the player's turn
    if (player == 1) {
        player = 2;
    } else {
        player = 1;
    }
    // Print the updated game board
    printBoard();
}

int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    // Start the game
    int player = 1;
    while (true) {
        // Prompt the player for a move
        printf("Player %d's turn:\n", player);
        int x, y;
        printf("Enter the coordinates of your move (x,y): ");
        scanf("%d %d", &x, &y);
        // Make the move
        makeMove(x, y, player);
    }
    return 0;
}