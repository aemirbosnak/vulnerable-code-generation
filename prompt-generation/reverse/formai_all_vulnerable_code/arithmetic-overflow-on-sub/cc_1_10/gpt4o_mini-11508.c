//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

// Function to print a triangle pattern
void printTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print an inverted triangle pattern
void printInvertedTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a diamond pattern
void printDiamond(int n) {
    // Upper part of the diamond
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    // Lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a hollow square pattern
void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print a pyramidal pattern
void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a number pattern
void printNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

// Function to print a zigzag pattern
void printZigzag(int n) {
    int row = 3; // Number of rows for the zigzag

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < n; j++) {
            if (j % (row - 1) == i || j % (row - 1) == (row - 1 - i)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function to execute the pattern printing
int main() {
    int n;

    // Get the number of rows/size for the patterns
    printf("Enter the size of the patterns: ");
    scanf("%d", &n);

    printf("\nTriangle Pattern:\n");
    printTriangle(n);

    printf("\nInverted Triangle Pattern:\n");
    printInvertedTriangle(n);

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);

    printf("\nPyramidal Pattern:\n");
    printPyramid(n);

    printf("\nNumber Pattern:\n");
    printNumberPattern(n);

    printf("\nZigzag Pattern:\n");
    printZigzag(n);

    printf("\nPattern printing completed! Enjoy your shapes!\n");
    
    return 0;
}