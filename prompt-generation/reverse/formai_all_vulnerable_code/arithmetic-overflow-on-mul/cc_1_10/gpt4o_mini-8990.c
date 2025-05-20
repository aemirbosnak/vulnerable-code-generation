//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

void printTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int height) {
    for (int i = height; i >= 1; i--) {
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printDiamond(int height) {
    printTriangle(height);
    printInvertedTriangle(height - 1);
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

void printHollowTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (k == 1 || k == (2 * i - 1) || i == height) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printIsoscelesTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < (2 * i) + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRhombus(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * height; j++) {
            if (j == height - 1 - i || j == height - 1 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = height - 2; i >= 0; i--) {
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * height; j++) {
            if (j == height - 1 - i || j == height - 1 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Welcome to the Pattern Printing Program!\n");
    printf("Choose a pattern to print:\n");
    printf("1. Diamond\n");
    printf("2. Hollow Square\n");
    printf("3. Hollow Triangle\n");
    printf("4. Isosceles Triangle\n");
    printf("5. Pyramid\n");
    printf("6. Rhombus\n");

    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter height of diamond: ");
            scanf("%d", &size);
            printDiamond(size);
            break;
        case 2:
            printf("Enter size of hollow square: ");
            scanf("%d", &size);
            printHollowSquare(size);
            break;
        case 3:
            printf("Enter height of hollow triangle: ");
            scanf("%d", &size);
            printHollowTriangle(size);
            break;
        case 4:
            printf("Enter height of isosceles triangle: ");
            scanf("%d", &size);
            printIsoscelesTriangle(size);
            break;
        case 5:
            printf("Enter height of pyramid: ");
            scanf("%d", &size);
            printPyramid(size);
            break;
        case 6:
            printf("Enter height of rhombus: ");
            scanf("%d", &size);
            printRhombus(size);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}