//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20
#define DELAY 100000

void draw_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Input values are too large.\n");
        return 1;
    }

    draw_pattern(rows, cols);

    while (1) {
        system("clear");
        int new_rows = rand() % (MAX_ROWS - 1) + 1;
        int new_cols = rand() % (MAX_COLS - 1) + 1;

        if (new_rows < rows || new_cols < cols) {
            printf("Error: Pattern is shrinking.\n");
            return 1;
        }

        draw_pattern(new_rows, new_cols);

        usleep(DELAY);
    }

    return 0;
}