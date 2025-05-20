//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void printPattern(int n) {
    // Calculate spaces required for the widest part of the pattern
    int space = n - 1;

    // Top half of the pattern
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        space--;

        // Print left half of stars
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        // Print right half of stars
        for (int j = 1; j < i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    // Bottom half of the pattern
    space = 1;  // Reset space for bottom half
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        space++;

        // Print left half of stars
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        // Print right half of stars
        for (int j = 1; j < i; j++) {
            printf("* ");
        }

        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for the pattern: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        fprintf(stderr, "Error: Please enter a valid positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("\nGenerated Pattern:\n");
    printPattern(n);

    return EXIT_SUCCESS;
}