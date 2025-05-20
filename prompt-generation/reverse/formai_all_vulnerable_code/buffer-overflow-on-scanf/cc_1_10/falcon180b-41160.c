//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY 100000 // microseconds

// function to print the disks
void print_disks(int num_disks, int from_rod, int to_rod, int aux_rod) {
    int i;
    printf("\n");
    for (i = 0; i < num_disks; i++) {
        if (i == from_rod)
            printf("->");
        else if (i == to_rod)
            printf("<->");
        else if (i == aux_rod)
            printf("Aux->");
        else
            printf("   ");
    }
    printf("\n");
}

// function to move n disks from from_rod to to_rod using aux_rod
void tower_of_hanoi(int num_disks, int from_rod, int to_rod, int aux_rod) {
    if (num_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        printf("Current configuration:\n");
        print_disks(num_disks, from_rod, to_rod, aux_rod);
        return;
    }

    tower_of_hanoi(num_disks - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %d to rod %d\n", num_disks, from_rod, to_rod);
    print_disks(num_disks, from_rod, to_rod, aux_rod);
    tower_of_hanoi(num_disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    int from_rod = 0, to_rod = 2, aux_rod = 1;
    printf("Solving Tower of Hanoi problem for %d disks...\n", num_disks);
    tower_of_hanoi(num_disks, from_rod, to_rod, aux_rod);
    printf("\n");

    return 0;
}