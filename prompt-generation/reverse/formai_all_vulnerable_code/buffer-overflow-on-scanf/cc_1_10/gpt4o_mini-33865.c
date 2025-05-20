//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>

void printDiamond(int n) {
    int spaces, stars;
    
    // Upper part of the diamond
    for (int i = 1; i <= n; i++) {
        spaces = n - i;
        stars = 2 * i - 1;

        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int j = 0; j < stars; j++)
            printf("*");
        printf("\n");
    }

    // Lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        spaces = n - i;
        stars = 2 * i - 1;

        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int j = 0; j < stars; j++)
            printf("*");
        printf("\n");
    }
}

void printSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++)
            printf(" ");
        for (int j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--)
            printf(" ");
        for (int j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

void printHourglass(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 0; j < (2 * (n - i) - 1); j++)
            printf("*");
        printf("\n");
    }
}

void printAllPatterns(int size) {
    printf("\nDiamond Pattern:\n");
    printDiamond(size);
    
    printf("\nSquare Pattern:\n");
    printSquare(size);
    
    printf("\nTriangle Pattern:\n");
    printTriangle(size);
    
    printf("\nPyramid Pattern:\n");
    printPyramid(size);
    
    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(size);
    
    printf("\nHourglass Pattern:\n");
    printHourglass(size);
}

int main() {
    int size;

    printf("Enter the size for the patterns (positive integer): ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    
    printAllPatterns(size);
    
    return 0;
}