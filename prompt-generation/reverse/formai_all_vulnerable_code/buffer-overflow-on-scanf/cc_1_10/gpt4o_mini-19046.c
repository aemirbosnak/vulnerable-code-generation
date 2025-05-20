//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Function prototypes
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
void resetBoard(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int row, col;
    int winner = 0;

    resetBoard(board);
    printf("Welcome to the Tic-Tac-Toe Game!\n");

    while (1) {
        displayBoard(board);
        
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        
        winner = checkWin(board);
        if (winner) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("----");
                if (k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check for a win condition
int checkWin(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Function to reset the game board
void resetBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}