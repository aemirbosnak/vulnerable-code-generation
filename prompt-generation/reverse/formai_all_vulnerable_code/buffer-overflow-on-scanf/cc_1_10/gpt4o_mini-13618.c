//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

void printSpaces(int count) {
    for(int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printDiamond(int size) {
    // Print the upper part of the diamond
    for(int i = 0; i < size; i++) {
        printSpaces(size - i - 1);
        for(int j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower part of the diamond
    for(int i = size - 2; i >= 0; i--) {
        printSpaces(size - i - 1);
        for(int j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int height) {
    // Print pyramid structure
    for(int i = 0; i < height; i++) {
        printSpaces(height - i - 1);
        for(int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int height) {
    // Print inverted pyramid structure
    for(int i = height; i > 0; i--) {
        printSpaces(height - i);
        for(int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowSquare(int size) {
    // Print a hollow square
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printRhombus(int height) {
    // Print a rhombus
    for(int i = 0; i < height; i++) {
        printSpaces(height - i - 1);
        for(int j = 0; j < height; j++) {
            if(j == 0 || j == height - 1 || i == 0 || i == height - 1) {
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

    printf("Choose the pattern to print:\n");
    printf("1. Diamond\n");
    printf("2. Pyramid\n");
    printf("3. Inverted Pyramid\n");
    printf("4. Hollow Square\n");
    printf("5. Rhombus\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter size for Diamond pattern: ");
            scanf("%d", &size);
            printDiamond(size);
            break;
        case 2:
            printf("Enter height for Pyramid pattern: ");
            scanf("%d", &size);
            printPyramid(size);
            break;
        case 3:
            printf("Enter height for Inverted Pyramid pattern: ");
            scanf("%d", &size);
            printInvertedPyramid(size);
            break;
        case 4:
            printf("Enter size for Hollow Square pattern: ");
            scanf("%d", &size);
            if(size < 2) {
                printf("Size should be at least 2 for a hollow square.\n");
            } else {
                printHollowSquare(size);
            }
            break;
        case 5:
            printf("Enter height for Rhombus pattern: ");
            scanf("%d", &size);
            printRhombus(size);
            break;
        default:
            printf("Invalid choice. Please select a number between 1 and 5.\n");
            break;
    }

    return 0;
}