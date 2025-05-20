//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int towers[MAX_DISKS], int n) {
    for (int i = 0; i < n; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = n - 1; j >= 0; j--) {
            if (towers[i] & (1 << j)) {
                printf("%d ", 1 << j);
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int towers[MAX_DISKS], int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n ||
        towers[from] == 0 || (towers[from] & towers[to])!= 0) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int towers[MAX_DISKS], int n, int from, int to) {
    towers[to] |= towers[from];
    towers[from] &= ~(1 << n - 1);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int towers[MAX_DISKS], int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(towers, n, from, to);
        return;
    }
    hanoi(towers, n - 1, from, aux, to);
    move_disk(towers, n, from, to);
    hanoi(towers, n - 1, aux, to, from);
}

int main() {
    int n, towers[MAX_DISKS] = {0};

    // Get the number of disks
    printf("Enter the number of disks (1-10): ");
    scanf("%d", &n);

    // Initialize the towers
    for (int i = 0; i < n; i++) {
        towers[i] = (1 << i);
    }

    // Print the initial state of the towers
    printf("Initial state:\n");
    print_towers(towers, n);

    // Solve the Tower of Hanoi problem
    hanoi(towers, n, 0, 2, 1);

    // Print the final state of the towers
    printf("\nFinal state:\n");
    print_towers(towers, n);

    return 0;
}