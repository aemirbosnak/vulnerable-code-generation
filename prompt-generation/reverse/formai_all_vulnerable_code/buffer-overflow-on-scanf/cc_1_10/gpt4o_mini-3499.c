//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

// Function to print the pyramid pattern
void printPyramid(int lines) {
    printf("\nPyramid Pattern:\n");
    
    for (int i = 1; i <= lines; i++) {
        // Print spaces
        for (int j = i; j < lines; j++) {
            printf(" ");
        }
        // Print asterisks
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the number pattern
void printNumberPattern(int lines) {
    printf("\nNumber Pattern:\n");
    
    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

// Function to print the reverse pyramid pattern
void printReversePyramid(int lines) {
    printf("\nReverse Pyramid Pattern:\n");
    
    for (int i = lines; i >= 1; i--) {
        // Print spaces
        for (int j = lines; j > i; j--) {
            printf(" ");
        }
        // Print asterisks
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function
int main() {
    int lines;

    // Get user input for the number of lines
    printf("Enter the number of lines for the patterns: ");
    scanf("%d", &lines);
    
    // Validating input
    if (lines <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    // Call the functions to print patterns
    printPyramid(lines);
    printNumberPattern(lines);
    printReversePyramid(lines);

    return 0;
}