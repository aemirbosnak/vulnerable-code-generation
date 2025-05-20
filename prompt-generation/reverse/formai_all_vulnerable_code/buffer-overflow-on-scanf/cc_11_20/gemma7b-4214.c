//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    k = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            c[k++] = a[i] + a[j];
        }
    }

    l = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            d[l++] = a[i] - a[j];
        }
    }

    m = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            e[m++] = a[i] * a[j];
        }
    }

    printf("The sum of pairs: ");
    for (i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    printf("\nThe difference of pairs: ");
    for (i = 0; i < l; i++) {
        printf("%d ", d[i]);
    }

    printf("\nThe product of pairs: ");
    for (i = 0; i < m; i++) {
        printf("%d ", e[i]);
    }

    return 0;
}