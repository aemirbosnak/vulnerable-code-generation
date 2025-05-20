//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the board
void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool isValidMove(int board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0);
}

// Function to check if the game is over
bool isGameOver(int board[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                count++;
            } else if (board[i][j] == board[0][0]) {
                count--;
            }
        }
    }
    return (count == 0);
}

// Function to play the game
void playGame() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int row, col;
    bool gameOver = false;

    printf("Welcome to the Memory Game!\n");
    printBoard(board);

    while (!gameOver) {
        printf("Turn: ");
        scanf("%d %d", &row, &col);

        if (isValidMove(board, row, col)) {
            board[row][col] = 1;
            printf("You found a match!\n");
            printBoard(board);
        } else {
            printf("Invalid move. Try again.\n");
        }

        if (isGameOver(board)) {
            gameOver = true;
            printf("You won!\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}