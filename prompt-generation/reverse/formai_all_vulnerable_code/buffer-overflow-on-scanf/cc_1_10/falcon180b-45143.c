//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the number of rows and columns
#define ROWS 10
#define COLS 10

// Function to print a single row of the pattern
void printRow(int row, int cols) {
    int i;
    for (i = 0; i < cols; i++) {
        printf("*");
    }
    printf("\n");
}

// Function to print the pattern
void printPattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i == 0 && j == 0) || (i == rows - 1 && j == cols - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int rows, cols;

    // Ask the user for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Validate the input
    if (rows <= 0 || cols <= 0) {
        printf("Invalid input. Please enter positive values for the number of rows and columns.\n");
        return 1;
    }

    // Print the pattern
    printPattern(rows, cols);

    return 0;
}