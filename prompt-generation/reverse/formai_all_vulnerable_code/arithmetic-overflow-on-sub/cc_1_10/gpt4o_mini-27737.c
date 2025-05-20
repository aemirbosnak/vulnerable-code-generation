//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

void printTriangle(int n) {
    int space, rows, stars;

    for (rows = 0; rows <= n; rows++) {
        for (space = n - rows; space > 0; space--) {
            printf(" ");
        }
        for (stars = 0; stars < (2 * rows - 1); stars++) {
            printf("*");
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    int space, rows, stars;

    // Upper part of Diamond
    for (rows = 0; rows <= n; rows++) {
        for (space = n - rows; space > 0; space--) {
            printf(" ");
        }
        for (stars = 0; stars < (2 * rows - 1); stars++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of Diamond
    for (rows = n - 1; rows > 0; rows--) {
        for (space = n - rows; space > 0; space--) {
            printf(" ");
        }
        for (stars = 0; stars < (2 * rows - 1); stars++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    int space, rows, stars;

    for (rows = n; rows > 0; rows--) {
        for (space = n - rows; space > 0; space--) {
            printf(" ");
        }
        for (stars = 0; stars < (2 * rows - 1); stars++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int space, rows, stars;

    for (rows = 0; rows < n; rows++) {
        for (space = n - rows - 1; space > 0; space--) {
            printf(" ");
        }
        for (stars = 0; stars < (2 * rows + 1); stars++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSpecialPattern(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void printNumberPyramid(int n) {
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = n; j > i; j--) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("Pattern Printing Program\n");
    printf("------------------------\n");
    printf("1. Triangle\n");
    printf("2. Diamond\n");
    printf("3. Inverted Triangle\n");
    printf("4. Pyramid\n");
    printf("5. Special Number Pattern\n");
    printf("6. Hollow Square\n");
    printf("7. Number Pyramid\n");
    printf("Choose a pattern to print (1-7): ");
    scanf("%d", &choice);

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    switch (choice) {
        case 1:
            printf("\nTriangle Pattern:\n");
            printTriangle(size);
            break;
        case 2:
            printf("\nDiamond Pattern:\n");
            printDiamond(size);
            break;
        case 3:
            printf("\nInverted Triangle Pattern:\n");
            printInvertedTriangle(size);
            break;
        case 4:
            printf("\nPyramid Pattern:\n");
            printPyramid(size);
            break;
        case 5:
            printf("\nSpecial Number Pattern:\n");
            printSpecialPattern(size);
            break;
        case 6:
            printf("\nHollow Square Pattern:\n");
            printHollowSquare(size);
            break;
        case 7:
            printf("\nNumber Pyramid Pattern:\n");
            printNumberPyramid(size);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}