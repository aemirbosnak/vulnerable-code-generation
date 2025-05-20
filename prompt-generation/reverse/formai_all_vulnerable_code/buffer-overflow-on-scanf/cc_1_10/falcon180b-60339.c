//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 20

void move_disk(int n, char from, char to, char aux) {
    printf("Move disk %d from rod %c to rod %c using rod %c\n", n, from, to, aux);
}

void tower_of_hanoi(int n, char from, char to, char aux) {
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

    printf("Solving Tower of Hanoi with %d disks...\n", n);
    srand(time(NULL));
    char from_rod = 'A' + rand() % 3;
    char to_rod = 'A' + rand() % 3;
    char aux_rod = 'A' + rand() % 3;

    printf("Using rods A, B, and C\n");
    printf("Initial configuration:\n");
    for (int i = n; i >= 1; i--) {
        printf("Disk %d on rod %c\n", i, from_rod);
    }

    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    printf("\nFinal configuration:\n");
    for (int i = 1; i <= n; i++) {
        printf("Disk %d on rod %c\n", i, to_rod);
    }

    return 0;
}