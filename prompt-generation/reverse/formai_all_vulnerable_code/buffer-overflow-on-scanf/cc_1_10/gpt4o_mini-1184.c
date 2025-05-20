//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

void printPattern(int n) {
    int i, j, k;

    // Upper half of the pattern
    for (i = 0; i < n; i++) {
        // Print leading spaces
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print increasing numbers
        for (j = 0; j <= i; j++) {
            printf("%d ", j + 1);
        }
        // Print decreasing numbers
        for (j = i - 1; j >= 0; j--) {
            printf("%d ", j + 1);
        }
        // Move to the next line
        printf("\n");
    }

    // Lower half of the pattern
    for (i = n - 2; i >= 0; i--) {
        // Print leading spaces
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print increasing numbers
        for (j = 0; j <= i; j++) {
            printf("%d ", j + 1);
        }
        // Print decreasing numbers
        for (j = i - 1; j >= 0; j--) {
            printf("%d ", j + 1);
        }
        // Move to the next line
        printf("\n");
    }
}

void printDiamond(int n) {
    int i, j;

    // Upper part of the diamond
    for (i = 0; i < n; i++) {
        // Print leading spaces for diamond
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print stars for diamond
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }

    // Lower part of the diamond
    for (i = n - 2; i >= 0; i--) {
        // Print leading spaces for diamond
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print stars for diamond
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}

void printHollowSquare(int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Print border of square
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        // Move to the next line
        printf("\n");
    }
}

int main() {
    int n;

    // Input for the pattern size
    printf("Enter the size for the patterns: ");
    scanf("%d", &n);

    // Print the patterns
    printf("\nPyramid Pattern:\n");
    printPattern(n);

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);

    return 0;
}