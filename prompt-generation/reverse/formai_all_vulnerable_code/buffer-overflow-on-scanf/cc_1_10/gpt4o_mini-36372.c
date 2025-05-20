//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE]; // The game board
char player = 'X';       // Player's symbol
char ai = 'O';          // AI's symbol

void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

bool isWinner(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || 
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) || 
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

void playerMove() {
    int row, col;
    while (true) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        row--, col--; // Adjust for 0-based index
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move, try again!\n\n");
        }
    }
}

void aiMove() {
    int row, col;

    // Attempt to win
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = ai;
                if (isWinner(ai)) return;
                board[row][col] = ' '; // Reset
            }
        }
    }

    // Block player's winning move
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = player;
                if (isWinner(player)) {
                    board[row][col] = ai; // Block the player's move
                    return;
                }
                board[row][col] = ' '; // Reset
            }
        }
    }
    
    // Choose the first available space
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = ai;
                return;
            }
        }
    }
}

int main() {
    printf("Welcome to Curious Tic Tac Toe!\n");
    initializeBoard();
    printBoard();

    while (true) {
        playerMove();
        printBoard();
        if (isWinner(player)) {
            printf("Congratulations! Player %c wins!\n", player);
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        aiMove();
        printBoard();
        if (isWinner(ai)) {
            printf("Oh no! AI %c wins!\n", ai);
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
    }

    printf("Game over! Thanks for playing!\n");
    return 0;
}