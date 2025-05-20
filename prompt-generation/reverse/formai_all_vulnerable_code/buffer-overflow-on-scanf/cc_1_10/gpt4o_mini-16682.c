//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

void printDiamond(int size) {
    int spaces, stars, i;
    
    // Upper half of the diamond
    for (i = 0; i < size; i++) {
        spaces = size - i - 1; // Calculate the number of leading spaces
        stars = 2 * i + 1;     // Calculate the number of stars
        
        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 0; j < stars; j++) {
            printf("*");
        }
        printf("\n"); // New line after each row
    }
    
    // Lower half of the diamond
    for (i = size - 2; i >= 0; i--) {
        spaces = size - i - 1; // Calculate the number of leading spaces
        stars = 2 * i + 1;     // Calculate the number of stars
        
        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 0; j < stars; j++) {
            printf("*");
        }
        printf("\n"); // New line after each row
    }
}

int main() {
    int size;

    // Prompt user for diamond size
    printf("Enter the size of the diamond: ");
    scanf("%d", &size);
    
    // Ensure size is positive
    if (size <= 0) {
        printf("Size must be a positive integer!\n");
        return 1;
    }

    // Function to print the diamond
    printDiamond(size);
    
    return 0;
}