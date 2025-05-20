//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 3
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY 0
#define WIN_SCORE 3

// Variables
int board[BOARD_SIZE][BOARD_SIZE] = {0};
int player = PLAYER_1;
int winner = EMPTY;

// Functions
void printBoard();
void makeMove(int row, int col);
void switchPlayer();
void checkWin();

int main() {
    printf("Welcome to TicTacToe!\n");
    printf("Player 1 is X, Player 2 is O\n\n");
    printBoard();

    // Game loop
    while (winner == EMPTY) {
        int row, col;

        // Get player input
        printf("Player %d's turn\n", player);
        printf("Enter row and column (eg. 1 1): ");
        scanf("%d %d", &row, &col);

        // Make move
        makeMove(row - 1, col - 1);

        // Switch player
        switchPlayer();

        // Check win
        checkWin();

        // Print board
        printBoard();
    }

    // Game over
    printf("Game over! Player %d wins!\n", winner);

    return 0;
}

// Prints the game board
void printBoard() {
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j] == PLAYER_1 ? 'X' :
                              board[i][j] == PLAYER_2 ? 'O' : '-');

            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }

        printf("\n");

        if (i < BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }

    printf("\n");
}

// Makes a move on the game board
void makeMove(int row, int col) {
    if (board[row][col] == EMPTY) {
        board[row][col] = player;
    } else {
        printf("That spot is already taken! Try again.\n");
        switchPlayer();
    }
}

// Switches the current player
void switchPlayer() {
    player = player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

// Checks if a player has won
void checkWin() {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        int rowSum = 0, colSum = 0;

        for (int j = 0; j < BOARD_SIZE; j++) {
            rowSum += board[i][j] == player ? 1 : 0;
            colSum += board[j][i] == player ? 1 : 0;
        }

        if (rowSum >= WIN_SCORE || colSum >= WIN_SCORE) {
            winner = player;
            return;
        }
    }

    // Check diagonals
    int diagSum1 = 0, diagSum2 = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        diagSum1 += board[i][i] == player ? 1 : 0;
        diagSum2 += board[i][BOARD_SIZE - i - 1] == player ? 1 : 0;
    }

    if (diagSum1 >= WIN_SCORE || diagSum2 >= WIN_SCORE) {
        winner = player;
        return;
    }
}