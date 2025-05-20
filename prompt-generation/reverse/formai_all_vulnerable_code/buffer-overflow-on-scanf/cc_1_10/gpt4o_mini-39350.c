//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

// Function to print spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to print asterisks in a diamond pattern
void printDiamondPattern(int n) {
    // Upper part of the diamond
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        printSpaces(n - i - 1);
        
        // Print asterisks
        for (int j = 0; j <= i * 2; j++) {
            printf("*");
        }
        
        // Move to the next line
        printf("\n");
    }
    
    // Lower part of the diamond
    for (int i = n - 2; i >= 0; i--) {
        // Print leading spaces
        printSpaces(n - i - 1);
        
        // Print asterisks
        for (int j = 0; j <= i * 2; j++) {
            printf("*");
        }
        
        // Move to the next line
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    
    // Input from the user
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &n);
    
    // Validate input
    if (n < 1) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }
    
    // Print the diamond pattern
    printDiamondPattern(n);
    
    return 0;
}