//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

// Function to initialize the board
void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the current state of the board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if there is a winner
bool checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// AI move
void aiMove(char board[SIZE][SIZE]) {
    // Basic AI logic: Place 'O' in the first empty spot
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O'; // AI plays "O"
                return;
            }
        }
    }
}

// Player move
void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (true) {
        printf("Enter your move (row and column): ");
        if (scanf("%d %d", &row, &col) != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid input. Please enter row and column between 0 and 2.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (board[row][col] != ' ') {
            printf("Cell already taken! Choose another cell.\n");
            continue;
        }
        board[row][col] = 'X'; // Player plays "X"
        break;
    }
}

// Main function
int main() {
    char board[SIZE][SIZE];
    initBoard(board);
    bool playerTurn = true;

    while (true) {
        printBoard(board);
        if (playerTurn) {
            playerMove(board);
            if (checkWinner(board, 'X')) {
                printBoard(board);
                printf("Congratulations! You win!\n");
                break;
            }
        } else {
            aiMove(board);
            if (checkWinner(board, 'O')) {
                printBoard(board);
                printf("AI wins! Better luck next time!\n");
                break;
            }
        }
        playerTurn = !playerTurn;

        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}