//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>

void printPyramid(int n) {
    int i, j, space;
    for (i = 0; i < n; i++) {
        // Print leading spaces
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        // Print left half of the pyramid
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    int i, j, space;
    // Print upper diamond part
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Print lower diamond part
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    int i, j, space;
    // Print upper hourglass
    for (i = n; i >= 1; i--) {
        for (space = 0; space < n - i; space++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Print lower hourglass
    for (i = 2; i <= n; i++) {
        for (space = 0; space < n - i; space++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int i, j, space;
    for (i = n; i >= 1; i--) {
        // Print leading spaces
        for (space = 0; space < n - i; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the pattern (a positive integer): ");
    scanf("%d", &n);

    printf("\n=== Pyramid Pattern ===\n\n");
    printPyramid(n);
    
    printf("\n=== Diamond Pattern ===\n\n");
    printDiamond(n);
    
    printf("\n=== Hourglass Pattern ===\n\n");
    printHourglass(n);
    
    printf("\n=== Inverted Pyramid Pattern ===\n\n");
    printInvertedPyramid(n);

    return 0;
}