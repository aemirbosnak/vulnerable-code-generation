//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printStars(int count) {
    for (int i = 0; i < count; i++) {
        printf("*");
    }
}

void printDiamond(int size) {
    // Print the upper part of the diamond
    for (int i = 0; i < size; i++) {
        printSpaces(size - i - 1);
        printStars(2 * i + 1);
        printf("\n");
    }

    // Print the lower part of the diamond
    for (int i = size - 2; i >= 0; i--) {
        printSpaces(size - i - 1);
        printStars(2 * i + 1);
        printf("\n");
    }
}

void printBorder(int size) {
    for (int i = 0; i < size * 2 + 1; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    int size;
    
    printf("Enter the size of the diamond: ");
    scanf("%d", &size);

    // Print a border before the diamond
    printBorder(size);

    // Print the diamond pattern
    printf("Diamond Pattern:\n");
    printDiamond(size);

    // Print a border after the diamond
    printBorder(size);

    // Additional creative patterns
    printf("\nOther Patterns:\n");

    // Print a hollow square
    printBorder(size);
    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < size - 2; j++) {
            if (i == 0 || i == size - 1) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printBorder(size);

    // Print a triangle
    printf("\nTriangle Pattern:\n");
    for (int i = 1; i <= size; i++) {
        printStars(i);
        printf("\n");
    }

    // Print a reverse triangle
    printf("\nReverse Triangle Pattern:\n");
    for (int i = size; i > 0; i--) {
        printStars(i);
        printf("\n");
    }

    // Create a checkerboard pattern
    printf("\nCheckerboard Pattern:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Create a pyramid pattern
    printf("\nPyramid Pattern:\n");
    for (int i = 0; i < size; i++) {
        printSpaces(size - i - 1);
        printStars(2 * i + 1);
        printf("\n");
    }

    // Create an inverted pyramid pattern
    printf("\nInverted Pyramid Pattern:\n");
    for (int i = size; i > 0; i--) {
        printSpaces(size - i);
        printStars(2 * i - 1);
        printf("\n");
    }

    printf("\nProgram has completed all patterns.\n");
    return 0;
}