//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

// Function to print inverted pyramid pattern
void printInvertedPyramid(int rows) {
    for (int i = rows; i >= 1; i--) {
        // Printing leading spaces
        for (int j = 0; j < rows - i; j++) {
            printf(" ");
        }
        // Printing stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print diamond pattern
void printDiamond(int rows) {
    // Printing upper triangle
    for (int i = 1; i <= rows; i++) {
        // Printing leading spaces
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        // Printing stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Printing lower triangle
    for (int i = rows - 1; i >= 1; i--) {
        // Printing leading spaces
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        // Printing stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function to execute the program
int main() {
    int rows;

    // Asking user for the number of rows for the patterns
    printf("Enter the number of rows for the patterns: ");
    scanf("%d", &rows);

    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(rows);

    printf("\nDiamond Pattern:\n");
    printDiamond(rows);

    return 0;
}