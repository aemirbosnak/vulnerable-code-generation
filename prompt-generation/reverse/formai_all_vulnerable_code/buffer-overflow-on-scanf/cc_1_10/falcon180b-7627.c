//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_disks(int disks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Disk %d: %d\n", i, disks[i]);
    }
}

void move_disk(int disks[], int n, int from, int to) {
    printf("Moving disk %d from rod %d to rod %d...\n", disks[from], from, to);
    disks[from] = 0;
    disks[to] = disks[from];
    printf("Disk %d successfully moved to rod %d.\n", disks[from], to);
}

void tower_of_hanoi(int disks[], int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Moving disk %d from rod %d to rod %d...\n", disks[from], from, to);
        disks[to] = disks[from];
        printf("Disk %d successfully moved to rod %d.\n", disks[from], to);
        return;
    }

    tower_of_hanoi(disks, n - 1, from, aux, to);

    move_disk(disks, n, from, to);

    tower_of_hanoi(disks, n - 1, aux, to, from);
}

int main() {
    int disks[MAX_DISKS];
    int n;

    printf("Welcome to the Tower of Hanoi game!\n");

    // Initialize random seed
    srand(time(NULL));

    // Get number of disks from user
    printf("How many disks do you want to play with? (Max %d): ", MAX_DISKS);
    scanf("%d", &n);

    // Initialize disks
    for (int i = 0; i < n; i++) {
        disks[i] = i + 1;
    }

    // Shuffle disks
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = disks[i];
        disks[i] = disks[j];
        disks[j] = temp;
    }

    // Print initial state
    printf("Initial state:\n");
    print_disks(disks, n);

    // Solve puzzle
    tower_of_hanoi(disks, n, 0, 2, 1);

    // Print final state
    printf("\nFinal state:\n");
    print_disks(disks, n);

    return 0;
}