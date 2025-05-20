//Falcon-180B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void generateBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
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
    srand(time(NULL));
    int board[ROWS][COLS];
    generateBoard(board);
    printBoard(board);
    int player = 1;
    while (1) {
        printf("Player %d's turn\n", player);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= 0) {
            printf("Invalid move\n");
            continue;
        }
        board[row][col] = player;
        printBoard(board);
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player =!player;
    }
    return 0;
}