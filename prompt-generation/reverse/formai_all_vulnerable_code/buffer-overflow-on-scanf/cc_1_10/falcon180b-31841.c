//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void move_tower(int disks, int from, int to, int aux) {
    printf("Move disk %d from %d to %d\n", disks, from, to);
}

void tower_of_hanoi(int disks, int from, int to, int aux) {
    if (disks == 1) {
        move_tower(disks, from, to, aux);
        return;
    }

    tower_of_hanoi(disks - 1, from, aux, to);
    move_tower(disks, from, to, aux);
    tower_of_hanoi(disks - 1, aux, to, from);
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    if (disks < 1 || disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    srand(time(NULL));
    int from = rand() % 3;
    int to = rand() % 3;
    int aux = (from + to) % 3;

    printf("Solving the Tower of Hanoi with %d disks\n", disks);
    printf("Initial state:\n");
    for (int i = disks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");

    tower_of_hanoi(disks, from, to, aux);

    printf("\nFinal state:\n");
    for (int i = disks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}