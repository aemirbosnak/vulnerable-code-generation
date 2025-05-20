//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>

void printDiagonals(int size);
void printXPattern(int size);
void printPyramid(int height);
void printReverseTriangle(int height);

int main() {
    int size, height;

    // Print diagonal pattern
    printf("Enter the size for the diagonal pattern: ");
    scanf("%d", &size);
    printDiagonals(size);

    // Print X pattern
    printf("Enter the size for the X pattern: ");
    scanf("%d", &size);
    printXPattern(size);

    // Print pyramid
    printf("Enter the height for the pyramid: ");
    scanf("%d", &height);
    printPyramid(height);

    // Print reverse triangle
    printf("Enter the height for the reverse triangle: ");
    scanf("%d", &height);
    printReverseTriangle(height);

    return 0;
}

void printDiagonals(int size) {
    printf("\nDiagonal Pattern:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j || j == size - i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printXPattern(int size) {
    printf("\nX Pattern:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i || j == size - i - 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printPyramid(int height) {
    printf("\nPyramid Pattern:\n");
    for (int i = 0; i < height; i++) {
        for (int j = height - i; j > 1; j--) {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printReverseTriangle(int height) {
    printf("\nReverse Triangle Pattern:\n");
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}