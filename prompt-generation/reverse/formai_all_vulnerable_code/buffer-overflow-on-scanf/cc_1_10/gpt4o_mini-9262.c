//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>

// Function to print spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to print the pyramid pattern
void printPattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        printSpaces(rows - i);

        // Print stars and numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j % 2 == 0) {
                printf(" "); // Print a space for even positions
            } else {
                if (j <= i) {
                    printf("*");
                } else {
                    printf("%d", (j - i) / 2 + 1);
                }
            }
        }
        printf("\n");
    }
}

// Function to print the inverted pyramid
void printInvertedPattern(int rows) {
    for (int i = rows; i >= 1; i--) {
        // Print leading spaces
        printSpaces(rows - i);

        // Print stars and numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j % 2 == 0) {
                printf(" "); // Print a space for even positions
            } else {
                if (j <= i) {
                    printf("*");
                } else {
                    printf("%d", (j - i) / 2 + 1);
                }
            }
        }
        printf("\n");
    }
}

// Function to combine both patterns to create a unique visual
void printCombinedPattern(int rows) {
    printf("Pyramid Pattern:\n");
    printPattern(rows);
    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPattern(rows);
}

// Main function
int main() {
    int rows;

    // User input for number of rows
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &rows);

    if (rows < 1) {
        printf("Please enter a valid number of rows (greater than 0).\n");
        return 1;
    }

    printCombinedPattern(rows);
    return 0;
}