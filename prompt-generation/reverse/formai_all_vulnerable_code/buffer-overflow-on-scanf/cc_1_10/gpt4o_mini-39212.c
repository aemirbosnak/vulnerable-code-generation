//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include <stdio.h>

void printDiamond(int n) {
    // Print the upper part of the diamond
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }

    // Print the lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}

int main() {
    int size;

    // Introduction to the program
    printf("Welcome to the Diamond Pattern Generator!\n");
    printf("Please enter the size of the diamond (positive integer): ");
    
    // Input validation
    while (1) {
        scanf("%d", &size);
        if (size > 0) break; // Acceptable input
        printf("Invalid input. Please enter a positive integer: ");
    }
    
    // Print the diamond
    printDiamond(size);

    // Completion message
    printf("Pattern generation completed successfully.\n");

    return 0;
}