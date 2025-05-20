//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("No disks to move.\n");
        return 0;
    }

    int A[n], B[n], C[n];
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
        B[i] = 0;
        C[i] = 0;
    }

    printf("Initial configuration:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Move n-1 disks from the source stack (A) to the destination stack (C)
    for (int i = n - 1; i >= 1; i--) {
        // Move the top disk from source stack A to the auxiliary stack B
        B[i] = A[i];

        // Move the top disk from source stack A to the destination stack C
        A[i] = C[i];

        // Move the top disk from auxiliary stack B to the destination stack C
        C[i] = B[i];

        // Print the new configuration
        printf("Move %d:\n", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", A[j]);
        }
        printf("\n");
    }

    // Move the remaining disk from the source stack (A) to the destination stack (C)
    printf("Move 0:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");

    // Print the final configuration
    printf("Final configuration:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");

    return 0;
}