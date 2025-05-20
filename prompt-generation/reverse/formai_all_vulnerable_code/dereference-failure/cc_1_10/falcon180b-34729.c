//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

/* Function to print the disks on the specified rod */
void print_disks(int disks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

/* Function to check if a move is valid */
int is_valid_move(int disks[], int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || to < from) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i!= from && i!= to && disks[i] > disks[from]) {
            return 0;
        }
    }
    return 1;
}

/* Function to move a disk from one rod to another */
void move_disk(int disks[], int n, int from, int to) {
    int temp = disks[from];
    disks[from] = disks[to];
    disks[to] = temp;
}

/* Function to solve the Tower of Hanoi problem */
void tower_of_hanoi(int disks, int from, int to, int aux) {
    if (disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        move_disk(disks, 1, from, to);
    } else {
        tower_of_hanoi(disks - 1, from, aux, to);
        printf("Move disk %d from rod %d to rod %d\n", disks, from, to);
        move_disk(disks, 1, from, to);
        tower_of_hanoi(disks - 1, aux, to, from);
    }
}

int main() {
    int n, disks[MAX_DISKS], from, to;
    srand(time(NULL));
    n = rand() % MAX_DISKS + 1;
    printf("Tower of Hanoi with %d disks:\n", n);
    for (int i = n; i > 0; i--) {
        disks[i - 1] = i;
    }
    from = rand() % n;
    to = rand() % n;
    while (!is_valid_move(disks, n, from, to)) {
        from = rand() % n;
        to = rand() % n;
    }
    printf("Initial state:\n");
    print_disks(disks, n);
    tower_of_hanoi(n, from, to, 0);
    printf("Final state:\n");
    print_disks(disks, n);
    return 0;
}