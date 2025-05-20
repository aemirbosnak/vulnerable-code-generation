//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void main() {
    int n, i, j, k, l, m, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the grades of the student: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        b[i] = a[i] * 2;
    }

    for (i = 0; i < n; i++) {
        c[i] = a[i] + 10;
    }

    for (i = 0; i < n; i++) {
        d[i] = a[i] - 5;
    }

    for (i = 0; i < n; i++) {
        e[i] = a[i] * 3;
    }

    for (i = 0; i < n; i++) {
        printf("The grades of the student after doubling their grades are: %d\n", b[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The grades of the student after adding 10 to their grades are: %d\n", c[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The grades of the student after subtracting 5 from their grades are: %d\n", d[i]);
    }

    for (i = 0; i < n; i++) {
        printf("The grades of the student after multiplying their grades by 3 are: %d\n", e[i]);
    }

    return;
}