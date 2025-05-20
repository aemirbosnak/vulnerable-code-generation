//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

void printPattern(int n) {
    int spaces, stars;

    // Print the upper part of the pattern
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (spaces = 1; spaces <= n - i; spaces++) {
            printf(" ");
        }
        // Print first half of stars
        for (stars = 1; stars <= i; stars++) {
            printf("* ");
        }
        printf("\n");
    }

    // Print the lower part of the pattern
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (spaces = 1; spaces <= n - i; spaces++) {
            printf(" ");
        }
        // Print first half of stars
        for (stars = 1; stars <= i; stars++) {
            printf("* ");
        }
        printf("\n");
    }
}

void diamondPattern(int n) {
    int spaces, stars;

    // Print the upper part of the diamond
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (spaces = 1; spaces <= n - i; spaces++) {
            printf(" ");
        }
        // Print stars
        for (stars = 1; stars <= (2 * i) - 1; stars++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (spaces = 1; spaces <= n - i; spaces++) {
            printf(" ");
        }
        // Print stars
        for (stars = 1; stars <= (2 * i) - 1; stars++) {
            printf("*");
        }
        printf("\n");
    }
}

void centeredTrianglePattern(int n) {
    // Prints a centered triangle of stars
    for (int i = 1; i <= n; i++) {
        // Print leading spaces for centering
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the height of the pattern: ");
    scanf("%d", &n);

    printf("\nDiamond Pattern:\n");
    diamondPattern(n);

    printf("\nCentered Triangle Pattern:\n");
    centeredTrianglePattern(n);

    printf("\nInverted Triangle Pattern:\n");
    printInvertedTriangle(n);

    printf("\nPyramid Pattern:\n");
    printPattern(n);

    return 0;
}