//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the board size and players
#define SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE]);
void aiMove(char board[SIZE][SIZE]);
int isValidMove(char board[SIZE][SIZE], int row, int col);
void clearBuffer();

// Main game loop
int main() {
    char board[SIZE][SIZE];
    int winner = 0;

    initializeBoard(board);

    // Main game loop
    while (winner == 0) {
        printBoard(board);
        playerMove(board);
        winner = checkWinner(board);
        if (winner != 0) break; // Check for winner after player's move
        
        aiMove(board);
        winner = checkWinner(board);
    }

    // Print the final board and the result
    printBoard(board);
    if (winner == 1) {
        printf("Congratulations! Player X wins!\n");
    } else if (winner == 2) {
        printf("Congratulations! Player O wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

// Initialize the Tic Tac Toe board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// Print the current board state to the console
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Check if there's a winner
int checkWinner(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY) {
            return (board[i][0] == PLAYER_X) ? 1 : 2;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY) {
            return (board[0][i] == PLAYER_X) ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) {
        return (board[0][0] == PLAYER_X) ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY) {
        return (board[0][2] == PLAYER_X) ? 1 : 2;
    }

    return 0; // No winner yet
}

// Check for a draw
int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0; // Not a draw yet
            }
        }
    }
    return 1; // It's a draw
}

// Player's move
void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    do {
        printf("Enter your move (row and column between 1 and 3): ");
        scanf("%d%d", &row, &col);
        row--; col--; // Adjust for zero-based indexing
    } while (!isValidMove(board, row, col));
    board[row][col] = PLAYER_X;
}

// AI's move
void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    srand(time(0));
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isValidMove(board, row, col));
    board[row][col] = PLAYER_O;
}

// Check if the move is valid
int isValidMove(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY);
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}