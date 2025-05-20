//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Variables
int board[3][3];
int currentPlayer = 0;
bool gameOver = false;

// Function to check if game is over
bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0) {
        return true;
    }

    return false;
}

// Function to get player's move
void getMove(int *player) {
    int row, col;

    printf("Player %d, enter row and column (0-2): ", *player == 0? 1 : 2);
    scanf("%d%d", &row, &col);

    // Validate input
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move. Try again.\n");
        return;
    }

    // Update board
    board[row][col] = *player;

    // Check for win
    if (checkWin()) {
        printf("Player %d wins!\n", *player);
        gameOver = true;
    }
}

// Function to play the game
void playGame() {
    int player = 0;

    while (!gameOver) {
        // Change players
        if (currentPlayer == 0) {
            currentPlayer = 1;
        } else {
            currentPlayer = 0;
        }

        // Player's turn
        printf("Player %d's turn.\n", currentPlayer);
        getMove(&player);
    }
}

int main() {
    int choice;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Enter 1 to start a new game, 2 to exit:\n");
    scanf("%d", &choice);

    while (choice!= 2) {
        if (choice == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = 0;
                }
            }

            playGame();
            printf("\nGame over. Press any key to continue...");
            getchar();
        }

        printf("Enter 1 to start a new game, 2 to exit:\n");
        scanf("%d", &choice);
    }

    return 0;
}