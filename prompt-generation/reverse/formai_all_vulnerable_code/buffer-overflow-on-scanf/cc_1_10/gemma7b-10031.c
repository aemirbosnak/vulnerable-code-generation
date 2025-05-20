//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, k, l, m, x, y, z, a[100], b[100], c[100], d[100], e[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        b[i] = a[i] * 2;
    }

    for (i = 0; i < n; i++) {
        c[i] = a[i] - 3;
    }

    for (i = 0; i < n; i++) {
        d[i] = a[i] % 4;
    }

    for (i = 0; i < n; i++) {
        e[i] = a[i] + 5;
    }

    printf("The elements of the array after doubling: ");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    printf("\nThe elements of the array after subtracting 3: ");
    for (i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    printf("\nThe elements of the array after taking the modulus 4: ");
    for (i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }

    printf("\nThe elements of the array after adding 5: ");
    for (i = 0; i < n; i++) {
        printf("%d ", e[i]);
    }

    return 0;
}