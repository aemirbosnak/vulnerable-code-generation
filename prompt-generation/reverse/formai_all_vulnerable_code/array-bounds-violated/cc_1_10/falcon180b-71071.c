//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: automated
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

void shuffleBoard(char board[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            k = rand() % ROWS;
            board[i][j] = board[k][j];
            board[k][j] = '-';
        }
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    shuffleBoard(board);
    printBoard(board);

    int row, col;
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);

    if (board[row][col] == '-') {
        printf("Invalid move\n");
    } else {
        board[row][col] = '-';
        printf("You flipped (%d, %d)\n", row, col);
        if (checkWin(board)) {
            printf("Congratulations! You win!\n");
        }
    }

    return 0;
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