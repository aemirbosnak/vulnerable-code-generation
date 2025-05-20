//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h>

void printDiamond(int n) {
    int space;

    // Print upper triangle
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print asterisks in odd counts
        for (int j = 1; j <= (2 * i) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print lower triangle
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print asterisks in odd counts
        for (int j = 1; j <= (2 * i) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int rows;

    // Input number of rows for diamond
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &rows);

    // Validate input
    if (rows <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    printf("\nDiamond Pattern:\n\n");
    printDiamond(rows);

    return 0;
}