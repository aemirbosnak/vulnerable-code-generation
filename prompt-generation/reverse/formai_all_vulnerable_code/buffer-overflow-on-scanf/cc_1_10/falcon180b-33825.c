//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeTile(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        board[row][col] = 'X';
    }
}

int checkWin(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return 1;
    }

    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(0));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    int moves = 0;

    while (1) {
        printBoard(board);
        int row, col;
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d %d", &row, &col);

        if (board[row - 1][col - 1]!= 'X' && board[row - 1][col - 1]!= 'O') {
            placeTile(board, row - 1, col - 1);
            moves++;
            player = (player % 2)? 1 : 2;

            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}