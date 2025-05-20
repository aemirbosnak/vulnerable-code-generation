//Falcon-180B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(char board[ROWS][COLS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
    int player = 1;
    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        int row, col;
        scanf("%d%d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move\n");
            continue;
        }
        if (board[row][col]!= '-') {
            printf("Spot already taken\n");
            continue;
        }
        board[row][col] = (player == 1)? 'X' : 'O';
        if (checkWin(board, board[row][col])) {
            printf("%c wins!\n", board[row][col]);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}