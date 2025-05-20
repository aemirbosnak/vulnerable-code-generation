//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>

void printTriangle(int rows) {
    printf("\nTriangle Pattern:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int rows) {
    printf("\nInverted Triangle Pattern:\n");
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDiamond(int rows) {
    printf("\nDiamond Pattern:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = rows - 1; i >= 1; i--) {
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHollowSquare(int size) {
    printf("\nHollow Square Pattern:\n");
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printPyramid(int rows) {
    printf("\nPyramid Pattern:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Select a pattern to print:\n");
    printf("1. Triangle\n");
    printf("2. Inverted Triangle\n");
    printf("3. Diamond\n");
    printf("4. Hollow Square\n");
    printf("5. Pyramid\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    printf("Enter the size (number of rows/lines): ");
    scanf("%d", &size);

    switch (choice) {
        case 1:
            printTriangle(size);
            break;
        case 2:
            printInvertedTriangle(size);
            break;
        case 3:
            printDiamond(size);
            break;
        case 4:
            printHollowSquare(size);
            break;
        case 5:
            printPyramid(size);
            break;
        default:
            printf("Invalid choice! Please select a number between 1 and 5.\n");
            break;
    }

    return 0;
}