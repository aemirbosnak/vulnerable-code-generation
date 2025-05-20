//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

void printPyramid(int n) {
    int space, i, j;
    // Loop through each row
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (space = 1; space <= (n - i); space++)
            printf(" ");
        // Print increasing stars
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        // Move to the next line
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int space, i, j;
    // Loop through each row
    for (i = n; i >= 1; i--) {
        // Print leading spaces
        for (space = 0; space < (n - i); space++)
            printf(" ");
        // Print decreasing stars
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        // Move to the next line
        printf("\n");
    }
}

void printDiamond(int n) {
    // First part of diamond
    printPyramid(n);
    // Second part of diamond
    printInvertedPyramid(n - 1);
}

void printHollowSquare(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            // Print "*" only for the borders
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printFilledSquare(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRightAngledTriangle(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRightAngledTriangleWithNumbers(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printNumberPyramid(int n) {
    int space, i, j;
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (space = 1; space <= (n - i); space++)
            printf(" ");
        // Print numbers in increasing order
        for (j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Welcome to the Pattern Printing Program!\n");
    printf("Choose a pattern to print:\n");
    printf("1. Pyramid\n");
    printf("2. Inverted Pyramid\n");
    printf("3. Diamond\n");
    printf("4. Hollow Square\n");
    printf("5. Filled Square\n");
    printf("6. Right Angled Triangle\n");
    printf("7. Right Angled Triangle with Numbers\n");
    printf("8. Number Pyramid\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    switch (choice) {
        case 1:
            printf("Pyramid Pattern of height %d:\n", size);
            printPyramid(size);
            break;
        case 2:
            printf("Inverted Pyramid Pattern of height %d:\n", size);
            printInvertedPyramid(size);
            break;
        case 3:
            printf("Diamond Pattern of height %d:\n", size);
            printDiamond(size);
            break;
        case 4:
            printf("Hollow Square Pattern of size %d:\n", size);
            printHollowSquare(size);
            break;
        case 5:
            printf("Filled Square Pattern of size %d:\n", size);
            printFilledSquare(size);
            break;
        case 6:
            printf("Right Angled Triangle Pattern of height %d:\n", size);
            printRightAngledTriangle(size);
            break;
        case 7:
            printf("Right Angled Triangle with Numbers Pattern of height %d:\n", size);
            printRightAngledTriangleWithNumbers(size);
            break;
        case 8:
            printf("Number Pyramid Pattern of height %d:\n", size);
            printNumberPyramid(size);
            break;
        default:
            printf("Invalid choice! Please select a valid pattern.\n");
    }

    return 0;
}