//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>

// Function to print a pattern of numbers and symbols
void printPattern(int n) {
    // Outer loop for rows
    for (int i = 1; i <= n; i++) {
        // Inner loop for columns
        for (int j = 1; j <= n; j++) {
            // Print number or symbol based on row and column
            if (i % 2 != 0) {
                // Print number in odd rows
                printf("%d ", (i * j) % 10);
            } else {
                // Print symbol in even rows; using ASCII values
                printf("%c ", (i + 64 + j) % 26 + 65);
            }
        }
        // Move to the next line after each row
        printf("\n");
    }
}

// Function to create a square pattern with a border
void printBorderedPattern(int n) {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            // Print border
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
                printf("* ");
            } else {
                // Print interior pattern
                if ((i - 1) % 2 == 0) {
                    printf("%d ", ((i - 1) * (j - 1)) % 10);
                } else {
                    printf("%c ", ((i + j - 1) % 26 + 65));
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    // Prompt user for the size of the pattern
    printf("Enter the size of the pattern (positive integer): ");
    scanf("%d", &size);

    // Check for valid input
    if (size <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Generate and print the patterns
    printf("\nNumber and Symbol Pattern:\n");
    printPattern(size);
    
    printf("\nBordered Square Pattern:\n");
    printBorderedPattern(size);

    return 0;
}