//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Function declarations
void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int placeMove(char board[SIZE][SIZE], int row, int col, char player);
int checkWinner(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);
void playGame();

int main() {
    playGame();
    return 0;
}

// Function to initialize the board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard(char board[SIZE][SIZE]) {
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

// Function to place a move on the board
int placeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player;
        return 1;
    }
    return 0;
}

// Function to check for a winner
int checkWinner(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // No winner
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Function to run the main game loop
void playGame() {
    char board[SIZE][SIZE];
    char player = 'X';
    int row, col, winner;

    initializeBoard(board);

    while (1) {
        displayBoard(board);
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        if (placeMove(board, row, col, player)) {
            winner = checkWinner(board);
            if (winner != ' ') {
                displayBoard(board);
                printf("Player %c wins!\n", winner);
                break;
            }
            if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                break;
            }
            player = (player == 'X') ? 'O' : 'X'; // Switch players
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}