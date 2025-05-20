//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

// Function to print a pyramid pattern
void printPyramid(int n) {
    int space, i, j;

    for (i = 0; i < n; i++) {
        // Print leading spaces
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        // Print stars
        for (j = 0; j < (2 * i + 1); j++)
            printf("*");
        printf("\n");
    }
}

// Function to print a diamond pattern
void printDiamond(int n) {
    int space, i, j;

    // Upper part of diamond
    for (i = 0; i < n; i++) {
        // Print leading spaces
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        // Print stars
        for (j = 0; j < (2 * i + 1); j++)
            printf("*");
        printf("\n");
    }

    // Lower part of diamond
    for (i = n - 2; i >= 0; i--) {
        // Print leading spaces
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        // Print stars
        for (j = 0; j < (2 * i + 1); j++)
            printf("*");
        printf("\n");
    }
}

// Function to print a square pattern
void printSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a hollow square pattern
void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("* ");
            else
                printf("  "); // Space in the middle
        }
        printf("\n");
    }
}

// Function to print a right-angled triangle pattern
void printRightTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a reversed right-angled triangle pattern
void printReversedRightTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    printf("Welcome to the Creative Pattern Printer!\n");
    printf("Please enter the size of the patterns (positive integer): ");
    scanf("%d", &n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nSquare Pattern:\n");
    printSquare(n);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);

    printf("\nRight-Angled Triangle Pattern:\n");
    printRightTriangle(n);

    printf("\nReversed Right-Angled Triangle Pattern:\n");
    printReversedRightTriangle(n);

    printf("\nThank you for using the Creative Pattern Printer!\n");

    return 0;
}