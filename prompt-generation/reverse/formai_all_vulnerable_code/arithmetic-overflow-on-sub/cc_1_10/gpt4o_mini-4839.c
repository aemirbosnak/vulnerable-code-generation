//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;
    
    // Print upper part of diamond
    for (i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Print lower part of diamond
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

void printRightTriangle(int n) {
    int i, j;
    
    // Print right-angled triangle
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    int i, j;
    
    // Print inverted triangle
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSquare(int n) {
    int i, j;
    
    // Print square
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    int i, j;
    
    // Print hollow square
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int space, i, j;

    // Print pyramid
    for (i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Welcome to the Pattern Printing Program!\n");
    printf("Please choose a pattern to print:\n");
    printf("1. Diamond\n");
    printf("2. Right Triangle\n");
    printf("3. Inverted Triangle\n");
    printf("4. Square\n");
    printf("5. Hollow Square\n");
    printf("6. Pyramid\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    switch(choice) {
        case 1:
            printf("Printing Diamond of size %d:\n", size);
            printDiamond(size);
            break;
        case 2:
            printf("Printing Right Triangle of size %d:\n", size);
            printRightTriangle(size);
            break;
        case 3:
            printf("Printing Inverted Triangle of size %d:\n", size);
            printInvertedTriangle(size);
            break;
        case 4:
            printf("Printing Square of size %d:\n", size);
            printSquare(size);
            break;
        case 5:
            printf("Printing Hollow Square of size %d:\n", size);
            printHollowSquare(size);
            break;
        case 6:
            printf("Printing Pyramid of size %d:\n", size);
            printPyramid(size);
            break;
        default:
            printf("Invalid choice! Please select a number between 1-6.\n");
    }
    
    return 0;
}