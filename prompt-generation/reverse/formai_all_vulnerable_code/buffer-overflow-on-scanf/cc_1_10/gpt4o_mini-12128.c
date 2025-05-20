//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>

void printTriangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces for alignment
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        // Print stars in the triangle
        for (int k = 1; k <= (2 * i) - 1; k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}

void printInvertedTriangle(int rows) {
    for (int i = rows; i >= 1; i--) {
        // Print leading spaces for alignment
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        // Print stars in the inverted triangle
        for (int k = 1; k <= (2 * i) - 1; k++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}

int main() {
    int levels;
    
    // Welcome message
    printf("Welcome to the Pattern Printing Program!\n");
    printf("Let's create something beautiful together!\n");
    
    // User input for the number of levels
    printf("Please enter the number of levels for the pattern (1-20): ");
    scanf("%d", &levels);
    
    // Input validation
    if (levels < 1 || levels > 20) {
        printf("Thank you for your input! Please enter a number within the range.\n");
        return 1;
    }
    
    // Inspiration from nature
    printf("\nLet's start with a lovely triangle pattern:\n");
    printTriangle(levels);
    
    // A graceful transition
    printf("\nAs the stars fade, let's admire their beauty in reverse:\n");
    printInvertedTriangle(levels);

    // Closing thoughts
    printf("\nThank you for participating in this joyous printing journey!\n");
    printf("May your day be filled with wonderful patterns and creativity!\n");

    return 0;
}