//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 1000

int main(void) {
    int n, from_rod, to_rod, aux_rod;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Allocate memory dynamically for the rods
    int *rods[3] = {(int *)malloc(n * sizeof(int)), (int *)malloc(n * sizeof(int)), (int *)malloc(n * sizeof(int))};
    if (rods[0] == NULL || rods[1] == NULL || rods[2] == NULL) {
        printf("Not enough memory!\n");
        exit(1);
    }

    // Initialize the rods with disks
    for (int i = n - 1; i >= 0; i--) {
        rods[0][i] = i;
    }

    // Print the initial state of the rods
    printf("Initial state:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", rods[0][i]);
    }
    printf("\n");

    // Move the disks from the first rod to the last rod
    for (int i = n - 1; i >= 0; i--) {
        from_rod = 0;
        to_rod = 2;
        aux_rod = 1;
        while (rods[from_rod][i]!= i) {
            if (rods[from_rod][i] < i) {
                printf("Move disk %d from rod %d to rod %d\n", rods[from_rod][i], from_rod, to_rod);
            } else {
                printf("Move disk %d from rod %d to rod %d\n", rods[from_rod][i], from_rod, aux_rod);
            }
            rods[to_rod][i] = rods[from_rod][i];
            rods[from_rod][i] = -1;
            from_rod = to_rod;
            to_rod = aux_rod;
            aux_rod = (aux_rod + 1) % 3;
        }
        rods[to_rod][i] = i;
    }

    // Print the final state of the rods
    printf("Final state:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", rods[2][i]);
    }
    printf("\n");

    // Free the memory allocated for the rods
    for (int i = 0; i < 3; i++) {
        free(rods[i]);
    }

    return 0;
}