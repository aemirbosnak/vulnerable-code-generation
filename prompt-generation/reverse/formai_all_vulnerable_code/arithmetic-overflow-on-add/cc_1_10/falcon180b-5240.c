//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define EMPTY '.'
#define PLAYER 'X'
#define ENEMY 'O'

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(const char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int makeMove(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == EMPTY) {
        board[row][col] = PLAYER;
        return 1;
    }
    return 0;
}

int checkWin(const char board[ROWS][COLS]) {
    int i, j;

    // Check rows
    for (i = 0; i < ROWS; ++i) {
        if (board[i][0] == PLAYER && board[i][1] == PLAYER && board[i][2] == PLAYER) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COLS; ++j) {
        if (board[0][j] == PLAYER && board[1][j] == PLAYER && board[2][j] == PLAYER) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == PLAYER && board[1][1] == PLAYER && board[2][2] == PLAYER) {
        return 1;
    }
    if (board[0][2] == PLAYER && board[1][1] == PLAYER && board[2][0] == PLAYER) {
        return 1;
    }

    return 0;
}

void playGame(char board[ROWS][COLS]) {
    int playerRow, playerCol;
    int enemyRow, enemyCol;
    int won = 0;

    srand(time(NULL));
    playerRow = rand() % ROWS;
    playerCol = rand() % COLS;
    board[playerRow][playerCol] = PLAYER;

    while (!won) {
        printBoard(board);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &enemyRow, &enemyCol);
        enemyRow = (enemyRow + 2) % ROWS;
        enemyCol = (enemyCol + 2) % COLS;
        if (makeMove(board, enemyRow, enemyCol)) {
            if (checkWin(board)) {
                printf("You win!\n");
                won = 1;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
}

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    playGame(board);
    return 0;
}