//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// A Pole structure to represent a pole in the Tower of Hanoi puzzle
struct Pole {
    int num_disks;
    int *disks;
};

// A global array to represent the three poles
struct Pole poles[3];

// A function to initialize the poles
void initialize_poles(int num_disks) {
    // Initialize each pole
    for (int i = 0; i < 3; i++) {
        poles[i].num_disks = 0;
        poles[i].disks = malloc(sizeof(int) * num_disks);
    }

    // Place all the disks on the first pole
    for (int i = 0; i < num_disks; i++) {
        poles[0].disks[i] = num_disks - i;
        poles[0].num_disks++;
    }
}

// A function to move a disk from one pole to another
void move_disk(int from_pole, int to_pole) {
    // Check if the move is valid
    if (poles[from_pole].num_disks == 0 ||
        (poles[to_pole].num_disks != 0 && poles[from_pole].disks[poles[from_pole].num_disks - 1] > poles[to_pole].disks[poles[to_pole].num_disks - 1])) {
        printf("Invalid move!\n");
        return;
    }

    // Move the disk
    poles[to_pole].disks[poles[to_pole].num_disks++] = poles[from_pole].disks[poles[from_pole].num_disks - 1];
    poles[from_pole].num_disks--;
}

// A function to solve the Tower of Hanoi puzzle
void solve_tower_of_hanoi(int num_disks, int from_pole, int to_pole, int aux_pole) {
    // Base case: if there are no more disks to move, return
    if (num_disks == 0) {
        return;
    }

    // Recursive case: move the top n-1 disks from the from pole to the aux pole
    solve_tower_of_hanoi(num_disks - 1, from_pole, aux_pole, to_pole);

    // Move the remaining disk from the from pole to the to pole
    move_disk(from_pole, to_pole);

    // Recursive case: move the n-1 disks from the aux pole to the to pole
    solve_tower_of_hanoi(num_disks - 1, aux_pole, to_pole, from_pole);
}

// A function to print the current state of the poles
void print_poles() {
    // Print each pole
    for (int i = 0; i < 3; i++) {
        printf("Pole %d: ", i + 1);
        for (int j = 0; j < poles[i].num_disks; j++) {
            printf("%d ", poles[i].disks[j]);
        }
        printf("\n");
    }
}

int main() {
    // The number of disks
    int num_disks;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // Initialize the poles
    initialize_poles(num_disks);

    // Print the initial state of the poles
    printf("Initial state:\n\n");
    print_poles();

    // Solve the Tower of Hanoi puzzle
    solve_tower_of_hanoi(num_disks, 0, 2, 1);

    // Print the final state of the poles
    printf("\nFinal state:\n\n");
    print_poles();

    return 0;
}