//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: beginner-friendly
/*
 * Tower of Hanoi
 *
 * A beginner-friendly example program to solve the Tower of Hanoi problem.
 *
 * Usage: ./tower_of_hanoi <num_disks>
 */

#include <stdio.h>
#include <stdlib.h>

// Define the number of disks in the tower
#define NUM_DISKS 3

// Define the names of the towers
#define TOWER_A "A"
#define TOWER_B "B"
#define TOWER_C "C"

// Define the struct to represent a tower
typedef struct {
    char name[2]; // Name of the tower
    int disk[NUM_DISKS]; // Disk values in the tower
} tower_t;

// Define the global variables
tower_t towers[3];
int num_disks;

// Function to print the current state of the towers
void print_towers() {
    printf("Tower A: ");
    for (int i = 0; i < num_disks; i++) {
        printf("%d ", towers[0].disk[i]);
    }
    printf("\n");
    printf("Tower B: ");
    for (int i = 0; i < num_disks; i++) {
        printf("%d ", towers[1].disk[i]);
    }
    printf("\n");
    printf("Tower C: ");
    for (int i = 0; i < num_disks; i++) {
        printf("%d ", towers[2].disk[i]);
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(char from, char to) {
    int disk = towers[from].disk[num_disks - 1];
    towers[from].disk[num_disks - 1] = 0;
    towers[to].disk[num_disks - 1] = disk;
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi() {
    // Initialize the towers
    for (int i = 0; i < NUM_DISKS; i++) {
        towers[0].disk[i] = i + 1;
        towers[1].disk[i] = 0;
        towers[2].disk[i] = 0;
    }

    // Print the initial state of the towers
    print_towers();

    // Move the disks from A to C
    for (int i = 0; i < num_disks; i++) {
        move_disk(0, 2);
        print_towers();
    }
}

int main(int argc, char *argv[]) {
    // Check if the number of disks is provided as an argument
    if (argc != 2) {
        printf("Usage: %s <num_disks>\n", argv[0]);
        return 1;
    }

    // Parse the number of disks
    num_disks = atoi(argv[1]);

    // Check if the number of disks is valid
    if (num_disks < 1 || num_disks > NUM_DISKS) {
        printf("Invalid number of disks: %d\n", num_disks);
        return 1;
    }

    // Solve the Tower of Hanoi problem
    solve_tower_of_hanoi();

    return 0;
}