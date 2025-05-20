//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

// Function to print a diamond pattern
void printDiamond(int n) {
    int space, i, j;
    
    // Print upper part of the diamond
    for (i = 1; i <= n; i++) {
        for (space = n; space > i; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Print lower part of the diamond
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

// Function to print a triangle pattern
void printTriangle(int n) {
    int i, j;
    
    // Printtriangle
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int diamondHeight, triangleHeight;

    // Get user input for the height of the diamond and triangle
    printf("Enter the height of the diamond: ");
    scanf("%d", &diamondHeight);
    
    printf("Enter the height of the triangle: ");
    scanf("%d", &triangleHeight);

    // Print patterns
    printf("\nDiamond Pattern:\n");
    printDiamond(diamondHeight);
    
    printf("\nTriangle Pattern:\n");
    printTriangle(triangleHeight);

    return 0;
}