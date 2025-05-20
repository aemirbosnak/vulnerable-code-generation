//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

void printStarPattern(int n) {
    printf("Star Pattern:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printPyramidPattern(int n) {
    printf("Pyramid Pattern:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n - i; j > 1; j--) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDiamondPattern(int n) {
    printf("Diamond Pattern:\n");
    // Upper half
    for (int i = 0; i < n; i++) {
        for (int j = n - i; j > 1; j--) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Lower half
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - i; j > 1; j--) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printNumberPattern(int n) {
    printf("Number Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printReverseTrianglePattern(int n) {
    printf("Reverse Triangle Pattern:\n");
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printFloydsTriangle(int n) {
    printf("Floyd's Triangle:\n");
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of lines for the patterns: ");
    scanf("%d", &n);

    printStarPattern(n);
    printf("\n");

    printPyramidPattern(n);
    printf("\n");

    printDiamondPattern(n);
    printf("\n");

    printNumberPattern(n);
    printf("\n");

    printReverseTrianglePattern(n);
    printf("\n");

    printFloydsTriangle(n);
    printf("\n");

    return 0;
}