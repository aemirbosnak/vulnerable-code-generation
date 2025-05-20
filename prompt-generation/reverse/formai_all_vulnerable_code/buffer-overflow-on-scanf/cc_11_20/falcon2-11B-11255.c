//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>

// Define a 2D array to represent the game board
int board[10][10];

// Function to print the game board
void printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for a winning condition
int isGameOver() {
    // Check rows
    for (int i = 0; i < 10; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] &&
            board[i][3] == board[i][4] && board[i][4] == board[i][5] && board[i][5] == board[i][6] &&
            board[i][6] == board[i][7] && board[i][7] == board[i][8] && board[i][8] == board[i][9]) {
            return 1; // Player 1 wins!
        }
    }

    // Check columns
    for (int i = 0; i < 10; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] &&
            board[3][i] == board[4][i] && board[4][i] == board[5][i] && board[5][i] == board[6][i] &&
            board[6][i] == board[7][i] && board[7][i] == board[8][i] && board[8][i] == board[9][i]) {
            return 2; // Player 2 wins!
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] &&
        board[3][3] == board[4][4] && board[4][4] == board[5][5] && board[5][5] == board[6][6] &&
        board[6][6] == board[7][7] && board[7][7] == board[8][8] && board[8][8] == board[9][9]) {
        return 1; // Player 1 wins!
    }

    if (board[0][9] == board[1][8] && board[1][8] == board[2][7] && board[2][7] == board[3][6] &&
        board[3][6] == board[4][5] && board[4][5] == board[5][4] && board[5][4] == board[6][3] &&
        board[6][3] == board[7][2] && board[7][2] == board[8][1] && board[8][1] == board[9][0]) {
        return 2; // Player 2 wins!
    }

    return 0; // Game is not over yet
}

// Function to check for a valid move
int isValidMove(int row, int col) {
    // Check if the move is within the board
    if (row >= 0 && row < 10 && col >= 0 && col < 10) {
        // Check if the cell is empty
        if (board[row][col] == 0) {
            return 1; // Valid move
        } else {
            return 0; // Invalid move
        }
    }

    return 0; // Invalid move
}

// Function to make a move
void makeMove(int row, int col, int player) {
    // Check if the move is valid
    if (isValidMove(row, col)) {
        // Update the game board
        board[row][col] = player;

        // Check for a winning condition
        if (isGameOver() == 1) {
            printf("Player 1 wins!\n");
        } else if (isGameOver() == 2) {
            printf("Player 2 wins!\n");
        } else {
            printf("It's a draw!\n");
        }
    } else {
        printf("Invalid move!\n");
    }
}

// Main function
int main() {
    // Print the game board
    printBoard();

    // Ask for the player's move
    printf("Player 1: Enter your move (row, column): ");
    int row, col;
    scanf("%d%d", &row, &col);

    // Check for a valid move
    if (isValidMove(row, col)) {
        // Make the move
        makeMove(row, col, 1);
    } else {
        printf("Invalid move!\n");
    }

    // Print the updated game board
    printBoard();

    // Ask for the player's move
    printf("Player 2: Enter your move (row, column): ");
    row, col;
    scanf("%d%d", &row, &col);

    // Check for a valid move
    if (isValidMove(row, col)) {
        // Make the move
        makeMove(row, col, 2);
    } else {
        printf("Invalid move!\n");
    }

    // Print the updated game board
    printBoard();

    return 0;
}