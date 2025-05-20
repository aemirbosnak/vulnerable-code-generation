//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>

void printPattern(int n) {
    int space, i, j, k;
    
    // Loop for each row of the pyramid
    for (i = 0; i < n; i++) {
        // Print leading spaces
        for (space = 0; space < n - i - 1; space++) {
            printf("  "); // Two spaces for better alignment
        }
        
        // Print stars for left side of the pyramid
        for (j = 0; j <= i; j++) {
            printf("* ");
        }

        // Print the number for the center
        printf("%d ", i + 1);
        
        // Print stars for right side of the pyramid
        for (k = i; k > 0; k--) {
            printf("* ");
        }

        // Move to the next line after printing each row
        printf("\n");
    }
}

void printNumberPattern(int n) {
    int i, j;
    
    // Generate a number pattern
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows for the star pattern: ");
    scanf("%d", &rows);
    printf("\nUnique Star and Number Pattern:\n");
    printPattern(rows);

    printf("\nNumber Pattern up to %d:\n", rows);
    printNumberPattern(rows);

    return 0;
}