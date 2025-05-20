//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
/*
 * Tower of Hanoi Problem
 *
 * This program solves the Tower of Hanoi problem using a recursive approach.
 * It takes as input the number of disks and the names of the three towers.
 * It outputs the moves required to solve the puzzle.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    char name[10];
    int num_disks;
} tower_t;

void hanoi(int num_disks, tower_t *towers) {
    // base case: if there is only one disk, move it to the destination tower
    if (num_disks == 1) {
        printf("Move disk 1 from %s to %s\n", towers[0].name, towers[2].name);
        return;
    }

    // solve the problem recursively
    // move the top disk from the source tower to the destination tower
    printf("Move disk %d from %s to %s\n", num_disks, towers[0].name, towers[2].name);

    // solve the problem for the remaining disks
    hanoi(num_disks - 1, towers);

    // move the top disk from the destination tower to the intermediate tower
    printf("Move disk %d from %s to %s\n", num_disks, towers[2].name, towers[1].name);

    // solve the problem for the remaining disks
    hanoi(num_disks - 1, towers);

    // move the top disk from the intermediate tower to the destination tower
    printf("Move disk %d from %s to %s\n", num_disks, towers[1].name, towers[2].name);
}

int main() {
    int num_disks;
    tower_t towers[3];

    // get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // get the names of the three towers from the user
    for (int i = 0; i < 3; i++) {
        printf("Enter the name of tower %d: ", i + 1);
        scanf("%s", towers[i].name);
        towers[i].num_disks = num_disks;
    }

    // solve the problem
    hanoi(num_disks, towers);

    return 0;
}