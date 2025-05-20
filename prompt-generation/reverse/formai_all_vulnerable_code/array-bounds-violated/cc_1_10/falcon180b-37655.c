//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: calm
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

int isMatch(char a, char b) {
    return a == b;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int matches = 0;

    while (matches < ROWS * COLS) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        char card1 = 'A' + x * COLS + y;
        char card2 = 'A' + (x + 1) * COLS + y;

        if (board[x][y] == '-' && board[x + 1][y]!= '-' && isMatch(board[x + 1][y], card1)) {
            board[x][y] = card1;
            board[x + 1][y] = '-';
            matches++;
        } else if (board[x][y] == '-' && board[x][y + 1]!= '-' && isMatch(board[x][y + 1], card2)) {
            board[x][y] = card2;
            board[x][y + 1] = '-';
            matches++;
        }

        printBoard(board);
        printf("Matches: %d\n", matches);
        fflush(stdout);
        sleep(1);
    }

    printf("Congratulations! You won with %d matches!\n", matches);
    return 0;
}