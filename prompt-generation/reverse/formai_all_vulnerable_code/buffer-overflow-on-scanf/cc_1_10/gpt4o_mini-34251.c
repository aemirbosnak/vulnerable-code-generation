//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>

// Function to print a square of stars of given size
void printSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a triangle of stars
void printTriangle(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print the combined pattern
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        printf("\nSquare of size %d:\n", i);
        printSquare(i);
        printf("Triangle of height %d:\n", i);
        printTriangle(i);
    }
}

int main() {
    int n;

    printf("Enter the number of iterations for printing patterns (1-10): ");
    // Validate input
    while (1) {
        if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
            printf("Invalid input. Please enter a number between 1 and 10: ");
            while(getchar() != '\n'); // Clear invalid input
        } else {
            break; // Valid input
        }
    }

    // Print the desired pattern
    printPattern(n);

    return 0;
}