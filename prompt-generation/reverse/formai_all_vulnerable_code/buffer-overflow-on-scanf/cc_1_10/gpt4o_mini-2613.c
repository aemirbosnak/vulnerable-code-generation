//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

// Function to print the mirrored pattern
void printMirroredPattern(int n) {
    int i, j;

    // Loop to generate each row
    for (i = 0; i < n; i++) {
        // First half (Numbers)
        for (j = 0; j < n - i; j++) {
            printf("%d ", j + 1);
        }
        
        // Space in between
        for (j = 0; j < i; j++) {
            printf("  ");
        }
        
        // Second half (Characters)
        for (j = 0; j < n - i; j++) {
            printf("%c ", 'A' + j);
        }
        
        // New line after each row
        printf("\n");
    }

    // Loop for the inverted half of the pattern
    for (i = 1; i < n; i++) {
        // First half (Numbers)
        for (j = 0; j < i + 1; j++) {
            printf("%d ", j + 1);
        }
        
        // Space in between
        for (j = 0; j < n - i - 1; j++) {
            printf("  ");
        }
        
        // Second half (Characters)
        for (j = 0; j < i + 1; j++) {
            printf("%c ", 'A' + j);
        }
        
        // New line after each row
        printf("\n");
    }
}

// Main function to drive the program
int main() {
    int rows;

    // Request user input for rows of the pattern
    printf("Enter the number of rows for the mirrored pattern: ");
    scanf("%d", &rows);

    // Validate the input
    if (rows < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1; // Exit with error
    }

    // Print the mirrored pattern
    printf("\nGenerated Mirrored Pattern:\n");
    printMirroredPattern(rows);

    return 0; // Successful execution
}