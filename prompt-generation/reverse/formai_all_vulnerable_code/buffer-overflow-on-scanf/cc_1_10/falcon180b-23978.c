//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 100

// Function to print the given pattern
void print_pattern(int rows, int cols, char pattern[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the given pattern
void generate_pattern(int rows, int cols, char pattern[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                pattern[i][j] = '*';
            } else if (i == j) {
                pattern[i][j] = 'X';
            } else {
                pattern[i][j] = '.';
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input!\n");
        return 1;
    }

    char pattern[rows][cols];
    generate_pattern(rows, cols, pattern);
    print_pattern(rows, cols, pattern);

    return 0;
}