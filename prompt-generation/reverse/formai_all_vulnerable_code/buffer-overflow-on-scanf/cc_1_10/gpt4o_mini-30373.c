//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
bool gameOver = false;
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '.';
}

void displayBoard() {
    printf("\033[1;32m"); // Set color to bright green
    printf("   0   1   2\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("  ---|---|---\n");
    }
    printf("\033[0m"); // Reset color
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '.');
}

void makeMove(int row, int col, char player) {
    board[row][col] = player;
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) // Column
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) // Anti-Diagonal
        return true;

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == '.')
                return false;
    return true;
}

void aiMove() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if AI can win
            if (isMoveValid(i, j)) {
                makeMove(i, j, currentPlayer);
                if (checkWin(currentPlayer)) {
                    return;
                }
                board[i][j] = '.'; // Reset move
            }
        }
    }

    // Block opponent's winning move
    char opponent = (currentPlayer == 'X') ? 'O' : 'X';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (isMoveValid(i, j)) {
                makeMove(i, j, opponent);
                if (checkWin(opponent)) {
                    makeMove(i, j, currentPlayer);
                    return;
                }
                board[i][j] = '.'; // Reset move
            }
        }
    }

    // Random move if no immediate win/block available
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isMoveValid(row, col));
    makeMove(row, col, currentPlayer);
}

void playGame() {
    while (!gameOver) {
        displayBoard();
        if (currentPlayer == 'X') {
            int row, col;
            printf("\033[1;34m"); // Set color to cyan
            printf("Hacker, make your move (row and column): ");
            printf("\033[0m"); // Reset color
            scanf("%d %d", &row, &col);

            if (isMoveValid(row, col)) {
                makeMove(row, col, currentPlayer);
            } else {
                printf("Invalid move! Try again.\n");
                continue;
            }
        } else {
            printf("\033[1;31m"); // Set color to red
            printf("AI is thinking...\n");
            printf("\033[0m"); // Reset color
            sleep(1); // Simulate AI thinking
            aiMove();
        }

        if (checkWin(currentPlayer)) {
            displayBoard();
            printf("\033[1;35m"); // Set color to magenta
            printf("%c wins the battle!\n", currentPlayer);
            printf("\033[0m"); // Reset color
            gameOver = true;
        } else if (isBoardFull()) {
            displayBoard();
            printf("\033[1;33m"); // Set color to yellow
            printf("It's a cyber-draw!\n");
            printf("\033[0m"); // Reset color
            gameOver = true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
    }
}

int main() {
    printf("\033[1;36m"); // Set color to cyan
    printf("Welcome to the Cyberpunk Tic Tac Toe!\n");
    printf("Let's begin the digital showdown...\n");
    printf("\033[0m"); // Reset color

    initializeBoard();
    playGame();

    return 0;
}