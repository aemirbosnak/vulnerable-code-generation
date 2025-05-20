//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Constants
#define NUM_TOWERS 3
#define MAX_DISK_SIZE 10

// Towers
int towers[NUM_TOWERS][MAX_DISK_SIZE];
int top[NUM_TOWERS];

// Function to initialize the towers
void initialize_towers() {
    for (int i = 0; i < NUM_TOWERS; i++) {
        for (int j = 0; j < MAX_DISK_SIZE; j++) {
            towers[i][j] = 0;
        }
        top[i] = -1;
    }
}

// Function to move a disk from one tower to another
void move_disk(int from, int to) {
    if (top[from] == -1) {
        printf("Error: No disk to move from tower %d.\n", from);
        return;
    }
    if (top[to] != -1 && towers[to][top[to]] < towers[from][top[from]]) {
        printf("Error: Cannot move a larger disk onto a smaller disk.\n");
        return;
    }
    towers[to][++top[to]] = towers[from][top[from]];
    top[from]--;
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int num_disks, int from, int to) {
    if (num_disks == 0) {
        return;
    }
    int via = 3 - from - to;
    solve_tower_of_hanoi(num_disks - 1, from, via);
    move_disk(from, to);
    solve_tower_of_hanoi(num_disks - 1, via, to);
}

// Function to print the towers
void print_towers() {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j <= top[i]; j++) {
            printf("%d ", towers[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random instance of the Tower of Hanoi problem
void generate_random_instance(int num_disks) {
    srand(time(NULL));
    for (int i = 0; i < num_disks; i++) {
        int tower = rand() % NUM_TOWERS;
        towers[tower][++top[tower]] = i + 1;
    }
}

// Main function
int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks > MAX_DISK_SIZE) {
        printf("Error: The maximum number of disks is %d.\n", MAX_DISK_SIZE);
        return EXIT_FAILURE;
    }
    initialize_towers();
    generate_random_instance(num_disks);
    printf("Initial state of the towers:\n");
    print_towers();
    solve_tower_of_hanoi(num_disks, 0, 2);
    printf("Final state of the towers:\n");
    print_towers();
    return EXIT_SUCCESS;
}