//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;

    // Print the top part of the diamond
    for (i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the bottom part of the diamond
    for (i = n - 1; i >= 1; i--) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    int i, j, k;

    for (i = n; i >= 1; i--) {
        for (j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = 2; i <= n; i++) {
        for (j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int i, j, space;

    for (i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i % 2);
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    printf("Enter the height for pattern (greater than 1): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Height must be greater than 1.\n");
        return 1;
    }

    printf("\nDiamond Pattern:\n");
    printDiamond(n);

    printf("\nHourglass Pattern:\n");
    printHourglass(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    return 0;
}