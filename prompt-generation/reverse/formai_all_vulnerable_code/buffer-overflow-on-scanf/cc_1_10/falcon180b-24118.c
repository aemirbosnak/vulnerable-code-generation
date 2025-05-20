//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_ROWS 4
#define MAX_COLS 4

void initBoard(char board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void generateRandomPosition(int *row, int *col, int maxRows, int maxCols) {
    *row = rand() % maxRows;
    *col = rand() % maxCols;
}

int main() {
    char board[MAX_ROWS][MAX_COLS];
    int i, j, matches = 0, attempts = 0, maxAttempts = 10;
    int selectedRow, selectedCol, selectedValue, value;
    srand(time(NULL));

    initBoard(board);

    for (i = 0; i < MAX_SIZE; i++) {
        generateRandomPosition(&selectedRow, &selectedCol, MAX_ROWS, MAX_COLS);
        value = rand() % 10 + 1;
        board[selectedRow][selectedCol] = value + '0';
    }

    printBoard(board);

    while (matches < MAX_SIZE && attempts < maxAttempts) {
        printf("Enter row and column to select: ");
        scanf("%d%d", &selectedRow, &selectedCol);

        if (selectedRow >= 0 && selectedRow < MAX_ROWS && selectedCol >= 0 && selectedCol < MAX_COLS) {
            value = board[selectedRow][selectedCol] - '0';

            if (value!= 0) {
                printf("You selected value %d\n", value);
                matches++;
            } else {
                printf("You selected a blank tile\n");
            }
        } else {
            printf("Invalid selection\n");
        }

        attempts++;
    }

    if (matches == MAX_SIZE) {
        printf("Congratulations, you won in %d attempts!\n", attempts);
    } else {
        printf("Sorry, you lost with %d matches in %d attempts\n", matches, attempts);
    }

    return 0;
}