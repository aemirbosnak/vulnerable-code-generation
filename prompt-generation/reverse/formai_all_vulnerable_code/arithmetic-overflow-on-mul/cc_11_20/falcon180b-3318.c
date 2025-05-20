//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// Function to print a pattern in a shape shifting style
void shapeShiftPattern(int rows, int cols, int shift) {
    int i, j, k, l;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || j == 0) {
                printf("* ");
            } else if (i == rows - 1 || j == cols - 1) {
                printf("* ");
            } else if (i == rows / 2 && j == cols / 2) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == rows / 2 && j == cols / 2) {
                printf("* ");
            } else if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (k = 0; k < rows; k++) {
        for (l = 0; l < cols; l++) {
            if (k == rows / 2 && l == cols / 2) {
                printf("* ");
            } else if (k == 0 || l == 0 || k == rows - 1 || l == cols - 1) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, shift;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the shift amount: ");
    scanf("%d", &shift);
    if (rows > 0 && cols > 0 && shift >= 0 && shift < rows * cols) {
        shapeShiftPattern(rows, cols, shift);
    } else {
        printf("Invalid input!");
    }
    return 0;
}