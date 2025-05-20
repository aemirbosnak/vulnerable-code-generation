//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>

// Function to print the inverted triangle pattern
void printInvertedTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--) {
            printf("  "); // Two spaces for alignment
        }

        // Print asterisks for the triangle
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("* ");
        }

        // Print numbers in decreasing order for each row
        for (int l = i; l >= 1; l--) {
            printf("%d ", l);
        }

        // Move to the next line after each row
        printf("\n");
    }
}

// Function to print the top part of the pattern
void printTopPart(int n) {
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = n; j > i; j--) {
            printf("  "); // Two spaces for alignment
        }

        // Print asterisks for the triangle
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("* ");
        }

        // Print numbers in increasing order for each row
        for (int l = 1; l <= i; l++) {
            printf("%d ", l);
        }

        // Move to the next line after each row
        printf("\n");
    }
}

// Main function
int main() {
    int height;

    // User input for the height of the pattern
    printf("Enter the height of the pattern: ");
    scanf("%d", &height);

    // Validate the input
    if (height <= 0) {
        printf("Please enter a positive integer for the height!\n");
        return 1;
    }

    // Print the complete pattern
    printf("\nComplete Pattern:\n\n");
    printTopPart(height);
    printInvertedTriangle(height);

    // Adding a border for a creative touch
    printf("\nPattern Drawing Complete!\n");
    for (int i = 0; i < (height * 2 + 1); i++) {
        printf("-");
    }
    printf("\n");

    return 0;
}