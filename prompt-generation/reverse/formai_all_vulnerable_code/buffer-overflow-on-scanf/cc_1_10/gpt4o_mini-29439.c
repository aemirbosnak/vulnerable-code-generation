//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

// Function to print the diamond pattern
void printDiamond(int n) {
    int space, i, j;

    // Print the upper part of the diamond
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }

    // Print the lower part of the diamond
    for (i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Welcome to the Diamond Pattern Printer! ✨\n");
    printf("Please enter the number of rows for the diamond shape (1 to 20): ");
    scanf("%d", &numRows);

    // Validation for input
    if (numRows < 1 || numRows > 20) {
        printf("Error! Please enter a number between 1 and 20. 🙁\n");
        return 1;
    }

    // Print the diamond pattern
    printf("\nHere is your diamond pattern:\n\n");
    printDiamond(numRows);
    printf("\nThank you for using the Diamond Pattern Printer! Have a great day! 🌈\n");

    return 0;
}