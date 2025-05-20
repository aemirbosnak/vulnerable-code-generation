//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

struct disk {
    int size;
    int position;
};

void print_disks(struct disk disks[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Disk %d: size = %d, position = %d\n", i + 1, disks[i].size, disks[i].position);
    }
}

void move_disk(struct disk disks[], int n, int from, int to) {
    if (from == to) {
        return;
    }

    if (from > to) {
        move_disk(disks, n, from, to + 1);
    }

    disks[to].position = disks[from].position;
    disks[from].position = to;
}

void tower_of_hanoi(int n, struct disk disks[], int from, int to, int aux) {
    if (n == 1) {
        move_disk(disks, n, from, to);
        return;
    }

    tower_of_hanoi(n - 1, disks, from, aux, to);
    move_disk(disks, n, from, to);
    tower_of_hanoi(n - 1, disks, aux, to, from);
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    struct disk disks[n];
    for (int i = 0; i < n; ++i) {
        disks[i].size = rand() % 10 + 1;
        disks[i].position = -1;
    }

    int from = 0;
    int to = n - 1;
    int aux = -1;

    printf("Initial state:\n");
    print_disks(disks, n);

    tower_of_hanoi(n, disks, from, to, aux);

    printf("\nFinal state:\n");
    print_disks(disks, n);

    return 0;
}