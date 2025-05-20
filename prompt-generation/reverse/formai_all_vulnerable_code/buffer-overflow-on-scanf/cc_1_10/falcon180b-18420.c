//Falcon-180B DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
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

int checkWin(char board[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
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

int main() {
    srand(time(0));

    char board[ROWS][COLS];
    initBoard(board);

    int player = 1;
    while (1) {
        system("clear");
        printBoard(board);
        printf("Player %d's turn\n", player);

        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move\n");
            continue;
        }

        if (board[row][col]!= '-') {
            printf("Spot already taken\n");
            continue;
        }

        board[row][col] = (player % 2 == 0)? 'X' : 'O';

        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}