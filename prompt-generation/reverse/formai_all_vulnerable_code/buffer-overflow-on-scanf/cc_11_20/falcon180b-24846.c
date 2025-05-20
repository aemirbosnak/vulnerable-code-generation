//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 9
#define NUM_NUMBERS 16

int main() {
    int board[ROWS][COLS];
    int num_placed = 0;
    int i, j, k, row, col, num, count;
    int flag = 0;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    for (i = 0; i < NUM_NUMBERS; i++) {
        row = rand() % ROWS;
        col = rand() % COLS;
        num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        board[row][col] = num;
        num_placed++;
    }

    printf("Sudoku Board:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("\nEnter a row number and column number to place a number: ");
        scanf("%d%d", &row, &col);

        if (row >= ROWS || col >= COLS) {
            printf("Invalid row or column number.\n");
            continue;
        }

        if (board[row][col]!= 0) {
            printf("This cell already has a number.\n");
            continue;
        }

        printf("Enter a number between %d and %d: ", MIN_NUM, MAX_NUM);
        scanf("%d", &num);

        if (num < MIN_NUM || num > MAX_NUM) {
            printf("Invalid number.\n");
            continue;
        }

        board[row][col] = num;
        num_placed++;

        if (num_placed == NUM_NUMBERS) {
            printf("Congratulations! You have completed the Sudoku board.\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Game over. You didn't complete the Sudoku board.\n");
    }

    return 0;
}