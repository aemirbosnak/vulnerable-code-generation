//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
void flipCard(char board[ROWS][COLS], int row, int col);
int checkMatch(char board[ROWS][COLS], int row, int col);
void playGame(char board[ROWS][COLS]);

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    playGame(board);
    return 0;
}

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

void flipCard(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (board[row][col] == '-') {
            board[row][col] = 'X';
        } else if (board[row][col] == 'X') {
            board[row][col] = 'O';
        } else if (board[row][col] == 'O') {
            board[row][col] = '-';
        }
    }
}

int checkMatch(char board[ROWS][COLS], int row, int col) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 'X' && (i == row || j == col)) {
                return 1;
            } else if (board[i][j] == 'O' && (i == row || j == col)) {
                return 1;
            }
        }
    }
    return 0;
}

void playGame(char board[ROWS][COLS]) {
    int player = 1;
    int row, col;
    srand(time(NULL));
    int randomRow, randomCol;

    while (1) {
        printBoard(board);
        printf("Player %d's turn\n", player);
        scanf("%d %d", &row, &col);
        row--; col--;
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid move\n");
            continue;
        }
        if (board[row][col] == '-') {
            flipCard(board, row, col);
            if (checkMatch(board, row, col)) {
                printf("Player %d wins!\n", player);
                break;
            } else {
                player++;
            }
        } else {
            printf("Card already flipped\n");
        }
    }
}