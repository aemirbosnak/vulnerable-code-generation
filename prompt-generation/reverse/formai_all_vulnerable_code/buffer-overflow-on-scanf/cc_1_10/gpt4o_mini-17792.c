//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>

// Function to print spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to print the upper part of the diamond
void printUpperDiamond(int lines) {
    for (int i = 0; i < lines; i++) {
        printSpaces(lines - i - 1); // Print leading spaces
        for (int j = 0; j <= i; j++) {
            printf("* "); // Print stars with space
        }
        printf("\n"); // Move to the next line
    }
}

// Function to print the lower part of the diamond
void printLowerDiamond(int lines) {
    for (int i = lines - 1; i > 0; i--) {
        printSpaces(lines - i); // Print leading spaces
        for (int j = 0; j < i; j++) {
            printf("* "); // Print stars with space
        }
        printf("\n"); // Move to the next line
    }
}

// Main function
int main() {
    int lines;

    // Prompt user for the number of lines
    printf("Enter the number of lines for the diamond pattern: ");
    scanf("%d", &lines);

    // Validate input
    if (lines <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; // Exit with error code
    }

    // Print the diamond pattern
    printUpperDiamond(lines);
    printLowerDiamond(lines);

    // Add an artistic touch
    printf("    *\n");
    printf("  *   *\n");
    printf(" *     *\n");
    printf("*       *\n");
    printf(" *     *\n");
    printf("  *   *\n");
    printf("    *\n");

    // End message
    printf("Enjoy your beautiful diamond pattern!\n");
    
    return 0; // Successful program termination
}