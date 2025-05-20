//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

void printHeart(int n) {
    int i, j;

    for (i = n / 2; i <= n; i += 2) {
        // Print leading spaces
        for (j = 1; j < n - i; j += 2)
            printf(" ");

        // Print first part of heart
        for (j = 1; j <= i; j++)
            printf("*");

        // Print space between the two parts of heart
        for (j = 1; j <= n - i; j++)
            printf(" ");

        // Print second part of heart
        for (j = 1; j <= i; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }

    // Bottom part of heart
    for (i = n; i >= 1; i--) {
        for (j = i; j < n; j++)
            printf(" ");
        for (j = 1; j <= (i * 2) - 1; j++)
            printf("*");
        printf("\n");
    }
}

void printStarburst(int n) {
    int i, j, center = n / 2;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == center || j == center || 
                i + j == center || 
                i - j == center || 
                j - i == center || 
                i + j == (n - 1) + center) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("O, fair maiden, enter the size of thy heart (even number): ");
    scanf("%d", &size);

    if (size % 2 != 0) {
        printf("Pray, provide an even size for the heart's beauty!\n");
        return 1;
    }

    printf("\nThe heart doth appear:\n");
    printHeart(size);

    printf("\nAnd now, let us behold the starburst of love:\n");
    printStarburst(size);

    printf("\nAlas! Our tale of stars and hearts hath ended.\n");
    return 0;
}