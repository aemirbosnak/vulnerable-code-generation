//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printDiamond(int n);
void printPyramid(int n);
void printSquare(int n);
void printTriangle(int n);
void printReverseTriangle(int n);
void printHollowSquare(int n);
void printHollowDiamond(int n);

int main() {
    int choice, size;

    printf("Welcome to the Pattern Printing Program!\n");
    printf("Please choose the pattern you want to print:\n");
    printf("1. Diamond\n");
    printf("2. Pyramid\n");
    printf("3. Square\n");
    printf("4. Triangle\n");
    printf("5. Reverse Triangle\n");
    printf("6. Hollow Square\n");
    printf("7. Hollow Diamond\n");
    printf("8. Exit\n");

    while (1) {
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        if (choice == 8) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter the size: ");
        scanf("%d", &size);

        switch (choice) {
            case 1:
                printDiamond(size);
                break;
            case 2:
                printPyramid(size);
                break;
            case 3:
                printSquare(size);
                break;
            case 4:
                printTriangle(size);
                break;
            case 5:
                printReverseTriangle(size);
                break;
            case 6:
                printHollowSquare(size);
                break;
            case 7:
                printHollowDiamond(size);
                break;
            default:
                printf("This should never happen!\n");
        }
        printf("\n");
    }

    return 0;
}

void printDiamond(int n) {
    int space, i, j;
    for (i = 0; i < n; i++) {
        for (space = n - i; space > 1; space--) {
            printf(" ");
        }
        for (j = 0; j <= (2 * i); j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = n - 1; i > 0; i--) {
        for (space = n - i; space > 0; space--) {
            printf(" ");
        }
        for (j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int space = n - i; space > 1; space--) {
            printf(" ");
        }
        for (int j = 0; j <= (2 * i); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printReverseTriangle(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printHollowDiamond(int n) {
    for (int i = 0; i < n; i++) {
        for (int space = n - i; space > 1; space--) {
            printf(" ");
        }
        if (i == 0) {
            printf("*\n");
            continue;
        }
        for (int j = 0; j <= (2 * i); j++) {
            if (j == 0 || j == (2 * i)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int space = n - i; space > 1; space--) {
            printf(" ");
        }
        if (i == 0) {
            printf("*\n");
            continue;
        }
        for (int j = 0; j <= (2 * i); j++) {
            if (j == 0 || j == (2 * i)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}