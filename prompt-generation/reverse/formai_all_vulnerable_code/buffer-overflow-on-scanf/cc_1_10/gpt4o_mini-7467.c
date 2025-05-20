//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: irregular
#include <stdio.h>

// Function to print a specific pattern of numbers
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        // Print leading spaces for each row
        for (int j = n; j > i; j--) {
            printf("   ");
        }
        // Print left side stars and numbers
        for (int j = 1; j <= i; j++) {
            printf("%2d ", j);
        }
        // Print right side stars and numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%2d ", j);
        }
        // New line for the next row
        printf("\n");
    }
}

// Function to print a pyramid of asterisks
void printAsterisks(int n) {
    for (int i = 1; i <= n; i++) {
        // Leading spaces for the pyramid
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print inverted triangle of numbers
void printInvertedTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j - i; j++) {
            printf("   ");
        }
        // Print numbers
        for (int j = 1; j <= i; j++) {
            printf("%2d ", j);
        }
        printf("\n");
    }
}

// Function to print diamond shape of numbers
void printDiamond(int n) {
    printPattern(n);
    for (int i = n-1; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--) {
            printf("   ");
        }
        // Print left side numbers
        for (int j = 1; j <= i; j++) {
            printf("%2d ", j);
        }
        // Print right side numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%2d ", j);
        }
        printf("\n");
    }
}

// Function to print hollow square of asterisks
void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

// Function to print zigzag pattern of numbers
void printZigzag(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) { // Odd row: left to right
            for (int j = 1; j <= n; j++) {
                printf("%2d ", j);
            }
        } else { // Even row: right to left
            for (int j = n; j >= 1; j--) {
                printf("%2d ", j);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the patterns (max 10): ");
    scanf("%d", &size);
    
    printf("\nPyramid of Asterisks:\n");
    printAsterisks(size);
    
    printf("\nInverted Triangle of Numbers:\n");
    printInvertedTriangle(size);
    
    printf("\nDiamond Shape of Numbers:\n");
    printDiamond(size);
    
    printf("\nHollow Square of Asterisks:\n");
    printHollowSquare(size);
    
    printf("\nZigzag Pattern of Numbers:\n");
    printZigzag(size);
    
    return 0;
}