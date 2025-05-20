//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i, j;

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return 1;
        }
    }

    // Check vertical lines
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return 1;
    }

    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int player = 1;
    int choice;
    int flag = 0;

    initBoard(board);

    while (!flag) {
        printBoard(board);
        printf("Player %d's turn.\n", player);
        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);

        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid choice.\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS]!= '-') {
            printf("Invalid choice.\n");
            continue;
        }

        board[choice / COLS][choice % COLS] = (player == 1)? 'X' : 'O';

        flag = checkWin(board);

        if (flag) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}