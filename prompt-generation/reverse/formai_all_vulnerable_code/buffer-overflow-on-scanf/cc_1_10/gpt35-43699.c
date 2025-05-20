//FormAI DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int row, col, spaces;
    for(row = 1; row <= n; row++) {
        
        // Left triangle
        for(col = 1; col <= row; col++) {
            printf("*");
        }

        // Spaces
        for(spaces = 1; spaces <= 2 * (n - row); spaces++) {
            printf(" ");
        }

        // Right triangle
        for(col = 1; col <= row; col++) {
            printf("*");
        }

        printf("\n");
    }

    for(row = n; row >= 1; row--) {
        
        // Left triangle
        for(col = 1; col <= row; col++) {
            printf("*");
        }

        // Spaces
        for(spaces = 1; spaces <= 2 * (n - row); spaces++) {
            printf(" ");
        }

        // Right triangle
        for(col = 1; col <= row; col++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}