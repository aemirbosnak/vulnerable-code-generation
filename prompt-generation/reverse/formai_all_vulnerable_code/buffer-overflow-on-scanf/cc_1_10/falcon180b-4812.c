//Falcon-180B DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS];

void initBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i]!= '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();
    int player = 1;
    char mark;

    while (1) {
        system("clear");
        drawBoard();
        printf("Player %d's turn\n", player);

        int row, col;
        if (player == 1) {
            mark = 'X';
            player = 2;
        } else {
            mark = 'O';
            player = 1;
        }

        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);

        if (board[row-1][col-1] == '-') {
            board[row-1][col-1] = mark;
            if (checkWin()) {
                printf("Player %d wins!\n", player);
                break;
            }
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}