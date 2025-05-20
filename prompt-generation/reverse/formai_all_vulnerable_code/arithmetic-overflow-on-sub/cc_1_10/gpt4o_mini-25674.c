//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

// Function to print diamond pattern
void printDiamond(int n) {
    int space, i, j;

    // Upper part of diamond
    for(i = 0; i < n; i++) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
    
    // Lower part of diamond
    for(i = n - 2; i >= 0; i--) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
}

// Function to print pyramid pattern
void printPyramid(int n) {
    int i, j, space;

    for(i = 0; i < n; i++) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

// Function to print inverted pyramid pattern
void printInvertedPyramid(int n) {
    int i, j, space;

    for(i = n; i >= 1; i--) {
        for(space = 0; space < n - i; space++)
            printf(" ");
        for(j = 0; j < i; j++)
            printf("* ");
        printf("\n");
    }
}

// Function to print hollow square pattern
void printHollowSquare(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to print right-angled triangle pattern
void printRightAngledTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    printf("Enter the number of levels (for diamond/pyramid patterns): ");
    scanf("%d", &n);
    
    printf("\nDiamond Pattern:\n");
    printDiamond(n);
    
    printf("\nPyramid Pattern:\n");
    printPyramid(n);
    
    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(n);
    
    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);
    
    printf("\nRight-Angled Triangle Pattern:\n");
    printRightAngledTriangle(n);
    
    return 0;
}