//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the board
void printBoard(int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == -1) {
                printf("  -  ");
            } else {
                printf("  %d  ", board[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if a player has won
int checkWin(int board[3][3], int player) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    // No winner
    return 0;
}

int main() {
    // Initialize the board with -1 to represent empty spaces
    int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

    // Keep track of the current player
    int currentPlayer = 1;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");
    printf("Player 1 is X and Player 2 is O.\n");
    printf("The board is a 3x3 grid. To make a move, enter the row and column numbers.\n");
    printf("Let's begin!\n");

    // Main game loop
    while(1) {
        // Print the board
        printBoard(board);

        // Ask the current player for their move
        int row, col;
        printf("Player %d, enter your move (row, column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if(board[row-1][col-1] != -1) {
            printf("That space is already taken. Try again.\n");
            continue;
        }

        // Make the move
        board[row-1][col-1] = currentPlayer;

        // Check if the current player has won
        if(checkWin(board, currentPlayer)) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        // Check for a tie
        int tie = 1;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == -1) {
                    tie = 0;
                    break;
                }
            }
        }
        if(tie) {
            printf("It's a tie!\n");
            break;
        }

        // Switch to the other player
        if(currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }

    return 0;
}