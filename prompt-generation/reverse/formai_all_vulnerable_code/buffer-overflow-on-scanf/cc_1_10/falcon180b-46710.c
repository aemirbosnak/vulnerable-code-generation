//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_disks(int num_disks, int from_rod, int to_rod, int aux_rod) {
    int i;

    printf("Current state of the towers:\n");
    for (i = 0; i < num_disks; i++) {
        if (i == from_rod) {
            printf("From rod: ");
        } else if (i == to_rod) {
            printf("To rod: ");
        } else if (i == aux_rod) {
            printf("Aux rod: ");
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int move_disk(int num_disks, int from_rod, int to_rod, int aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return 1;
    }

    int i;

    printf("Move %d disks from rod %d to rod %d using rod %d as auxiliary\n", num_disks, from_rod, to_rod, aux_rod);

    for (i = num_disks - 1; i >= 1; i--) {
        move_disk(i, from_rod, aux_rod, to_rod);
        print_disks(num_disks, from_rod, to_rod, aux_rod);
        sleep(1);
    }

    move_disk(num_disks, from_rod, to_rod, aux_rod);
    print_disks(num_disks, from_rod, to_rod, aux_rod);

    return 1;
}

int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 0;
    }

    move_disk(num_disks, 0, 2, 1);

    return 0;
}