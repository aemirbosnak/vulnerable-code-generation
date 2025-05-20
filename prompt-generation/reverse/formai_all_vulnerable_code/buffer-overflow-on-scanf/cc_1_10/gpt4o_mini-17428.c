//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

// Function to print the upper half of the diamond
void printUpperHalf(int rows) {
    int space, i, j;
    for (i = 1; i <= rows; i++) {
        // Print leading spaces
        for (space = i; space < rows; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        // Move to the next line after each row
        printf("\n");
    }
}

// Function to print the lower half of the diamond
void printLowerHalf(int rows) {
    int space, i, j;
    for (i = rows - 1; i >= 1; i--) {
        // Print leading spaces
        for (space = rows; space > i; space--) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        // Move to the next line after each row
        printf("\n");
    }
}

// Main function
int main() {
    int rows;

    // Prompt the user for the number of rows
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &rows);

    // Validate input
    if (rows < 1) {
        printf("Number of rows must be a positive integer.\n");
        return 1;
    }

    // Print the diamond pattern
    printf("\nDiamond Pattern:\n");
    printUpperHalf(rows);
    printLowerHalf(rows);

    return 0;
}