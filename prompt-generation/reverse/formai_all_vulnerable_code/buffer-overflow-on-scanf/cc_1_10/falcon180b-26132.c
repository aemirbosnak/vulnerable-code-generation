//Falcon-180B DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS], int player) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
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

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int currentPlayer = 1;
    int gameWon = 0;

    while (!gameWon) {
        system("clear");
        printBoard(board);
        int row, col;
        printf("Player %d's turn. Enter row and column: ", currentPlayer);
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 0) {
            board[row][col] = currentPlayer;
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                printf("Player %d wins!\n", currentPlayer);
            } else {
                currentPlayer =!currentPlayer;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}