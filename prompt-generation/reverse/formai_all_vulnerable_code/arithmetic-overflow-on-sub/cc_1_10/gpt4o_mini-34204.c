//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;
    // Upper part of the diamond
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
    // Lower part of the diamond
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
}

void printTriangle(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printReverseTriangle(int n) {
    int i, j;
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printHollowSquare(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int space, i, j;
    for (i = n; i >= 1; i--) {
        for (space = 0; space < n - i; space++)
            printf(" ");
        for (j = 0; j < 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows for the patterns: ");
    scanf("%d", &n);
    
    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nTriangle Pattern:\n");
    printTriangle(n);

    printf("\nReverse Triangle Pattern:\n");
    printReverseTriangle(n);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);

    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(n);

    return 0;
}