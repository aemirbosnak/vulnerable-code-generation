//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main() {
    int a[MAX], b[MAX], c[MAX], sum[MAX], diff[MAX], prod[MAX];
    int i;

    printf("Enter %d elements in array A:\n", MAX);
    for (i = 0; i < MAX; i++) {
        printf("Enter element A[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter %d elements in array B:\n", MAX);
    for (i = 0; i < MAX; i++) {
        printf("Enter element B[%d]: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nPerforming Arithmetic Operations:\n");

    for (i = 0; i < MAX; i++) {
        c[i] = a[i] + b[i];
        sum[i] = a[i] + b[i];
        diff[i] = a[i] - b[i];
        prod[i] = a[i] * b[i];
    }

    printf("\nElements of Array C (Sum):\n");
    for (i = 0; i < MAX; i++) {
        printf("C[%d] = %d\n", i, c[i]);
    }

    printf("\nElements of Array Sum (Sum of elements of Array A and Array B):\n");
    for (i = 0; i < MAX; i++) {
        printf("Sum[%d] = %d\n", i, sum[i]);
    }

    printf("\nElements of Array Diff (Difference of elements of Array A and Array B):\n");
    for (i = 0; i < MAX; i++) {
        printf("Diff[%d] = %d\n", i, diff[i]);
    }

    printf("\nElements of Array Prod (Product of elements of Array A and Array B):\n");
    for (i = 0; i < MAX; i++) {
        printf("Prod[%d] = %d\n", i, prod[i]);
    }
}