//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the elements of the disk
void printDisk(int disk[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", disk[i]);
    }
    printf("\n");
}

// Function to move the disk from source to destination using auxiliary tower
void moveDisk(int disk[], int n, int source, int destination, int auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    moveDisk(disk, n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from rod %d to rod %d\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination
    moveDisk(disk, n - 1, auxiliary, destination, source);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, int source, int destination, int auxiliary) {
    int disk[MAX];

    // Initialize the disks
    for (int i = 0; i < n; i++) {
        disk[i] = i + 1;
    }

    // Move the disks from source to destination
    moveDisk(disk, n, source, destination, auxiliary);
}

// Main function
int main() {
    int n;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}