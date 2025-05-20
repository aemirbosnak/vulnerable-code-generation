//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

#define MAX_ROWS 12
#define MAX_COLS 80

void print_pattern(int row, int col, char c) {
    if (row >= MAX_ROWS || col >= MAX_COLS)
        return;

    printf("%c", c);

    if (row == 0 && col == 0) {
        printf("\n");
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                print_pattern(i, j, '*');
            }
        }
    } else if (row == 0) {
        printf("\n");
        for (int j = 0; j < MAX_COLS; j++) {
            print_pattern(row + 1, j, '*');
        }
    } else if (col == 0) {
        for (int i = 0; i < MAX_ROWS; i++) {
            print_pattern(i, col + 1, '*');
        }
    } else if (row == MAX_ROWS - 1 && col == MAX_COLS - 1) {
        printf("\n");
    } else if (row == MAX_ROWS - 1) {
        for (int j = 0; j < MAX_COLS; j++) {
            print_pattern(row, j, '*');
        }
    } else if (col == MAX_COLS - 1) {
        for (int i = 0; i < MAX_ROWS; i++) {
            print_pattern(i, col, '*');
        }
    } else {
        print_pattern(row + 1, col + 1, '*');
        print_pattern(row + 1, col - 1, '*');
        print_pattern(row - 1, col + 1, '*');
        print_pattern(row - 1, col - 1, '*');
    }
}

int main() {
    int row, col;

    printf("Enter the row and column position of the center of the pattern: ");
    scanf("%d%d", &row, &col);

    print_pattern(row, col, '*');

    return 0;
}