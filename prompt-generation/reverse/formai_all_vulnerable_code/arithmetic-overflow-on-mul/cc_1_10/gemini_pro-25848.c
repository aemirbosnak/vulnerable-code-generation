//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to print the top half of the pattern
void printTopHalf(int n) {
    int i, j;

    // Iterate over each row of the top half
    for (i = 0; i < n; i++) {
        // Print spaces before the stars
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print stars in the current row
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to print the bottom half of the pattern
void printBottomHalf(int n) {
    int i, j;

    // Iterate over each row of the bottom half
    for (i = n - 1; i >= 0; i--) {
        // Print spaces before the stars
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print stars in the current row
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    // Get the size of the pattern from the user
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Print the top half of the pattern
    printTopHalf(n);

    // Print the bottom half of the pattern
    printBottomHalf(n);

    return 0;
}