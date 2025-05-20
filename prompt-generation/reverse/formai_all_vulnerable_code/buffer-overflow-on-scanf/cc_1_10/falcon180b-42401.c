//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>

#define MAX_DISKS 10
#define FROM_ROD 1
#define TO_ROD 2
#define AUX_ROD 3

void display_disks(int disks, int from_rod, int to_rod, int aux_rod) {
    int i;
    for (i = 0; i < disks; i++) {
        if (i == from_rod) {
            printf("F");
        } else if (i == to_rod) {
            printf("T");
        } else if (i == aux_rod) {
            printf("A");
        } else {
            printf("_");
        }
    }
}

void move_disk(int disks, int from_rod, int to_rod, int aux_rod) {
    if (disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", FROM_ROD, TO_ROD);
    } else {
        move_disk(disks - 1, FROM_ROD, aux_rod, TO_ROD);
        printf("Move disk %d from rod %d to rod %d\n", disks, FROM_ROD, TO_ROD);
        move_disk(disks - 1, aux_rod, TO_ROD, FROM_ROD);
    }
}

void tower_of_hanoi(int disks) {
    printf("Tower of Hanoi with %d disks:\n", disks);
    move_disk(disks, FROM_ROD, TO_ROD, AUX_ROD);
}

int main() {
    int disks;

    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    if (disks < 1 || disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    tower_of_hanoi(disks);

    return 0;
}