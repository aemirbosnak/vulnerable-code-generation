//Falcon-180B DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUMBERS 100

int main() {
    int rows, cols, numbers;
    int table[MAX_ROWS][MAX_COLS];
    int i, j, k;
    int sum = 0;

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;
    numbers = rand() % MAX_NUMBERS + 1;

    printf("Welcome to the C Table Game!\n");
    printf("You have %d rows, %d columns, and %d numbers to fill.\n", rows, cols, numbers);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            table[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("Now, try to fill in the missing numbers.\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (table[i][j] == 0) {
                printf("Missing number at (%d,%d): ", i, j);
                scanf("%d", &table[i][j]);
                sum += table[i][j];
            }
        }
    }

    printf("Congratulations! You filled in all the missing numbers.\n");
    printf("The sum of all numbers in the table is %d.\n", sum);

    return 0;
}