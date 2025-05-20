//Falcon-180B DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char board[ROWS][COLS] = { { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' } };

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (i * COLS) + j + 1;
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();
    printBoard();

    int player = 1;
    while (1) {
        int row, col;
        printf("Player %d, enter your move (row, col): ", player);
        scanf("%d%d", &row, &col);
        row--; col--;

        if (board[row][col]!= (player * COLS) + col + 1) {
            printf("Invalid move!\n");
            continue;
        }

        board[row][col] = player * COLS + col + 1;
        printBoard();

        if (checkWin()) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player % 2)? 1 : 2;
    }

    return 0;
}