//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    if (n > 1) {
        move_disk(n - 1, from_rod, aux_rod, to_rod);
    }
}

void tower_of_hanoi(int n) {
    char from_rod = 'A', to_rod = 'C', aux_rod = 'B';
    srand(time(0));
    int choice = rand() % 3;

    if (choice == 0) {
        from_rod = 'B';
        to_rod = 'A';
        aux_rod = 'C';
    } else if (choice == 1) {
        from_rod = 'C';
        to_rod = 'B';
        aux_rod = 'A';
    }

    printf("Tower of Hanoi problem with %d disks\n", n);
    printf("Initial position:\n");
    for (int i = n; i >= 1; i--) {
        printf("Disk %d is on rod %c\n", i, from_rod);
    }
    printf("\n");

    move_disk(n, from_rod, to_rod, aux_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n);

    return 0;
}