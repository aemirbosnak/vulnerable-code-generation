//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>

void printDiamond(int n) {
    int space, i;

    // Print upper triangle
    for(i = 0; i < n; i++) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(space = 0; space < 2 * i + 1; space++)
            printf("*");
        printf("\n");
    }

    // Print lower triangle
    for(i = n - 2; i >= 0; i--) {
        for(space = 0; space < n - i - 1; space++)
            printf(" ");
        for(space = 0; space < 2 * i + 1; space++)
            printf("*");
        printf("\n");
    }
}

void printSquare(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("* ");
        printf("\n");
    }
}

void printRightTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    for(int i = 0; i < n; i++) {
        for(int space = 0; space < n - i - 1; space++)
            printf(" ");
        for(int j = 0; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

void printNumberTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }
}

void printAsteriskSPattern(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || (i + j == n - 1 && i < n / 2) || (i == n / 2 && j != 0) || (j == n - 1 && i < n / 2) || (i < n / 2 && j == 0)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the height for the diamond pattern: ");
    scanf("%d", &n);
    printf("\nDiamond pattern:\n");
    printDiamond(n);
    
    printf("Enter the size for the square pattern: ");
    scanf("%d", &n);
    printf("\nSquare pattern:\n");
    printSquare(n);
    
    printf("Enter the height for the right triangle pattern: ");
    scanf("%d", &n);
    printf("\nRight Triangle pattern:\n");
    printRightTriangle(n);
    
    printf("Enter the height for the inverted triangle pattern: ");
    scanf("%d", &n);
    printf("\nInverted Triangle pattern:\n");
    printInvertedTriangle(n);
    
    printf("Enter the size for the hollow square pattern: ");
    scanf("%d", &n);
    printf("\nHollow Square pattern:\n");
    printHollowSquare(n);
    
    printf("Enter the height for the pyramid pattern: ");
    scanf("%d", &n);
    printf("\nPyramid pattern:\n");
    printPyramid(n);
    
    printf("Enter the height for the number triangle pattern: ");
    scanf("%d", &n);
    printf("\nNumber Triangle pattern:\n");
    printNumberTriangle(n);
    
    printf("Enter the size for the asterisk 'S' pattern: ");
    scanf("%d", &n);
    printf("\nAsterisk 'S' pattern:\n");
    printAsteriskSPattern(n);
    
    return 0;
}