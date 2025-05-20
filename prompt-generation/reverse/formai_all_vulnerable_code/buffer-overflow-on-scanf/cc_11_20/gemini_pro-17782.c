//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, l;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        for (l = 1; l <= n - i; l++) {
            printf(" ");
        }

        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        for (l = 1; l <= n - i; l++) {
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}