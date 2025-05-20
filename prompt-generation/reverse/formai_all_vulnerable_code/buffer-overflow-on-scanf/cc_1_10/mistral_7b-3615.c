//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main() {
    int a[SIZE], b[SIZE], c[SIZE], sum[SIZE], diff[SIZE], prod[SIZE];

    printf("Enter %d numbers for array a: ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter %d numbers for array b: ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
        sum[i] = a[i] + b[i];
        diff[i] = a[i] - b[i];
        prod[i] = a[i] * b[i];
    }

    printf("\nArrays after Arithmetic Operations:\n");
    printf("Element-wise sum: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sum[i]);
    }
    printf("\nElement-wise difference: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", diff[i]);
    }
    printf("\nElement-wise product: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", prod[i]);
    }

    printf("\nArrays after storing individual arithmetic results: \n");
    printf("Element-wise sum: [");
    for (int i = 0; i < SIZE - 1; i++) {
        printf("%d, ", c[i]);
    }
    printf("%d]\n", c[SIZE - 1]);

    printf("Element-wise difference: [");
    for (int i = 0; i < SIZE - 1; i++) {
        printf("%d, ", diff[i]);
    }
    printf("%d]\n", diff[SIZE - 1]);

    printf("Element-wise product: [");
    for (int i = 0; i < SIZE - 1; i++) {
        printf("%d, ", prod[i]);
    }
    printf("%d]\n", prod[SIZE - 1]);

    return 0;
}