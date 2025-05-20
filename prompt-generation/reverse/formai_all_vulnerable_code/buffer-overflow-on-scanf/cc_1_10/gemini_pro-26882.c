//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure representing a Hanoi tower
struct hanoi_tower {
    int num_disks;
    bool is_valid;
    int* disks;
};

// Tower abstraction functions
struct hanoi_tower* create_tower(int num_disks) {
    struct hanoi_tower* tower = (struct hanoi_tower*)malloc(sizeof(struct hanoi_tower));
    tower->num_disks = num_disks;
    tower->is_valid = true;
    tower->disks = (int*)malloc(sizeof(int) * num_disks);

    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = num_disks - i;
    }

    return tower;
}

void free_tower(struct hanoi_tower* tower) {
    free(tower->disks);
    free(tower);
}

// Print tower abstraction functions
void print_tower(struct hanoi_tower* tower) {
    printf("Tower:\n");
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d\n", tower->disks[i]);
    }
    printf("\n");
}

// Checks tower validity
bool is_valid_tower(struct hanoi_tower* tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        for (int j = i + 1; j < tower->num_disks; j++) {
            if (tower->disks[i] > tower->disks[j]) {
                return false;
            }
        }
    }

    return true;
}

// Solves Hanoi using recursion
void solve_hanoi(struct hanoi_tower* source, struct hanoi_tower* destination, struct hanoi_tower* temp) {
    if (source->num_disks <= 0) {
        return;
    }

    // Move n-1 disks from source to temp
    solve_hanoi(source, temp, destination);

    // Move nth disk from source to destination
    destination->disks[destination->num_disks++] = source->disks[--source->num_disks];

    // Move n-1 disks from temp to destination
    solve_hanoi(temp, destination, source);
}

// Main function
int main() {
    // Get number of disks from user
    int num_disks;
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);

    // Create three Hanoi towers
    struct hanoi_tower* source = create_tower(num_disks);
    struct hanoi_tower* destination = create_tower(0);
    struct hanoi_tower* temp = create_tower(0);

    // Check if tower is valid
    if (!is_valid_tower(source)) {
        printf("Invalid tower.\n");
        return 1;
    }

    // Solve Hanoi
    solve_hanoi(source, destination, temp);

    // Print destination tower
    printf("Destination Tower:\n");
    print_tower(destination);

    // Free towers
    free_tower(source);
    free_tower(destination);
    free_tower(temp);

    return 0;
}