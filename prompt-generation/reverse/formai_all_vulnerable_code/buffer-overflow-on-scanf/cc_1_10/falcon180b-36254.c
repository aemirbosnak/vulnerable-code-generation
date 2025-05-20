//Falcon-180B DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

void generate_table(int table[MAX_ROWS][MAX_COLS], int rows, int cols);
void print_table(int table[MAX_ROWS][MAX_COLS], int rows, int cols);
int get_user_input(int min, int max);

int main() {
    int table[MAX_ROWS][MAX_COLS];
    int rows, cols;

    srand(time(NULL));
    rows = rand() % (MAX_ROWS - 2) + 2;
    cols = rand() % (MAX_COLS - 2) + 2;

    generate_table(table, rows, cols);
    print_table(table, rows, cols);

    return 0;
}

void generate_table(int table[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            table[i][j] = get_user_input(MIN_VALUE, MAX_VALUE);
        }
    }
}

void print_table(int table[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int get_user_input(int min, int max) {
    int input;

    do {
        printf("Enter a value between %d and %d: ", min, max);
        scanf("%d", &input);
    } while (input < min || input > max);

    return input;
}