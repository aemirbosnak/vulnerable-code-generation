//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>

// Minimum disks for Tower of Hanoi problem
#define MIN_DISKS 3

// Structure to represent rods in the problem
struct rod {
    int *disks;         // Array of disks on the rod
    int top_index;      // Index of the top disk on the rod
    int size;           // Maximum size of the rod
    char name;          // Name of the rod
};

// Initialize the rods with the necessary values
void initialize_rods(struct rod *rods, int num_rods, int num_disks) {
    for (int i = 0; i < num_rods; i++) {
        rods[i].size = num_disks;
        rods[i].name = 'A' + i;
        rods[i].disks = malloc(sizeof(int) * num_disks);
        rods[i].top_index = -1;
    }
    // Initialize the first rod with all the disks
    for (int i = 0; i < num_disks; i++) {
        rods[0].disks[i] = num_disks - i;
        rods[0].top_index++;
    }
}

// Move the top disk from one rod to the other rod
void move_disk(struct rod *from_rod, struct rod *to_rod) {
    int disk = from_rod->disks[from_rod->top_index];
    from_rod->top_index--;
    to_rod->top_index++;
    to_rod->disks[to_rod->top_index] = disk;
    printf("Move disk %d from %c to %c\n", disk, from_rod->name, to_rod->name);
}

// Recursive function to solve the Tower of Hanoi problem
void tower_of_hanoi(struct rod *source, struct rod *target, struct rod *aux, int num_disks) {
    if (num_disks == 1) {
        move_disk(source, target);
    } else {
        tower_of_hanoi(source, aux, target, num_disks - 1);
        move_disk(source, target);
        tower_of_hanoi(aux, target, source, num_disks - 1);
    }
}

int main() {
    int num_disks, num_rods;

    // Get input from the user
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);
    num_rods = 3;

    // Check if the number of disks is valid
    if (num_disks < MIN_DISKS) {
        printf("Number of disks must be at least %d\n", MIN_DISKS);
        return 1;
    }

    // Create the rods
    struct rod rods[num_rods];
    initialize_rods(rods, num_rods, num_disks);

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(&rods[0], &rods[1], &rods[2], num_disks);

    // Free the memory used by the rods
    for (int i = 0; i < num_rods; i++) {
        free(rods[i].disks);
    }

    return 0;
}