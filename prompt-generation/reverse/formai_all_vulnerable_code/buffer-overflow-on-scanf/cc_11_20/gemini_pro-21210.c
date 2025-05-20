//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Pattern 1
    printf("\nPattern 1:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern 2
    printf("\nPattern 2:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n-i; j++) {
            printf("  ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern 3
    printf("\nPattern 3:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2*i-1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 4
    printf("\nPattern 4:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i-1; j++) {
            printf("  ");
        }
        for (k = 1; k <= n-i+1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern 5
    printf("\nPattern 5:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}