//Gemma-7B DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        b[i] = a[i] * 2;
    }

    for (i = 0; i < n; i++) {
        c[i] = a[i] + 10;
    }

    for (i = 0; i < n; i++) {
        d[i] = a[i] % 5;
    }

    for (i = 0; i < n; i++) {
        e[i] = a[i] * a[i];
    }

    for (i = 0; i < n; i++) {
        f[i] = a[i] / 2;
    }

    for (i = 0; i < n; i++) {
        g[i] = a[i] + 20;
    }

    for (i = 0; i < n; i++) {
        printf("The element is: %d\n", a[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The double of the element is: %d\n", b[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The element added by 10 is: %d\n", c[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The remainder when the element is divided by 5 is: %d\n", d[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The square of the element is: %d\n", e[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The element divided by 2 is: %d\n", f[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The element added by 20 is: %d\n", g[i]);
    }

    return 0;
}