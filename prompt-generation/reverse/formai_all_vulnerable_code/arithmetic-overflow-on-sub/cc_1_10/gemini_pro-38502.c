//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to print the pattern
void printPattern(int n) {
    int i, j, k;

    // Iterate over each row
    for (i = 0; i < n; i++) {
        // Print spaces for the current row
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        // Print stars for the current row
        for (k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }

    // Iterate over each row in reverse order
    for (i = n - 1; i >= 0; i--) {
        // Print spaces for the current row
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }

        // Print stars for the current row
        for (k = 0; k < 2 * i; k++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    // Get the input from the user
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Print the pattern
    printPattern(n);

    return 0;
}