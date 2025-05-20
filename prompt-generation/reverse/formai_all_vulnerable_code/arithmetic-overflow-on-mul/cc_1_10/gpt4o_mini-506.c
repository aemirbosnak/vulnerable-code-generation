//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

void printDiamond(int n) {
    int i, j, space;
    
    // Print upper part of diamond
    for (i = 0; i < n; i++) {
        for (space = 0; space < (n - i - 1); space++)
            printf(" ");
        for (j = 0; j <= (2 * i); j++)
            printf("*");
        printf("\n");
    }
    
    // Print lower part of diamond
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < (n - i - 1); space++)
            printf(" ");
        for (j = 0; j <= (2 * i); j++)
            printf("*");
        printf("\n");
    }
}

void printPyramid(int n) {
    int i, j;
    
    // Print pyramid
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++)
            printf(" ");
        for (j = 0; j < (2 * i + 1); j++)
            printf("*");
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int i, j;
    
    // Print inverted pyramid
    for (i = n; i > 0; i--) {
        for (j = 0; j < (n - i); j++)
            printf(" ");
        for (j = 0; j < (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

void printHollowSquare(int n) {
    int i, j;
    
    // Print hollow square
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

void printCheckerboard(int n) {
    int i, j;
    
    // Print checkerboard pattern
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printRightAngleTriangle(int n) {
    int i, j;
    
    // Print right angle triangle
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

void printNumberPyramid(int n) {
    int i, j, num;
    
    // Print number pyramid
    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Pattern Printing Program\n");
    printf("------------------------\n");
    printf("1. Diamond\n");
    printf("2. Pyramid\n");
    printf("3. Inverted Pyramid\n");
    printf("4. Hollow Square\n");
    printf("5. Checkerboard\n");
    printf("6. Right-Angle Triangle\n");
    printf("7. Number Pyramid\n");
    printf("Choose a pattern to print (1-7): ");
    scanf("%d", &choice);

    printf("Enter size: ");
    scanf("%d", &size);
    
    switch (choice) {
        case 1:
            printDiamond(size);
            break;
        case 2:
            printPyramid(size);
            break;
        case 3:
            printInvertedPyramid(size);
            break;
        case 4:
            printHollowSquare(size);
            break;
        case 5:
            printCheckerboard(size);
            break;
        case 6:
            printRightAngleTriangle(size);
            break;
        case 7:
            printNumberPyramid(size);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}