//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

void initBoard(char board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isMatch(char board[ROW][COL], int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL) {
        return 0;
    }

    if (board[row][col] == '-') {
        return 0;
    }

    return 1;
}

int countMatches(char board[ROW][COL]) {
    int count = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (isMatch(board, i, j)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    srand(time(NULL));

    char board[ROW][COL];
    initBoard(board);

    int matches = 0;
    int turns = 0;

    while (matches < ROW * COL / 2) {
        printBoard(board);

        int row, col;
        printf("Player %d's turn. Enter row and column: ", turns % 2 + 1);
        scanf("%d%d", &row, &col);

        if (isMatch(board, row, col)) {
            board[row][col] = 'X';
            matches++;
        } else {
            board[row][col] = 'O';
        }

        turns++;
        printf("\n");
    }

    printf("Congratulations! You win!\n");

    return 0;
}