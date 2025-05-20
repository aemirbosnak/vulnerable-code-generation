//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

void printShockPattern(int rows) {
    for(int i = 1; i <= rows; i++) {
        // Print leading spaces
        for(int j = i; j < rows; j++) {
            printf(" "); // Create spaces for proper alignment
        }
        // Print the upper part of the shocked face or pattern
        for(int k = 1; k <= (2 * i - 1); k++) {
            if (k % 2 == 0) {
                printf("O"); // Representing eyes
            } else {
                printf("*"); // Representing shocked mouth and nose
            }
        }
        printf("\n"); // Move to next line
    }
}

void printLowerPattern(int rows) {
    for(int i = rows; i >= 1; i--) {
        // Print leading spaces
        for(int j = rows; j > i; j--) {
            printf(" ");
        }
        // Print the lower part of the shocked face or pattern
        for(int k = 1; k <= (2 * i - 1); k++) {
            if (k % 2 == 0) {
                printf("O"); // Again representing the shocked eyes
            } else {
                printf("*"); // Representing shocked mouth
            }
        }
        printf("\n"); // Move to next line
    }
}

int main() {
    int totalRows;
    printf("Enter the number of rows for the shocked pattern (5-10): ");
    scanf("%d", &totalRows);

    // Validate input
    if (totalRows < 5 || totalRows > 10) {
        printf("Please enter a number between 5 and 10.\n");
        return 1; // Exit if the input is out of range
    }

    printf("\nHere comes the shocked pattern!\n\n");
    
    // Call functions to print the shocked pattern
    printShockPattern(totalRows);
    printLowerPattern(totalRows);

    printf("\nWow! That was shocking!\n");
    return 0;
}