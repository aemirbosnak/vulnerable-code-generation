//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

void printDiamond(int n) {
    int spaces = n - 1; // Spaces for alignment

    // Print the upper part of the diamond
    for (int i = 1; i <= n; i++) {
        // Printing spaces
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces--;

        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Reset spaces for the lower part
    spaces = 1;

    // Print the lower part of the diamond
    for (int i = 1; i < n; i++) {
        // Printing spaces
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces++;

        // Print stars
        for (int j = 1; j <= (2 * (n - i) - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int height) {
    for (int i = 1; i <= height; i++) {
        // Print leading spaces
        for (int j = i; j < height; j++) {
            printf(" ");
        }

        // Print stars, with odd numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int height) {
    for (int i = height; i >= 1; i--) {
        // Print leading spaces
        for (int j = height; j > i; j--) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHourglass(int height) {
    // Print inverted pyramid
    printInvertedPyramid(height);

    // Print pyramid
    printPyramid(height);
}

void printDiamondWithNumbers(int n) {
    int spaces = n - 1;

    // Upper part
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces--;

        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    // Lower part
    spaces = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces++;

        for (int j = 1; j <= (2 * (n - i) - 1); j++) {
            printf("%d", n - i);
        }
        printf("\n");
    }
}

void printTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printBackwardsTriangle(int height) {
    for (int i = height; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the height for the diamond pattern: ");
    scanf("%d", &n);
    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(n);

    printf("\nHourglass Pattern:\n");
    printHourglass(n);

    printf("\nDiamond with Numbers Pattern:\n");
    printDiamondWithNumbers(n);

    printf("\nTriangle Pattern:\n");
    printTriangle(n);

    printf("\nBackwards Triangle Pattern:\n");
    printBackwardsTriangle(n);

    return 0;
}