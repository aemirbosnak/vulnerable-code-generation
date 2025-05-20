//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the tower structure
typedef struct tower {
    int num_disks;
    int *disks;
} tower;

// Create a new tower with the given number of disks
tower* create_tower(int num_disks) {
    tower* new_tower = malloc(sizeof(tower));
    new_tower->num_disks = num_disks;
    new_tower->disks = malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        new_tower->disks[i] = num_disks - i;
    }
    return new_tower;
}

// Print the tower
void print_tower(tower* t) {
    for (int i = 0; i < t->num_disks; i++) {
        printf("%d ", t->disks[i]);
    }
    printf("\n");
}

// Move a disk from one tower to another
void move_disk(tower* from, tower* to) {
    int disk = from->disks[from->num_disks - 1];
    from->num_disks--;
    to->num_disks++;
    to->disks[to->num_disks - 1] = disk;
}

// Solve the Tower of Hanoi problem
void solve_hanoi(tower* from, tower* to, tower* aux, int num_disks) {
    if (num_disks == 1) {
        move_disk(from, to);
        return;
    }
    solve_hanoi(from, aux, to, num_disks - 1);
    move_disk(from, to);
    solve_hanoi(aux, to, from, num_disks - 1);
}

// Get the number of disks from the user
int get_num_disks() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    return num_disks;
}

// Main function
int main() {
    // Get the number of disks from the user
    int num_disks = get_num_disks();

    // Create the three towers
    tower* from = create_tower(num_disks);
    tower* to = create_tower(0);
    tower* aux = create_tower(0);

    // Print the initial state of the towers
    printf("Initial state:\n");
    print_tower(from);
    print_tower(to);
    print_tower(aux);

    // Solve the Tower of Hanoi problem
    solve_hanoi(from, to, aux, num_disks);

    // Print the final state of the towers
    printf("Final state:\n");
    print_tower(from);
    print_tower(to);
    print_tower(aux);

    return 0;
}