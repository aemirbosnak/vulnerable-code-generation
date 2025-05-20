//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void draw_pattern(int row, int col, char pattern[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char pattern[ROWS][COLS];
    int i, j;

    // Initialize pattern with random characters
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            pattern[i][j] = rand() % 26 + 'A';
        }
    }

    // Print initial pattern
    printf("Initial pattern:\n");
    draw_pattern(0, 0, pattern);

    // Shift pattern right by one column
    for (i = 0; i < ROWS; i++) {
        for (j = COLS - 1; j > 0; j--) {
            pattern[i][j] = pattern[i][j - 1];
        }
        pattern[i][0] = rand() % 26 + 'A';
    }

    // Print shifted pattern
    printf("\nPattern shifted right by one column:\n");
    draw_pattern(0, 1, pattern);

    // Shift pattern down by one row
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLS; j++) {
            pattern[i][j] = pattern[i + 1][j];
        }
        pattern[ROWS - 1][j] = rand() % 26 + 'A';
    }

    // Print shifted pattern
    printf("\nPattern shifted down by one row:\n");
    draw_pattern(1, 0, pattern);

    return 0;
}