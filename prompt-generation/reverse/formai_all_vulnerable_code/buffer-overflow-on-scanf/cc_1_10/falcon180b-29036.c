//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to print the disks on a rod
void print_disks(int disks[], int n) {
    printf("Rod: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int disks[], int n, int from_rod, int to_rod) {
    if (from_rod >= 0 && from_rod < n && to_rod >= 0 && to_rod < n && to_rod!= from_rod && disks[from_rod] > 0) {
        return 1;
    }
    return 0;
}

// Function to move a disk from one rod to another
void move_disk(int disks[], int n, int from_rod, int to_rod) {
    int disk = disks[from_rod];
    disks[from_rod] = 0;
    disks[to_rod] += disk;
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int disks[], int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        move_disk(disks, n, from_rod, to_rod);
        return;
    }
    tower_of_hanoi(disks, n - 1, from_rod, aux_rod, to_rod);
    move_disk(disks, n, from_rod, to_rod);
    tower_of_hanoi(disks, n - 1, aux_rod, to_rod, from_rod);
}

// Main function to run the program
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    int disks[MAX_SIZE];
    printf("Enter the sizes of the disks (in decreasing order): ");
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &disks[i]);
    }

    int from_rod = 0;
    int to_rod = 2;
    int aux_rod = 1;

    printf("Initial state:\n");
    print_disks(disks, n);

    tower_of_hanoi(disks, n, from_rod, to_rod, aux_rod);

    printf("Final state:\n");
    print_disks(disks, n);

    return 0;
}