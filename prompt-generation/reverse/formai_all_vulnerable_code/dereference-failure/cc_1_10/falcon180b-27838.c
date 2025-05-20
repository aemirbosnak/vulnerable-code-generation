//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the disks on a tower
void print_tower(int tower[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(int source[], int target[], int n) {
    if (n == 0) {
        return;
    }

    // Move the top disk from the source tower to the target tower
    int disk = source[n - 1];
    source[n - 1] = 0;
    target[n - 1] = disk;

    // Recursively move the remaining disks
    move_disk(source, target, n - 1);
}

// Function to perform the Tower of Hanoi problem
void tower_of_hanoi(int n) {
    int source[MAX_DISKS], target[MAX_DISKS], auxiliary[MAX_DISKS];

    // Initialize the source tower with n disks
    for (int i = 0; i < n; i++) {
        source[i] = i + 1;
    }

    print_tower(source, n);

    // Move the disks from the source tower to the target tower
    move_disk(source, target, n);

    // Move the disks from the target tower to the auxiliary tower
    move_disk(target, auxiliary, n);

    // Move the disks from the auxiliary tower to the source tower
    move_disk(auxiliary, source, n);

    print_tower(source, n);
}

int main() {
    int n;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Perform the Tower of Hanoi problem
    tower_of_hanoi(n);

    return 0;
}