//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: ultraprecise
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;
  
    // Upper part of the diamond
    for (i = 0; i < n; i++) {
        // Printing spaces
        for (space = n - i; space > 1; space--) {
            printf(" ");
        }
        // Printing characters
        for (j = 0; j <= i; j++) {
            printf("%c ", 65 + j); // 65 is 'A' in ASCII
        }
        printf("\n");
    }
    
    // Lower part of the diamond
    for (i = n - 2; i >= 0; i--) {
        // Printing spaces
        for (space = n - i; space > 1; space--) {
            printf(" ");
        }
        // Printing characters
        for (j = 0; j <= i; j++) {
            printf("%c ", 65 + j); // 65 is 'A' in ASCII
        }
        printf("\n");
    }
}

void printReversePyramid(int n) {
    int space, i, j;
  
    for (i = n; i >= 1; i--) {
        // Printing spaces
        for (space = 0; space < n - i; space++) {
            printf(" ");
        }
        // Printing characters
        for (j = 0; j < i; j++) {
            printf("%c ", 65 + j); // 65 is 'A' in ASCII
        }
        printf("\n");
    }
}

void printIncreasingNumbers(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printDecreasingNumbers(int n) {
    int i, j;

    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printTriangle(int n) {
    int space, i, j;
  
    for (i = 1; i <= n; i++) {
        // Printing spaces for triangle
        for (space = n; space > i; space--) {
            printf(" ");
        }
        // Printing stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int rows;

    // Diamond pattern
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &rows);
    printDiamond(rows);
    
    printf("\n");

    // Reverse Pyramid pattern
    printf("Enter the number of rows for the reverse pyramid pattern: ");
    scanf("%d", &rows);
    printReversePyramid(rows);

    printf("\n");

    // Increasing numbers pattern
    printf("Enter the number of rows for increasing numbers pattern: ");
    scanf("%d", &rows);
    printIncreasingNumbers(rows);

    printf("\n");

    // Decreasing numbers pattern
    printf("Enter the number of rows for decreasing numbers pattern: ");
    scanf("%d", &rows);
    printDecreasingNumbers(rows);

    printf("\n");

    // Triangle pattern
    printf("Enter the number of rows for the triangle pattern: ");
    scanf("%d", &rows);
    printTriangle(rows);

    return 0;
}