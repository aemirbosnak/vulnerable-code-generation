//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS], int x, int y) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == x && j == y) {
                printf("|   X");
            } else if (board[i][j] == 0) {
                printf("|  %d ", board[i][j]);
            } else {
                printf("| %d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int main() {
    int board[ROWS][COLS] = {0};
    int numbers[76] = {0};
    int index = 1;
    int num, row, col;
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) {
                continue;
            }
            board[i][j] = index++;
        }
    }

    printf("Welcome to Bingo Simulator!\n");
    printf("The `X` is your current position.\n");

    while (1) {
        printf("\nEnter a number (1 - 75): ");
        scanf("%d", &num);

        if (num < 1 || num > 75) {
            printf("Invalid number. Please enter a number between 1 and 75.\n");
            continue;
        } else if (numbers[num] != 0) {
            printf("Number %d has already been called. Please enter a different number.\n", num);
            continue;
        }

        numbers[num] = 1;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        printBoard(board, row, col);

        if (board[0][0] == 0 && board[0][4] == 0 && board[4][0] == 0 && board[4][4] == 0) {
            printf("Bingo! All four corners have been marked.\n");
            break;
        }

        int flag = 0;

        for (int i = 0; i < ROWS; i++) {
            int count = 0;
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 0) {
                    count++;
                }
            }
            if (count == 5) {
                printf("Bingo! Row %d has been marked.\n", i + 1);
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            break;
        }

        flag = 0;

        for (int i = 0; i < COLS; i++) {
            int count = 0;
            for (int j = 0; j < ROWS; j++) {
                if (board[j][i] == 0) {
                    count++;
                }
            }
            if (count == 5) {
                printf("Bingo! Column %d has been marked.\n", i + 1);
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            break;
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}