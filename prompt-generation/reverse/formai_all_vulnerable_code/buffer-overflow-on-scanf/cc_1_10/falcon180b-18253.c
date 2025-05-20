//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

int check_win(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
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

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);
    int player = 1;
    while (1) {
        printf("Player %d's turn:\n", player);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[row][col]!= '*') {
            printf("Cell already revealed.\n");
            continue;
        }
        board[row][col] = (player == 1)? 'X' : 'O';
        if (check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}