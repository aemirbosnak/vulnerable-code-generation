//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void drawMatrix(int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printPattern(int rows, int cols, int pattern) {
    int matrix[MAX_ROWS][MAX_COLS];
    int i, j;
    int count = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = count;
            count++;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i][j] * pattern;
        }
    }

    drawMatrix(matrix);
}

int main() {
    int rows, cols, pattern;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the pattern: ");
    scanf("%d", &pattern);

    printPattern(rows, cols, pattern);

    return 0;
}