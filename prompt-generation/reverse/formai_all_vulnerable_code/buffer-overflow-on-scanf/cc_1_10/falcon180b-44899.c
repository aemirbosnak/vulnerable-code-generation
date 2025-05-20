//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

void move_disk(int n, int from, int to, int aux) {
    printf("Move disk %d from %d to %d\n", n, from, to);
}

void tower_of_hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(1, from, to, aux);
        return;
    }

    tower_of_hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    tower_of_hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    srand(time(NULL));
    int from = rand() % 3;
    int to = rand() % 3;
    int aux = (from + to) % 3;

    printf("Solving Tower of Hanoi with %d disks\n", n);
    printf("Initial configuration:\n");
    for (int i = n; i >= 1; i--) {
        printf("Disk %d is on peg %d\n", i, from);
    }

    tower_of_hanoi(n, from, to, aux);

    printf("\nFinal configuration:\n");
    for (int i = 1; i <= n; i++) {
        printf("Disk %d is on peg %d\n", i, to);
    }

    return 0;
}