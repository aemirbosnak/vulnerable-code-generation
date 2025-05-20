//FormAI DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int n;
    printf("Enter an odd number greater than or equal to 5: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Error: Input is not an odd number\n");
        return 1;
    }
    if (n < 5) {
        printf("Error: Input number is less than 5\n");
        return 1;
    }

    int half = n / 2;

    // Print top half
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == n - 1 - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print middle line
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");

    // Print bottom half
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= half - i && j <= half + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}