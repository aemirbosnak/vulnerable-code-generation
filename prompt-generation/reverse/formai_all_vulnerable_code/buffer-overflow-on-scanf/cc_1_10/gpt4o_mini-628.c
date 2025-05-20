//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: irregular
#include <stdio.h>

// Function to print an inverted triangle
void print_inverted_triangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a pyramid
void print_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a diamond shape
void print_diamond(int n) {
    // Print upper triangle
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    // Print lower triangle
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a hollow square
void print_hollow_square(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to print various patterns
void print_patterns(int n) {
    printf("\nInverted Triangle:\n");
    print_inverted_triangle(n);

    printf("\nPyramid:\n");
    print_pyramid(n);

    printf("\nDiamond:\n");
    print_diamond(n);

    printf("\nHollow Square:\n");
    print_hollow_square(n);
}

int main() {
    int n;

    // Getting user input
    printf("Enter the size for the patterns (1-20): ");
    scanf("%d", &n);

    // Validating input
    if (n < 1 || n > 20) {
        printf("Please enter a number between 1 and 20.\n");
        return 1; // Exit on invalid input
    }

    // Printing all patterns
    print_patterns(n);

    return 0;
}