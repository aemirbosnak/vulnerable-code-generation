//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

// Function to print the top half of the diamond
void printTopHalf(int n) {
    int i, j, k;

    // Iterate over each row
    for (i = 1; i <= n; i++) {
        // Print spaces for the current row
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print stars for the current row
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to print the bottom half of the diamond
void printBottomHalf(int n) {
    int i, j, k;

    // Iterate over each row
    for (i = n - 1; i >= 1; i--) {
        // Print spaces for the current row
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print stars for the current row
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    // Get the size of the diamond from the user
    printf("Enter the size of the diamond: ");
    scanf("%d", &n);

    // Print the top half of the diamond
    printTopHalf(n);

    // Print the bottom half of the diamond
    printBottomHalf(n);

    return 0;
}