//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 20
#define MAX_COLS 30

// Function to print the given pattern
void print_pattern(int rows, int cols, int pattern) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (pattern == 1) { // Pattern 1: Alternate 1's and 0's
                printf("%d ", i % 2 + 1);
            } else if (pattern == 2) { // Pattern 2: Diagonal 1's and 0's
                if (i + j % 2 == 0) {
                    printf("%d ", 0);
                } else {
                    printf("%d ", 1);
                }
            } else if (pattern == 3) { // Pattern 3: Random 1's and 0's
                if (rand() % 2 == 0) {
                    printf("%d ", 0);
                } else {
                    printf("%d ", 1);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, pattern;
    printf("Enter the number of rows (1-20): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (1-30): ");
    scanf("%d", &cols);
    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input. Please enter values within the range.\n");
        return 1;
    }
    printf("Enter the pattern number (1-3): ");
    scanf("%d", &pattern);
    if (pattern < 1 || pattern > 3) {
        printf("Invalid pattern number. Please enter a valid number.\n");
        return 1;
    }
    print_pattern(rows, cols, pattern);
    return 0;
}