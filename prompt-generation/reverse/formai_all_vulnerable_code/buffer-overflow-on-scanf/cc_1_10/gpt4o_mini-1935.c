//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>

void printDiamond(int n) {
    int i, j, space;

    // Print top half of diamond
    for (i = 1; i <= n; i++) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print numbers
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    // Print bottom half of diamond
    for (i = n - 1; i >= 1; i--) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print numbers
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int i, j, space;

    for (i = 1; i <= n; i++) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSquare(int size) {
    int i, j;
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowTriangle(int n) {
    int i, j, space;
    
    for (i = 1; i <= n; i++) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars and spaces
        for (j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printNumberPyramid(int n) {
    int i, j, space;
    
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print increasing numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Print decreasing numbers
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Pattern Printing Program\n");
    printf("------------------------\n");

    // Input for diamond
    printf("Enter the number of rows for diamond: ");
    scanf("%d", &n);
    printDiamond(n);

    // Input for pyramid
    printf("\nEnter the number of rows for pyramid: ");
    scanf("%d", &n);
    printPyramid(n);

    // Input for square
    printf("\nEnter the size of square: ");
    scanf("%d", &n);
    printSquare(n);

    // Input for hollow triangle
    printf("\nEnter the number of rows for hollow triangle: ");
    scanf("%d", &n);
    printHollowTriangle(n);

    // Input for number pyramid
    printf("\nEnter the number of rows for number pyramid: ");
    scanf("%d", &n);
    printNumberPyramid(n);

    printf("\nPattern printing completed!\n");

    return 0;
}