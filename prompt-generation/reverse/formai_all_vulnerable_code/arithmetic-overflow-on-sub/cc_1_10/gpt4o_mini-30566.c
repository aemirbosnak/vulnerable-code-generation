//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;

    // Upper half of the diamond
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j < (2 * i + 1); j++)
            printf("*");
        printf("\n");
    }

    // Lower half of the diamond
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j < (2 * i + 1); j++)
            printf("*");
        printf("\n");
    }
}

void printPyramid(int n) {
    int space, i, j;

    // Printing pyramid pattern
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++)
            printf(" ");
        for (j = 0; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int space, i, j;

    // Printing inverted pyramid pattern
    for (i = n; i >= 1; i--) {
        for (space = 0; space < n - i; space++)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printHollowSquare(int n) {
    int i, j;

    // Loop for rows
    for (i = 0; i < n; i++) {
        // Loop for columns
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printRightAngledTriangle(int n) {
    int i, j;

    // Printing right angled triangle
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

void printAlphabetTriangle(int n) {
    int i, j;
    char ch;

    // Printing alphabet triangle
    for (i = 0; i < n; i++) {
        ch = 'A';  // Reset character to A for each row
        for (j = 0; j <= i; j++) {
            printf("%c ", ch);
            ch++;  // Move to the next character
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the size for the diamond pattern: ");
    scanf("%d", &size);
    printf("\nDiamond Pattern:\n");
    printDiamond(size);

    printf("\nEnter the size for the pyramid pattern: ");
    scanf("%d", &size);
    printf("\nPyramid Pattern:\n");
    printPyramid(size);

    printf("\nEnter the size for the inverted pyramid pattern: ");
    scanf("%d", &size);
    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(size);

    printf("\nEnter the size for hollow square pattern: ");
    scanf("%d", &size);
    printf("\nHollow Square Pattern:\n");
    printHollowSquare(size);

    printf("\nEnter the size for right-angled triangle pattern: ");
    scanf("%d", &size);
    printf("\nRight Angled Triangle Pattern:\n");
    printRightAngledTriangle(size);

    printf("\nEnter the size for alphabet triangle pattern: ");
    scanf("%d", &size);
    printf("\nAlphabet Triangle Pattern:\n");
    printAlphabetTriangle(size);

    return 0;
}