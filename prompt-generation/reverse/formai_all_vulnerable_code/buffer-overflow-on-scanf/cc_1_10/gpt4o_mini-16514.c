//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

void printDiamond(int n) {
    int space, row, i;

    // Upper part of the diamond
    for (row = 1; row <= n; row++) {
        for (space = row; space < n; space++) {
            printf(" ");
        }
        for (i = 1; i <= (2 * row - 1); i++) {
            printf("%d", (i <= row) ? i : (2 * row - i));
        }
        printf("\n");
    }

    // Lower part of the diamond
    for (row = n - 1; row >= 1; row--) {
        for (space = n; space > row; space--) {
            printf(" ");
        }
        for (i = 1; i <= (2 * row - 1); i++) {
            printf("%d", (i <= row) ? i : (2 * row - i));
        }
        printf("\n");
    }
}

void printReverseTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    // Top part
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Bottom part
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the size for the diamond and reverse triangle (greater than 1): ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Size must be greater than 1.\n");
        return 0;
    }

    printf("\nDiamond Pattern:\n");
    printDiamond(size);

    printf("\nReverse Triangle Pattern:\n");
    printReverseTriangle(size);

    printf("\nHollow Square Pattern:\n");
    printHollowSquare(size);

    printf("\nHourglass Pattern:\n");
    printHourglass(size);

    return 0;
}