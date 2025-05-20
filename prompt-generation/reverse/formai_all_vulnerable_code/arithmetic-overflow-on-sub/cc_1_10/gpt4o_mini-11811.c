//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

// Function to print patterns of asterisks in a creative way
void printDiamond(int n) {
    int spaces = n - 1;

    // Upper half of the diamond
    for (int i = 1; i <= n; i++) {
        // Printing spaces
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces--;
        
        // Printing stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the diamond
    spaces = 1;
    for (int i = 1; i <= n - 1; i++) {
        // Printing spaces
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces++;

        // Printing stars
        for (int j = 1; j <= (2 * (n - i) - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int spaces = n - 1;

    // Loop through rows
    for (int i = 1; i <= n; i++) {
        // Printing spaces
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces--;

        // Printing numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    // Loop through rows
    for (int i = n; i >= 1; i--) {
        // Printing numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printHollowDiamond(int n) {
    int spaces = n - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces--;

        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    spaces = 1;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        spaces++;

        for (int j = 1; j <= (2 * (n - i) - 1); j++) {
            if (j == 1 || j == (2 * (n - i) - 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Taking input from user
    printf("Enter the number of rows for the patterns: ");
    scanf("%d", &n);

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(n);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);

    printf("\nHollow Diamond Pattern:\n");
    printHollowDiamond(n);

    return 0;
}