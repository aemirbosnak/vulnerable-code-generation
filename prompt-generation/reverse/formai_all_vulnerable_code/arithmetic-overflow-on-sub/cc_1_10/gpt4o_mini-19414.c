//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

// Function to print a hollow diamond pattern
void printHollowDiamond(int n) {
    int space, i, j;

    // Print upper half of the diamond
    for (i = 0; i < n; i++) {
        for (space = n - i; space > 0; space--) {
            printf(" ");
        }
        for (j = 0; j < (2 * i + 1); j++) {
            if (j == 0 || j == (2 * i)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print lower half of the diamond
    for (i = n - 2; i >= 0; i--) {
        for (space = n - i; space > 0; space--) {
            printf(" ");
        }
        for (j = 0; j < (2 * i + 1); j++) {
            if (j == 0 || j == (2 * i)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print a pyramid pattern
void printPyramid(int n) {
    int i, j;

    // Print each row of the pyramid
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a full triangle pattern
void printFullTriangle(int n) {
    int i, j;

    // Print each row of the triangle
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a reversed triangle pattern
void printReversedTriangle(int n) {
    int i, j;

    // Print each row of the reversed triangle
    for (i = n; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a square pattern
void printSquare(int n) {
    int i, j;

    // Print each row of the square
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a checkerboard pattern
void printCheckerboard(int n) {
    int i, j;

    // Print each row of the checkerboard
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    // User input for number of lines
    printf("Enter the size of the pattern (number of lines): ");
    scanf("%d", &n);

    // Print various patterns
    printf("\nHollow Diamond Pattern:\n");
    printHollowDiamond(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nFull Triangle Pattern:\n");
    printFullTriangle(n);

    printf("\nReversed Triangle Pattern:\n");
    printReversedTriangle(n);

    printf("\nSquare Pattern:\n");
    printSquare(n);

    printf("\nCheckerboard Pattern:\n");
    printCheckerboard(n);

    return 0;
}