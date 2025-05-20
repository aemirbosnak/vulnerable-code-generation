//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef enum { X, O, EMPTY } Cell;
typedef enum { PLAYER, AI } Turn;

void printBoard(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    // Print column numbers
    printf("  0 1 2\n");

    // Print rows with cells
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case X: printf("X "); break;
                case O: printf("O "); break;
                case EMPTY: printf("_ "); break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if any of the rows or columns are full with the type passed as an argument
int checkRowsCols(Cell board[BOARD_SIZE][BOARD_SIZE], Cell type) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != type) {
                break;
            }
        }
        if (j == BOARD_SIZE) {
            return 1;
        }

        // Check columns
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[j][i] != type) {
                break;
            }
        }
        if (j == BOARD_SIZE) {
            return 1;
        }
    }

    return 0;
}

// Checks if any of the diagonals are full with the type passed as an argument
int checkDiagonals(Cell board[BOARD_SIZE][BOARD_SIZE], Cell type) {
    int i;

    // Check first diagonal
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != type) {
            break;
        }
    }
    if (i == BOARD_SIZE) {
        return 1;
    }

    // Check second diagonal
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] != type) {
            break;
        }
    }
    if (i == BOARD_SIZE) {
        return 1;
    }

    return 0;
}

// Checks if the board is full (no empty cells left)
int checkBoardFull(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

// Checks if the game has ended (any of the players won or the board is full)
int checkEndGame(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    return checkRowsCols(board, X) || checkRowsCols(board, O) || checkDiagonals(board, X) || checkDiagonals(board, O) || checkBoardFull(board);
}

// Calculates the AI's move and sets the corresponding cell on the board
void aiMove(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    // Find the first empty cell and set it to O
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = O;
                return;
            }
        }
    }
}

void playerMove(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    do {
        printf("Enter row and column (e.g. 1 2): ");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY);

    board[row][col] = X;
}

// Controls the main game loop switching between player and AI's turns
void playGame() {
    // Initialize the game board with empty cells
    Cell board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    Turn currentPlayer = PLAYER;

    while (!checkEndGame(board)) {
        printBoard(board);

        if (currentPlayer == PLAYER) {
            playerMove(board);
            currentPlayer = AI;
        } else {
            aiMove(board);
            currentPlayer = PLAYER;
        }
    }

    printBoard(board);
    if (checkRowsCols(board, X) || checkDiagonals(board, X)) {
        printf("Congratulations! You win!\n");
    } else if (checkRowsCols(board, O) || checkDiagonals(board, O)) {
        printf("You lost! Better luck next time.\n");
    } else {
        printf("It's a tie!\n");
    }
}

// Main entry point
int main() {
    playGame();
    return 0;
}