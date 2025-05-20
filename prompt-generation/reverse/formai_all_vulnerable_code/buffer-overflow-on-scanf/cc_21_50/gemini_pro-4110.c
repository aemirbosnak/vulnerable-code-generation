//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, l, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i * 2 - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i * 2 - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i - 1) / 2; k++) {
            printf("* ");
        }
        for (l = 1; l <= (2 * i - 1) / 2 - 1; l++) {
            printf("  ");
        }
        for (m = 1; m <= (2 * i - 1) / 2; m++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i - 1) / 2; k++) {
            printf("* ");
        }
        for (l = 1; l <= (2 * i - 1) / 2 - 1; l++) {
            printf("  ");
        }
        for (m = 1; m <= (2 * i - 1) / 2; m++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}