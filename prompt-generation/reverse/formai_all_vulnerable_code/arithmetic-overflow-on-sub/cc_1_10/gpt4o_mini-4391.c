//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: random
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
}

void diamondPattern(int n) {
    // Upper part of the diamond
    for (int i = 0; i < n; i++) {
        printSpaces(n - i - 1);
        printStars(i + 1);
        printf("\n");
    }
    // Lower part of the diamond
    for (int i = n - 2; i >= 0; i--) {
        printSpaces(n - i - 1);
        printStars(i + 1);
        printf("\n");
    }
}

void reverseTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        printStars(i);
        printf("\n");
    }
}

void triangleWithNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void hollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void invertedPyramid(int n) {
    for (int i = n; i >= 1; i--) {
        printSpaces(n - i);
        printStars(i);
        printf("\n");
    }
}

void fullPyramid(int n) {
    for (int i = 0; i < n; i++) {
        printSpaces(n - i - 1);
        printStars(2 * i + 1);
        printf("\n");
    }
}

void hourglassPattern(int n) {
    // Upper part of Hourglass
    for (int i = 0; i < n; i++) {
        printStars(n - i);
        printf("\n");
    }
    // Lower part of Hourglass
    for (int i = 1; i <= n; i++) {
        printStars(i);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter a number to define the size of the patterns: ");
    scanf("%d", &n);

    printf("\nDiamond Pattern:\n");
    diamondPattern(n);

    printf("\nReverse Triangle Pattern:\n");
    reverseTriangle(n);

    printf("\nTriangle with Numbers:\n");
    triangleWithNumbers(n);

    printf("\nHollow Square Pattern:\n");
    hollowSquare(n);

    printf("\nInverted Pyramid Pattern:\n");
    invertedPyramid(n);

    printf("\nFull Pyramid Pattern:\n");
    fullPyramid(n);

    printf("\nHourglass Pattern:\n");
    hourglassPattern(n);

    return 0;
}