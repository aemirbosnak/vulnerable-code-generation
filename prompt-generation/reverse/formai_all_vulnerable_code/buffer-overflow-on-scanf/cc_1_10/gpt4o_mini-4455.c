//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

void printDiamond(int n) {
    int space;
    
    // Print upper triangle
    for (int i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Print lower triangle
    for (int i = n - 1; i >= 1; i--) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
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
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void diamondPattern(int n) {
    printf("\nDiamond Pattern:\n");
    printDiamond(n);
}

void invertedTrianglePattern(int n) {
    printf("\nInverted Triangle Pattern:\n");
    printInvertedTriangle(n);
}

void hollowSquarePattern(int n) {
    printf("\nHollow Square Pattern:\n");
    printHollowSquare(n);
}

void pyramidPattern(int n) {
    printf("\nPyramid Pattern:\n");
    printPyramid(n);
}

void trianglePattern(int n) {
    printf("\nTriangle Pattern:\n");
    printTriangle(n);
}

int main() {
    int n;

    printf("Enter the number of layers for the patterns: ");
    scanf("%d", &n);

    if(n < 1 || n > 20) {
        printf("Please enter a number between 1 and 20.\n");
        return 1;
    }
    
    diamondPattern(n);
    invertedTrianglePattern(n);
    hollowSquarePattern(n);
    pyramidPattern(n);
    trianglePattern(n);

    return 0;
}