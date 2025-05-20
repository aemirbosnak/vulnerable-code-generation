//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char *argv[]) {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks should be positive.\n");
        return 1;
    }

    int A[n], B[n], C[n];
    int i, j, k;

    // Initialize disks
    for (i = 0; i < n; i++) {
        A[i] = i + 1;
        B[i] = i + 1;
        C[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    // Move disks from source to destination
    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n; j++) {
            if (A[j] > A[i]) {
                k = A[i];
                A[i] = A[j];
                A[j] = k;
                k = B[i];
                B[i] = B[j];
                B[j] = k;
                k = C[i];
                C[i] = C[j];
                C[j] = k;
            }
        }
        printf("%d ", A[i]);
        printf("%d ", B[i]);
        printf("%d ", C[i]);
        printf("\n");
    }

    return 0;
}