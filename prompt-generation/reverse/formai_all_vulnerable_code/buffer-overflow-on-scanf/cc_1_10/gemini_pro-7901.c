//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void ScalablePattern(int n) {
    int i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("*");
        }
        for (l = 1; l <= n - i; l++) {
            printf(" ");
        }
        for (m = 1; m <= i; m++) {
            printf("*");
        }
        for (o = 1; o <= n - i; o++) {
            printf(" ");
        }
        for (p = 1; p <= i; p++) {
            printf("*");
        }
        for (q = 1; q <= n - i; q++) {
            printf(" ");
        }
        for (r = 1; r <= i; r++) {
            printf("*");
        }
        for (s = 1; s <= n - i; s++) {
            printf(" ");
        }
        for (t = 1; t <= i; t++) {
            printf("*");
        }
        for (u = 1; u <= n - i; u++) {
            printf(" ");
        }
        for (v = 1; v <= i; v++) {
            printf("*");
        }
        for (w = 1; w <= n - i; w++) {
            printf(" ");
        }
        for (x = 1; x <= i; x++) {
            printf("*");
        }
        for (y = 1; y <= n - i; y++) {
            printf(" ");
        }
        for (z = 1; z <= i; z++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    ScalablePattern(n);
    return 0;
}