//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

void print_disks(int disks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

void move_disk(int disks[], int n, int from, int to) {
    int top = disks[n - 1];
    for (int i = n - 1; i >= from; i--) {
        disks[i + 1] = disks[i];
    }
    disks[to] = top;
}

void tower_of_hanoi(int disks, int from_rod, int to_rod, int aux_rod) {
    if (disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(disks - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", disks, from_rod, to_rod);
    tower_of_hanoi(disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int disks[MAX_DISKS];
    for (int i = n; i >= 1; i--) {
        disks[n - i] = i;
    }

    printf("Initial state:\n");
    print_disks(disks, n);

    printf("Moving %d disks from rod 1 to rod 3:\n", n);
    tower_of_hanoi(n, 1, 3, 2);

    printf("Final state:\n");
    print_disks(disks, n);

    return 0;
}