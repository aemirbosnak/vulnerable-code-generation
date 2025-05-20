//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

void printBoard(char board[ROWS][COLUMNS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf(" %c ", board[i][j]);
            if (j < COLUMNS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < ROWS - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

bool isWinner(char board[ROWS][COLUMNS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLUMNS; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }

    return false;
}

bool isTie(char board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void resetBoard(char board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char board[ROWS][COLUMNS];
    char player1 = 'X';
    char player2 = 'O';
    int turn = 1;
    int row, col;
    bool gameOver = false;

    resetBoard(board);
    srand(time(NULL));

    while (!gameOver) {
        printf("Turn %d:\n", turn);
        if (turn % 2 == 0) {
            printf("Player 2 (O) turn:\n");
            row = rand() % 3;
            col = rand() % 3;
        } else {
            printf("Player 1 (X) turn:\n");
            printf("Enter row between 0-2: ");
            scanf("%d", &row);
            printf("Enter column between 0-2: ");
            scanf("%d", &col);
            printf("\n");
        }

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (turn % 2 == 0) {
            board[row][col] = 'O';
        } else {
            board[row][col] = 'X';
        }

        printBoard(board);

        if (isWinner(board, player1)) {
            printf("Player 1 (X) wins!\n");
            gameOver = true;
        } else if (isWinner(board, player2)) {
            printf("Player 2 (O) wins!\n");
            gameOver = true;
        } else if (isTie(board)) {
            printf("Tie game.\n");
            gameOver = true;
        }

        turn++;
    }

    return 0;
}