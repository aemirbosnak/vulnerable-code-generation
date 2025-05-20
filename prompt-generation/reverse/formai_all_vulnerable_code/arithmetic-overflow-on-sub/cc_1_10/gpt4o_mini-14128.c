//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>

void printUpperTriangle(int n) {
    int space, stars;

    for (int i = 0; i < n; i++) {
        // Print spaces
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }

        // Print stars
        for (stars = 0; stars <= i; stars++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printLowerTriangle(int n) {
    int space, stars;

    for (int i = n - 1; i >= 0; i--) {
        // Print spaces
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }

        // Print stars
        for (stars = 0; stars <= i; stars++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    printUpperTriangle(n);
    printLowerTriangle(n);
}

void printRhombus(int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int i, j;

    for (i = n; i > 0; i--) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
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

void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printNumberTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printCharacterPyramid(int n) {
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        ch = 'A';
        for (int j = 0; j <= i; j++) {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for the patterns (1-20): ");
    scanf("%d", &n);

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nRhombus Pattern:\n");
    printRhombus(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(n);

    printf("\nSquare Pattern:\n");
    printSquare(n);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);

    printf("\nNumber Triangle:\n");
    printNumberTriangle(n);

    printf("\nCharacter Pyramid:\n");
    printCharacterPyramid(n);

    return 0;
}