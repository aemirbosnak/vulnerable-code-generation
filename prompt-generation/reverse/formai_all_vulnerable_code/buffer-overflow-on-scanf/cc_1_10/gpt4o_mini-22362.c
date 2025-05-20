//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>

// Function to print the upper part of the diamond
void printUpperDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" "); // Print leading spaces
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*"); // Print stars
        }
        printf("\n"); // Move to the next line
    }
}

// Function to print the lower part of the diamond
void printLowerDiamond(int n) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" "); // Print leading spaces
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*"); // Print stars
        }
        printf("\n"); // Move to the next line
    }
}

// Function to print the full diamond pattern
void printDiamond(int n) {
    printUpperDiamond(n); // Call to print the upper part
    printLowerDiamond(n); // Call to print the lower part
}

// Main function
int main() {
    int n;

    // Prompt user for the size of the diamond
    printf("Enter the number of rows for the diamond (greater than 0): ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; // Exit with error code
    }

    printf("\nGenerated Diamond Pattern:\n\n");
    printDiamond(n); // Call to print the entire diamond pattern

    return 0; // Successful exit code
}