//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    int i, j, k, m;
    // First part
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Second part
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Third part
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (k = i; k <= n; k++) {
            printf("%d ", k);
        }
        for (m = n - 1; m >= i; m--) {
            printf("%d ", m);
        }
        printf("\n");
    }

    // Fourth part
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (k = i; k <= n; k++) {
            printf("%d ", k);
        }
        for (m = n - 1; m >= i; m--) {
            printf("%d ", m);
        }
        printf("\n");
    }

    return 0;
}