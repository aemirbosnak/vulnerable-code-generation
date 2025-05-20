//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>

void printPattern(int n) {
    // Loop to print upper part of the pattern
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print left half of the diamond
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Loop to print lower part of the pattern
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print right half of the diamond
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printReversePyramid(int height) {
    for (int i = height; i >= 1; i--) {
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2*i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHollowSquare(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, n, height, size;

    printf("Pattern Printing Program\n");
    printf("Choose a pattern to print:\n");
    printf("1. Diamond\n");
    printf("2. Hollow Square\n");
    printf("3. Reverse Pyramid\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the height of diamond: ");
                scanf("%d", &n);
                printDiamond(n);
                break;
            case 2:
                printf("Enter the size of hollow square: ");
                scanf("%d", &size);
                printHollowSquare(size);
                break;
            case 3:
                printf("Enter the height of reverse pyramid: ");
                scanf("%d", &height);
                printReversePyramid(height);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter again (1-4): ");
        }

        printf("Choose another pattern to print or exit:\n");
        printf("1. Diamond\n");
        printf("2. Hollow Square\n");
        printf("3. Reverse Pyramid\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
    }

    return 0;
}