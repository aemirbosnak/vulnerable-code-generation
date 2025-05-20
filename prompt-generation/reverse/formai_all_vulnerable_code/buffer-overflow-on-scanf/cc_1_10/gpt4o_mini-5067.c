//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

void printDiamond(int n) {
    int space, star;

    // Upper part of the diamond
    for (int i = 0; i < n; i++) {
        // Printing leading spaces
        for (space = n - i; space > 1; space--) {
            printf(" ");
        }
        // Printing stars
        for (star = 0; star <= i; star++) {
            printf("* ");
        }
        // Newline after each row
        printf("\n");
    }

    // Lower part of the diamond
    for (int i = n - 1; i > 0; i--) {
        // Printing leading spaces
        for (space = n - i; space > 0; space--) {
            printf(" ");
        }
        // Printing stars
        for (star = 0; star < i; star++) {
            printf("* ");
        }
        // Newline after each row
        printf("\n");
    }
}

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
        // Printing leading spaces
        for (int space = n - i; space > 1; space--) {
            printf(" ");
        }
        // Printing stars
        for (int star = 0; star <= i; star++) {
            printf("* ");
        }
        // Newline after each row
        printf("\n");
    }
}

void printHeart(int n) {
    int i, j;

    // Upper part of heart
    for (i = n / 2; i <= n; i += 2) {
        for (j = 1; j < n - i; j += 2) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of heart
    for (i = n; i >= 1; i--) {
        for (j = i; j < n; j++) {
            printf(" ");
        }
        for (j = 1; j <= (i * 2) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Welcome to the Pattern Printing Program!\n");
    printf("Please choose a pattern to print:\n");
    printf("1. Diamond Pattern\n");
    printf("2. Pyramid Pattern\n");
    printf("3. Heart Pattern\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the size of the diamond (odd number): ");
            scanf("%d", &size);
            if (size % 2 == 0) {
                size++; // Ensure it's odd
            }
            printDiamond((size / 2) + 1);
            break;
        case 2:
            printf("Enter the height of the pyramid: ");
            scanf("%d", &size);
            printPyramid(size);
            break;
        case 3:
            printf("Enter the size of the heart pattern: ");
            scanf("%d", &size);
            printHeart(size);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            break;
    }

    printf("Thank you for using the Pattern Printing Program!\n");
    return 0;
}