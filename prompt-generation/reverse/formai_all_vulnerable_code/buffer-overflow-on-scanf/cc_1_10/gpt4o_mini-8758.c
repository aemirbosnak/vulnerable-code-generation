//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

void printFlowerPattern(int n) {
    int i, j;

    // Check if n is an odd number and at least 3
    if (n < 3 || n % 2 == 0) {
        printf("Please provide an odd number greater than or equal to 3.\n");
        return;
    }

    // Top part of the flower
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n; j++) {
            if (j == n / 2 - i || j == n / 2 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Middle part of the flower
    for (i = 0; i < n; i++) {
        if (i == n / 2) {
            for (j = 0; j < n; j++) {
                printf("*");
            }
        } else {
            printf(" ");
        }
        printf("\n");
    }

    // Bottom part of the flower
    for (i = n / 2; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if (j == n / 2 - i || j == n / 2 + i) {
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

    // User input for the size of the flower
    printf("Enter an odd number for flower pattern size (>= 3): ");
    scanf("%d", &size);

    printFlowerPattern(size);

    return 0;
}