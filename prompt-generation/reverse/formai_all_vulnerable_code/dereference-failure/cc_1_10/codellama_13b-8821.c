//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
/*
 * A modular C program to solve the Tower of Hanoi problem
 */

#include <stdio.h>

/*
 * Struct to represent a disk
 */
struct disk {
    int size;
    struct disk *next;
};

/*
 * Function to print the disks in a tower
 */
void print_disks(struct disk *disks) {
    while (disks != NULL) {
        printf("%d ", disks->size);
        disks = disks->next;
    }
    printf("\n");
}

/*
 * Function to move a disk from one tower to another
 */
void move_disk(struct disk *disk, struct disk *source, struct disk *dest) {
    // Move the disk from the source tower to the destination tower
    disk->next = dest->next;
    dest->next = disk;

    // Print the disks in the source and destination towers
    printf("Moving disk %d from %s to %s\n", disk->size, source->next->size, dest->next->size);
    print_disks(source);
    print_disks(dest);
}

/*
 * Function to solve the Tower of Hanoi problem
 */
void solve_hanoi(int num_disks, struct disk *source, struct disk *dest) {
    // Base case: if there is only one disk, move it to the destination tower
    if (num_disks == 1) {
        move_disk(source->next, source, dest);
        return;
    }

    // Recursive case: move the top disk from the source tower to the destination tower
    move_disk(source->next, source, dest);

    // Recursive case: solve the problem for the remaining disks
    solve_hanoi(num_disks - 1, source, dest);
}

int main() {
    // Create the disks
    struct disk disk1 = {1, NULL};
    struct disk disk2 = {2, NULL};
    struct disk disk3 = {3, NULL};
    struct disk disk4 = {4, NULL};
    struct disk disk5 = {5, NULL};
    struct disk disk6 = {6, NULL};
    struct disk disk7 = {7, NULL};

    // Create the towers
    struct disk *tower1 = &disk1;
    struct disk *tower2 = &disk2;
    struct disk *tower3 = &disk3;

    // Print the initial state of the towers
    printf("Initial state of the towers:\n");
    print_disks(tower1);
    print_disks(tower2);
    print_disks(tower3);

    // Solve the Tower of Hanoi problem
    solve_hanoi(7, tower1, tower3);

    // Print the final state of the towers
    printf("Final state of the towers:\n");
    print_disks(tower1);
    print_disks(tower2);
    print_disks(tower3);

    return 0;
}