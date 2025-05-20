//Falcon-180B DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize game board
void initBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = -1;
        }
    }
}

// Function to check if a move is valid
int isValidMove(int board[3][3], int row, int col) {
    if (board[row][col]!= -1) {
        return 0;
    }
    return 1;
}

// Function to check if a player has won
int checkWin(int board[3][3], int player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to print the game board
void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get a valid move from the player
int getValidMove(int board[3][3]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d%d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if (isValidMove(board, row, col)) {
            return row * 3 + col;
        }
        printf("Invalid move. Please try again.\n");
    }
}

// Function to play the game
void playGame(int board[3][3]) {
    int player = 1;
    int currentPlayer = player;
    int moves = 0;
    while (moves < 9) {
        printBoard(board);
        int move = getValidMove(board);
        if (move == -1) {
            return;
        }
        board[move / 3][move % 3] = currentPlayer;
        moves++;
        if (checkWin(board, currentPlayer)) {
            printf("Player %d wins!\n", currentPlayer);
            return;
        }
        currentPlayer = 3 - currentPlayer;
    }
    printf("It's a draw.\n");
}

// Main function
int main() {
    srand(time(NULL));
    int board[3][3];
    initBoard(board);
    playGame(board);
    return 0;
}