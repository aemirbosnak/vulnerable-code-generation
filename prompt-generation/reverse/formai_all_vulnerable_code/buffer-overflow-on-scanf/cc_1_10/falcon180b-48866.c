//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to print the pattern
void printPattern(int rows, int cols) {
    int i, j;

    // Print the first row
    for (i = 0; i < cols; i++) {
        printf("*");
    }
    printf("\n");

    // Print the middle rows
    for (i = 1; i < rows - 1; i++) {
        for (j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the last row
    for (i = 0; i < cols; i++) {
        printf("*");
    }
    printf("\n");
}

// Function to validate the input
int validateInput(int rows, int cols) {
    if (rows < 1 || rows > MAX_ROWS) {
        printf("Invalid number of rows! Please enter a number between 1 and %d.\n", MAX_ROWS);
        return 0;
    }

    if (cols < 1 || cols > MAX_COLS) {
        printf("Invalid number of columns! Please enter a number between 1 and %d.\n", MAX_COLS);
        return 0;
    }

    return 1;
}

int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Validate the input
    if (!validateInput(rows, cols)) {
        return 0;
    }

    // Print the pattern
    printPattern(rows, cols);

    return 0;
}