//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

// Function to print the diamond pattern
void printDiamond(int n) {
    int space, i, j;

    // Upper part of the diamond
    for (i = 0; i < n; i++) {
        // Print spaces
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        // New line after each row
        printf("\n");
    }

    // Lower part of the diamond
    for (i = n - 2; i >= 0; i--) {
        // Print spaces
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        // New line after each row
        printf("\n");
    }
}

// Function to get user input for the diamond size
int getInput() {
    int n;
    printf("Enter the size of the diamond (integer >= 1): ");
    while (1) {
        scanf("%d", &n);
        if (n >= 1) {
            break;  // Valid input
        }
        printf("Please enter a valid integer greater than or equal to 1: ");
    }
    return n;
}

// Main function
int main() {
    // Prompt user for diamond size
    int diamondSize = getInput();

    // Print the diamond
    printf("\nHere is your diamond pattern of size %d:\n\n", diamondSize);
    printDiamond(diamondSize);

    return 0;  // End of program
}