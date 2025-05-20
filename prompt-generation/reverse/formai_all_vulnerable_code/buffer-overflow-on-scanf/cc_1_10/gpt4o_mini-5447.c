//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}

void printStars(int stars) {
    for (int i = 0; i < stars; i++) {
        printf("* ");
    }
}

void printUpperDiamond(int n) {
    for (int i = 0; i < n; i++) {
        printSpaces(n - i - 1);
        printStars(i + 1);
        printf("\n");
    }
}

void printLowerDiamond(int n) {
    for (int i = n - 1; i > 0; i--) {
        printSpaces(n - i);
        printStars(i);
        printf("\n");
    }
}

void printDiamond(int n) {
    printUpperDiamond(n);
    printLowerDiamond(n);
}

void printHollowSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printFilledSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int choice, n;

    while(1) {
        printf("Pattern Printing Menu:\n");
        printf("1. Diamond\n");
        printf("2. Hollow Square\n");
        printf("3. Filled Square\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of layers for the diamond: ");
                scanf("%d", &n);
                printDiamond(n);
                break;

            case 2:
                printf("Enter the size of the hollow square: ");
                scanf("%d", &n);
                printHollowSquare(n);
                break;

            case 3:
                printf("Enter the size of the filled square: ");
                scanf("%d", &n);
                printFilledSquare(n);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}