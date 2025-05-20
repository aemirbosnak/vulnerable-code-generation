//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>

// Function to print the desired pattern
void printPattern(int n) {
    int i, j;

    // Upper part of the diamond
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (j = i; j < n; j++) {
            printf("  ");
        }
        // Print asterisks
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Lower part of the diamond
    for (i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (j = n; j > i; j--) {
            printf("  ");
        }
        // Print asterisks
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a pyramid of numbers
void printNumberPyramid(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (j = i; j < n; j++) {
            printf("  ");
        }
        // Print numbers in the pyramid
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Function to print inverted pyramid of numbers
void printInvertedNumberPyramid(int n) {
    int i, j;

    for (i = n; i >= 1; i--) {
        // Print leading spaces
        for (j = n; j > i; j--) {
            printf("  ");
        }
        // Print numbers in the inverted pyramid
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Function to print X pattern
void printXPattern(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j == i || j == (n - i + 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print hollow rectangle
void printHollowRectangle(int rows, int cols) {
    int i, j;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            if (i==1 || i==rows || j==1 || j==cols) {
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
    int n;

    printf("Enter the size for the patterns (1 to 10): ");
    scanf("%d", &n);

    if(n < 1 || n > 10) {
        printf("Please enter a number between 1 and 10.\n");
        return 1;
    }

    printf("\nDiamond Pattern:\n");
    printPattern(n);

    printf("\nNumber Pyramid:\n");
    printNumberPyramid(n);

    printf("\nInverted Number Pyramid:\n");
    printInvertedNumberPyramid(n);

    printf("\nX Pattern:\n");
    printXPattern(n);

    printf("\nHollow Rectangle:\n");
    printHollowRectangle(n, n * 2); // Rectangular with double the number of columns

    return 0;
}