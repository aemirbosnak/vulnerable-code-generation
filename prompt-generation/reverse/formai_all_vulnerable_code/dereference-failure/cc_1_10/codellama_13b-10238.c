//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
/*
 * A unique C Tower of Hanoi Problem example program in a lively style
 *
 * Usage: ./hanoi [num_disks]
 *
 * Example: ./hanoi 5
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_DISKS 5

// Structure to represent a disk
typedef struct {
    int num;
    char from;
    char to;
} disk_t;

// Function to print the current state of the towers
void print_state(disk_t *disks) {
    printf("  A: ");
    for (int i = 0; i < NUM_DISKS; i++) {
        if (disks[i].from == 'A') {
            printf("%d ", disks[i].num);
        }
    }
    printf("\n");

    printf("  B: ");
    for (int i = 0; i < NUM_DISKS; i++) {
        if (disks[i].from == 'B') {
            printf("%d ", disks[i].num);
        }
    }
    printf("\n");

    printf("  C: ");
    for (int i = 0; i < NUM_DISKS; i++) {
        if (disks[i].from == 'C') {
            printf("%d ", disks[i].num);
        }
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(disk_t *disks, int num, char from, char to) {
    for (int i = 0; i < NUM_DISKS; i++) {
        if (disks[i].num == num && disks[i].from == from) {
            disks[i].to = to;
            disks[i].from = to;
            break;
        }
    }
}

// Function to solve the Tower of Hanoi problem
void solve_hanoi(disk_t *disks, int num_disks) {
    if (num_disks == 1) {
        move_disk(disks, 1, 'A', 'C');
    } else {
        solve_hanoi(disks, num_disks - 1);
        move_disk(disks, num_disks, 'A', 'C');
        solve_hanoi(disks, num_disks - 1);
    }
}

int main(int argc, char *argv[]) {
    int num_disks = atoi(argv[1]);

    disk_t disks[NUM_DISKS];
    for (int i = 0; i < NUM_DISKS; i++) {
        disks[i].num = i + 1;
        disks[i].from = 'A';
        disks[i].to = 'A';
    }

    printf("Initial state:\n");
    print_state(disks);

    solve_hanoi(disks, num_disks);

    printf("\nFinal state:\n");
    print_state(disks);

    return 0;
}