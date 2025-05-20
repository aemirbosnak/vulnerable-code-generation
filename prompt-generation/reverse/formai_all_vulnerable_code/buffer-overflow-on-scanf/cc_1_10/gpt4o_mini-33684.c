//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Ada Lovelace
#include <stdio.h>

void printDiamond(int n) {
    int i, j;
    
    // Print upper part of diamond
    for (i = 1; i <= n; i++) {
        // Print spaces
        for (j = i; j < n; j++)
            printf(" ");
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }

    // Print lower part of diamond
    for (i = n - 1; i >= 1; i--) {
        // Print spaces
        for (j = n; j > i; j--)
            printf(" ");
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

void printSquare(int size) {
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Print border of the square
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printHollowTriangle(int rows) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j <= rows; j++) {
            // Print hollow edges of triangle
            if (j == 0 || j == rows - i - 1 || i == rows - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printPattern(int n) {
    printf("\nDiamond Pattern:\n");
    printDiamond(n);
    
    printf("\nSquare Pattern:\n");
    printSquare(n);
    
    printf("\nHollow Triangle Pattern:\n");
    printHollowTriangle(n);
}

int main() {
    int n;
    printf("Enter the number of rows for the patterns (greater than 1): ");
    scanf("%d", &n);

    // Error handling for invalid input
    if (n < 2) {
        printf("Please enter a value greater than 1.\n");
        return 1;
    }

    printPattern(n);
    return 0;
}