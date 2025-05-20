//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Alan Turing
#include <stdio.h>

// Function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Function to print asterisks in a line
void printAsterisks(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
}

// Function to print a diamond pattern
void printDiamond(int n) {
    int spaces;
    // Printing upper half of the diamond
    for (int i = 0; i < n; i++) {
        spaces = n - i - 1; // Calculate spaces for current row
        printSpaces(spaces); // Print leading spaces
        printAsterisks(i + 1); // Print asterisks (1 to n)
        printf("\n"); // New line after each row
    }

    // Printing lower half of the diamond
    for (int i = n - 2; i >= 0; i--) {
        spaces = n - i - 1; // Calculate spaces for current row
        printSpaces(spaces); // Print leading spaces
        printAsterisks(i + 1); // Print asterisks (1 to n)
        printf("\n"); // New line after each row
    }
}

// Main function
int main() {
    int n;

    // Prompting user for input
    printf("Enter the number of rows for the diamond pattern (greater than 0): ");
    scanf("%d", &n);

    // Validation of user input
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("\nGenerating a diamond pattern of %d rows:\n\n", n);
    printDiamond(n); // Call function to print diamond
    return 0;
}