//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: irregular
#include <stdio.h>

void printPattern(int n) {
    // Outer loop for number of rows
    for (int i = 0; i <= n; i++) {
        // Inner loop for leading spaces (to create an irregular pattern)
        for (int j = 0; j < n - i; j++) {
            printf(" "); // Printing spaces
        }
        
        // Inner loop for printing the pattern (stars and numbers)
        for (int k = 0; k <= i; k++) {
            if (k % 2 == 0) {
                printf("* "); // For even index, print *
            } else {
                printf("%d ", i); // For odd index, print the row number
            }
        }
        
        // Move to the next line for the next row
        printf("\n");
    }
    // Inverting the triangle for irregular style
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" "); // Printing spaces
        }
        
        for (int k = 0; k <= i; k++) {
            if (k % 2 == 0) {
                printf("* "); // For even index, print *
            } else {
                printf("%d ", i); // For odd index, print the row number
            }
        }
        
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1; // Exit the program
    }
    
    printf("\nPrinting irregular pattern:\n\n");
    printPattern(n); // Calling the function to print the pattern
    
    return 0; // Normal program termination
}