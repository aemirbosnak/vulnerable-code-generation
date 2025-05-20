//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: shape shifting
#include <stdio.h>

void printDiamond(int n) {
    for (int i = 0; i <= n; i += 2) {
        // printing leading spaces
        for (int j = 0; j < n - i; j += 2) {
            printf(" ");
        }
        // printing stars
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printDescending(int n) {
    for (int i = n; i > 0; i--) {
        // printing stars and spaces alternately
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printAscending(int n) {
    for (int i = 1; i <= n; i++) {
        // printing stars and spaces alternately
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printReversePyramid(int n) {
    for (int i = n; i > 0; i--) {
        // printing leading spaces
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // printing stars
        for (int j = 0; j < (2 * i) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printShapeShift(int n) {
    printDiamond(n);
    printf("\n");
    printDescending(n);
    printf("\n");
    printAscending(n);
    printf("\n");
    printReversePyramid(n);
}

int main() {
    int size;
    printf("Enter size for shape-shifting pattern (odd number recommended): ");
    scanf("%d", &size);

    // Validate input
    if (size < 1) {
        printf("Invalid size. Must be greater than 0.\n");
        return 1;
    }

    // Adjust size for diamond by making sure it is even
    if (size % 2 != 0) {
        size++;
    }

    printShapeShift(size);

    return 0;
}