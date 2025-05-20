//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>

void printDiamondPattern(int n) {
    // Upper part of diamond
    for (int i = 1; i <= n; i++) {
        // Print leading spaces for upper part
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print stars for upper part
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of diamond
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces for lower part
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print stars for lower part
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int size;

    // Welcome message
    printf("Welcome to the Diamond Pattern Generator!\n");

    // Input size with validation
    while (1) {
        printf("Please enter the size of the diamond (odd number > 1): ");
        scanf("%d", &size);
        
        // Check if the input is valid
        if (size > 1 && size % 2 != 0) {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Print the diamond pattern
    printDiamondPattern(size);

    // Farewell message
    printf("Thank you for using the Diamond Pattern Generator. Goodbye!\n");

    return 0;
}