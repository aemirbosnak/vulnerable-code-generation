//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void getMove(char board[ROWS][COLS], int player) {
    int row, col;
    do {
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d%d", &row, &col);
        row--;
        col--;
    } while (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= '-');

    board[row][col] = (player == 1)? 'X' : 'O';
}

int main() {
    char board[ROWS][COLS] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
    int player = 1;
    srand(time(NULL));

    while (1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn.\n", player);
        getMove(board, player);

        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}