//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

void printStarPattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        
        // Print numbers in increasing order
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Print asterisks
        for (int j = 1; j < i; j++) {
            printf("* ");
        }

        // Print numbers in decreasing order
        for (int j = i; j > 0; j--) {
            printf("%d ", j);
        }
        
        printf("\n");
    }
}

void printDiamondPattern(int n) {
    // upper part of diamond
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i + 1; j--) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // lower part of diamond
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n; j > i + 1; j--) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int rows;
    int diamondSize;

    printf("Enter the number of rows for the star-number pattern: ");
    scanf("%d", &rows);
    printStarPattern(rows);
    
    printf("Enter the size for the diamond pattern: ");
    scanf("%d", &diamondSize);
    printDiamondPattern(diamondSize);

    return 0;
}