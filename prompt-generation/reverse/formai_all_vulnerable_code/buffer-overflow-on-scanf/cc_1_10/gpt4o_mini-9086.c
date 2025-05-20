//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

void printPattern(int rows) {
    // Outer loop for rows
    for (int i = 0; i < rows; i++) {
        // Print leading spaces
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // Print numbers
        for (int j = 1; j <= i + 1; j++) {
            printf("%d ", j);
        }

        // Print letters
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            printf("%c ", ch);
        }

        // New line after each row
        printf("\n");
    }
}

void printBanner() {
    printf("    * * * * * * * * * * * * * * * * *\n");
    printf("    *      SHERLOCK HOLMES        *\n");
    printf("    *     PATTERN PRINTER         *\n");
    printf("    * * * * * * * * * * * * * * * * *\n\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("This program generates a pattern of numbers and letters.\n");
    printf("You will enter the number of rows for the pattern.\n");
}

int main() {
    int rows;

    // Print the banner
    printBanner();
    
    // Show the instructions
    printInstructions();
    
    // Ask user for the number of rows
    printf("Enter the number of rows (1-26): ");
    scanf("%d", &rows);

    // Validate input to ensure it does not exceed limits
    if (rows < 1 || rows > 26) {
        printf("Please enter a number between 1 and 26.\n");
        return 1;
    }

    // Print the pattern
    printPattern(rows);

    return 0;
}