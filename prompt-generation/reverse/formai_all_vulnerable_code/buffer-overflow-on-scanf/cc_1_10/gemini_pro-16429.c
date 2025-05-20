//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS];
int player;

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int main() {
    initBoard();
    player = 1;

    while (!checkWin()) {
        int row, col;
        printf("Player %d's turn:\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        if (row < 1 || row > ROWS || col < 1 || col > COLS || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if (player == 1) {
            board[row - 1][col - 1] = 'X';
        } else {
            board[row - 1][col - 1] = 'O';
        }

        printBoard();

        player = 3 - player;
    }

    printf("Player %d wins!\n", player);
    return 0;
}