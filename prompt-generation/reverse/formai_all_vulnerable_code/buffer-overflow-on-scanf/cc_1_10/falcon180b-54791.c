//Falcon-180B DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

int create_table(int rows, int cols, int min_value, int max_value) {
    int table[rows][cols];
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = rand() % (max_value - min_value + 1) + min_value;
        }
    }
    return 0;
}

int display_table(int rows, int cols, int table[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int rows, cols;
    printf("Enter number of rows (between 1 and %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (between 1 and %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Invalid input. Please enter valid numbers.\n");
        return 1;
    }

    int min_value, max_value;
    printf("Enter minimum value (between %d and %d): ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &min_value);
    printf("Enter maximum value (between %d and %d): ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &max_value);

    if (min_value >= max_value) {
        printf("Invalid input. Minimum value cannot be greater than or equal to maximum value.\n");
        return 1;
    }

    int table[rows][cols];
    create_table(rows, cols, min_value, max_value);
    display_table(rows, cols, table);

    return 0;
}