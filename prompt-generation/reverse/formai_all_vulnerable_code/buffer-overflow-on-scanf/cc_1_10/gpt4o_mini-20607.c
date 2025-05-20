//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Constants for the game
#define PLAYER 'X'
#define AI 'O'
#define EMPTY ' '
#define SIZE 3

// Function to print the Tic Tac Toe board
void printBoard(char board[SIZE][SIZE]) {
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) 
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Check rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) // Check columns
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    return 0;
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY)
                return 0;
    return 1;
}

// Function for AI to make a move
void aiMove(char board[SIZE][SIZE]) {
    // Simple AI: Try to win, otherwise block the player
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                // Try to win
                board[i][j] = AI;
                if (checkWin(board, AI)) {
                    return;
                }
                board[i][j] = EMPTY; // Undo move
            }
        }
    }
    // Block player from winning
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER;
                if (checkWin(board, PLAYER)) {
                    board[i][j] = AI; // Block the player
                    return;
                }
                board[i][j] = EMPTY; // Undo move
            }
        }
    }
    // If no winning or blocking moves, choose first available space
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                return;
            }
        }
    }
}

// Main function to run the Tic Tac Toe game
int main() {
    char board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;

    int row, col;
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are 'X' and the AI is 'O'.\n");

    while (1) {
        printBoard(board);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);

        // Validate input
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = PLAYER;

        if (checkWin(board, PLAYER)) {
            printBoard(board);
            printf("Congratulations! You've won!\n");
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        aiMove(board);

        if (checkWin(board, AI)) {
            printBoard(board);
            printf("AI wins! Better luck next time.\n");
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }
    }
    
    return 0;
}