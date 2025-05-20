//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>

void printDiamond(int n) {
    int i, j;
    // Print the upper part of the diamond
    for (i = 0; i < n; i++) {
        for (j = n; j > i + 1; j--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Print the lower part of the diamond
    for (i = n - 1; i >= 0; i--) {
        for (j = n; j > i + 1; j--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int i, j;
    // Print pyramid
    for (i = 0; i < n; i++) {
        for (j = n; j > i; j--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    int i, j;
    // Print inverted triangle
    for (i = n; i > 0; i--) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    int i, j;
    // Print hourglass pattern
    for (i = n; i > 0; i--) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 2; i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the height of the patterns (positive integer): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nInverted Triangle Pattern:\n");
    printInvertedTriangle(n);

    printf("\nHourglass Pattern:\n");
    printHourglass(n);

    return 0;
}