//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define the towers
#define NUM_TOWERS 3
#define TOWER_A 0
#define TOWER_B 1
#define TOWER_C 2

// Define the maximum number of disks
#define MAX_DISKS 10

// Define the data structure for a tower
typedef struct {
    int num_disks;
    int disks[MAX_DISKS];
} tower;

// Initialize the towers
tower towers[NUM_TOWERS] = {
    {0, {}},
    {0, {}},
    {0, {}},
};

// Function to move a disk from one tower to another
void move_disk(int from_tower, int to_tower) {
    // Get the top disk from the from_tower
    int disk = towers[from_tower].disks[towers[from_tower].num_disks - 1];

    // Remove the disk from the from_tower
    towers[from_tower].num_disks--;

    // Add the disk to the to_tower
    towers[to_tower].disks[towers[to_tower].num_disks] = disk;
    towers[to_tower].num_disks++;
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int num_disks, int from_tower, int to_tower, int aux_tower) {
    // Base case: no disks to move
    if (num_disks == 0) {
        return;
    }

    // Recursive case: move the top n-1 disks from the from_tower to the aux_tower
    solve_tower_of_hanoi(num_disks - 1, from_tower, aux_tower, to_tower);

    // Move the remaining disk from the from_tower to the to_tower
    move_disk(from_tower, to_tower);

    // Recursive case: move the n-1 disks from the aux_tower to the to_tower
    solve_tower_of_hanoi(num_disks - 1, aux_tower, to_tower, from_tower);
}

// Main function
int main() {
    // Get the number of disks from the user
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // Solve the Tower of Hanoi problem
    solve_tower_of_hanoi(num_disks, TOWER_A, TOWER_C, TOWER_B);

    // Print the result
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }

    return 0;
}