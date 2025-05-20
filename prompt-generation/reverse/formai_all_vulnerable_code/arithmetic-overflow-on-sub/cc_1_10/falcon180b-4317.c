//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
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

int match(char a, char b) {
    if (a == b) {
        return 1;
    } else {
        return 0;
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 9 + 1;
        }
    }
    int flag = 0;
    int player = 1;
    while (flag == 0) {
        int choice;
        printf("Player %d's turn\n", player);
        printBoard(board);
        printf("Enter row and column: ");
        scanf("%d %d", &i, &j);
        if (board[i-1][j-1]!= '-') {
            printf("Invalid move!\n");
        } else {
            board[i-1][j-1] = (player % 2) + '0';
            player++;
            if (checkWin(board)) {
                printf("Player %d wins!\n", player);
                flag = 1;
            }
        }
    }
    return 0;
}