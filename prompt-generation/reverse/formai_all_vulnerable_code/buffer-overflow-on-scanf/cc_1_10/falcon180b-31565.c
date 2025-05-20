//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print the disks on a given peg
void print_disks(int peg, int num_disks) {
    for (int i = num_disks; i > 0; i--) {
        printf(" ");
    }
    printf("O");
}

// Function to move a disk from one peg to another
void move_disk(int from_peg, int to_peg, int num_disks, int *aux_peg) {
    if (num_disks == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from_peg, to_peg);
        return;
    }

    // Move n-1 disks from from_peg to aux_peg
    move_disk(from_peg, *aux_peg, num_disks - 1, &to_peg);

    // Move the last disk from from_peg to to_peg
    printf("Move disk %d from peg %d to peg %d\n", num_disks, from_peg, to_peg);

    // Move the n-1 disks from aux_peg to to_peg
    move_disk(*aux_peg, to_peg, num_disks - 1, &from_peg);
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int num_disks, int from_peg, int to_peg, int *aux_peg) {
    if (num_disks == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from_peg, to_peg);
        return;
    }

    // Move n-1 disks from from_peg to aux_peg
    tower_of_hanoi(num_disks - 1, from_peg, *aux_peg, &to_peg);

    // Move the last disk from from_peg to to_peg
    printf("Move disk %d from peg %d to peg %d\n", num_disks, from_peg, to_peg);

    // Move the n-1 disks from aux_peg to to_peg
    tower_of_hanoi(num_disks - 1, *aux_peg, to_peg, &from_peg);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    int from_peg = 1, to_peg = 3, aux_peg = 2;
    printf("Initial state:\n");
    print_disks(from_peg, num_disks);
    printf("\n");

    tower_of_hanoi(num_disks, from_peg, to_peg, &aux_peg);

    printf("\nFinal state:\n");
    print_disks(to_peg, num_disks);
    printf("\n");

    return 0;
}