//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_disks(int disks[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

void move_disk(int disks[], int n, int from, int to) {
    if (n == 1) {
        disks[to] = disks[from];
        return;
    }
    int temp = (from + to) % 3;
    move_disk(disks, n - 1, from, temp);
    disks[to] = disks[from];
    move_disk(disks, n - 1, temp, to);
}

void tower_of_hanoi(int disks, int from, int to, int aux) {
    if (disks == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from, to);
        return;
    }
    tower_of_hanoi(disks - 1, from, aux, to);
    printf("Move disk %d from peg %d to peg %d\n", disks, from, to);
    tower_of_hanoi(disks - 1, aux, to, from);
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_DISKS + 3;
    int disks[MAX_DISKS];
    for (int i = n; i >= 1; i--) {
        disks[i] = i;
    }
    int from = 1, to = 3, aux = 2;
    printf("Tower of Hanoi with %d disks:\n", n);
    printf("Initial state:\n");
    print_disks(disks, n);
    tower_of_hanoi(n, from, to, aux);
    printf("Final state:\n");
    print_disks(disks, n);
    return 0;
}