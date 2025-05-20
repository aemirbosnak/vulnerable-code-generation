//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, int source, int target, int aux, int *tower) {
    int i;

    for (i = 0; i <= n; i++) {
        if (i == source)
            printf(" %d ", tower[i]);
        else if (i == target)
            printf(" %d ", tower[i]);
        else if (i == aux)
            printf(" %d ", tower[i]);
        else
            printf("   ");
    }

    printf("\n");
}

// Function to move n disks from source to target using aux as auxiliary tower
void hanoi(int n, int source, int target, int aux, int *tower) {
    if (n == 1) {
        tower[target] = tower[source];
        printf("Move disk 1 from %d to %d\n", source, target);
        return;
    }

    hanoi(n - 1, source, aux, target, tower);

    tower[target] = tower[source];
    printf("Move disk %d from %d to %d\n", n, source, target);

    hanoi(n - 1, aux, target, source, tower);
}

int main() {
    int n;

    // Get number of disks from user input
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize towers with disks
    int tower[MAX_DISKS];
    for (int i = n; i >= 1; i--) {
        tower[n - i] = i;
    }

    // Print initial state of towers
    printf("Initial state:\n");
    print_towers(n, 0, 2, 1, tower);

    // Solve Tower of Hanoi problem
    hanoi(n, 0, 2, 1, tower);

    // Print final state of towers
    printf("Final state:\n");
    print_towers(n, 0, 2, 1, tower);

    return 0;
}