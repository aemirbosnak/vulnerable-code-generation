//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>

// Function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Function to print binary representation pattern
void printBinaryPattern(int n) {
    for (int i = 0; i <= n; i++) {
        // Print leading spaces for symmetry
        printSpaces(n - i);
        
        // Print binary pattern for the current row
        for (int j = 0; j < (1 << i); j++) { // 1 << i means 2 raised to the power i
            printf("%d", (j % 2)); // Print 0 or 1
        }
        
        // Move to the next line after printing a row
        printf("\n");
    }
}

// Function to print the mirrored pattern
void printMirroredPattern(int n) {
    for (int i = n - 1; i >= 0; i--) {
        // Print leading spaces for symmetry
        printSpaces(n - i);
        
        // Print binary pattern for the current row
        for (int j = 0; j < (1 << i); j++) {
            printf("%d", (j % 2));
        }
        
        // Move to the next line after printing a row
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter number of rows for the binary pattern (max 10): ");
    scanf("%d", &rows);
    
    // Limit the maximum rows to avoid overflow
    if (rows > 10) {
        printf("The maximum number of rows allowed is 10.\n");
        return 1; 
    }

    printf("\nBinary Pattern:\n");
    printBinaryPattern(rows);
    
    printf("\nMirrored Binary Pattern:\n");
    printMirroredPattern(rows);
    
    // Final message to signify end of program
    printf("\nData Transmission Complete. Patterns have been printed!\n");
    
    return 0;
}