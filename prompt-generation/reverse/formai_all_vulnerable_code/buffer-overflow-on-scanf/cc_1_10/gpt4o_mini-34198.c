//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>

void printPattern(int n) {
    int spaces = n - 1;
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        spaces--;

        // Print first half of the pattern
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }

        // Print second half of the pattern
        for (int j = 0; j < i; j++) {
            printf("* ");
        }

        // Move to the next line
        printf("\n");
    }
}

void printInvertedPattern(int n) {
    int spaces = 0;
    for (int i = n; i > 0; i--) {
        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        spaces++;

        // Print first half of the inverted pattern
        for (int j = 0; j < i; j++) {
            printf("* ");
        }

        // Print second half of the inverted pattern
        for (int j = 1; j < i; j++) {
            printf("* ");
        }

        // Move to the next line
        printf("\n");
    }
}

int main() {
    int n;

    // Visionary introduction
    printf("Welcome to the Star Pattern Generator!\n");
    printf("Enter the number of rows for the star pattern: ");
    scanf("%d", &n);

    // Print the first part of the pattern
    printf("\nHere comes your mesmerizing star pattern:\n");
    printPattern(n);

    // Print the second part of the pattern
    printf("\nAnd now, behold the inverted reflection:\n");
    printInvertedPattern(n);

    // Finishing touch
    printf("\nThank you for visiting the visionary world of patterns!\n");
    
    return 0;
}