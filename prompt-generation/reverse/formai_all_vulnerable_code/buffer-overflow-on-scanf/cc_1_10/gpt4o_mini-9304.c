//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);
int isFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int gameStatus = 0;

    initializeBoard(board);

    printf("Welcome to the Tic Tac Toe Game!\n");

    while (gameStatus == 0) {
        printBoard(board);
        playerMove(board, currentPlayer);
        gameStatus = checkWin(board);
        
        if (gameStatus == 0 && isFull(board)) {
            gameStatus = -1; // Draw condition
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);

    if (gameStatus == 1) {
        printf("Player X wins!\n");
    } else if (gameStatus == 2) {
        printf("Player O wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

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
            for (int k = 0; k < SIZE; k++) {
                printf("---");
                if (k < SIZE - 1) {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][SIZE - 1] != ' ' && board[0][SIZE - 1] == board[1][SIZE - 2] && board[1][SIZE - 2] == board[SIZE - 1][0]) {
        return (board[0][SIZE - 1] == 'X') ? 1 : 2;
    }
    return 0; // No winner yet
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;

    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break; // Valid move made
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int isFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Found an empty space
            }
        }
    }
    return 1; // No empty spaces left
}