//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void drawBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0)
                printf("_ ");
            else if (board[i][j] == 1)
                printf("X ");
            else if (board[i][j] == 2)
                printf("O ");
        }
        printf("\n");
    }
}

int isValidMove(int board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 0)
        return 1;
    return 0;
}

void makeMove(int board[ROWS][COLS], int row, int col) {
    if (isValidMove(board, row, col)) {
        board[row][col] = 1;
    }
}

int checkWin(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 1)
            return 0;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 1)
            return 0;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 1)
        return 0;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 1)
        return 0;
    return 1;
}

int main() {
    int board[ROWS][COLS] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int player = 0;
    srand(time(NULL));
    int row, col;
    while (1) {
        drawBoard(board);
        printf("Player %d's turn.\n", player + 1);
        if (player % 2 == 0)
            printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (isValidMove(board, row, col)) {
            makeMove(board, row, col);
            player++;
            if (checkWin(board)) {
                printf("Player %d wins!\n", player - 1);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}