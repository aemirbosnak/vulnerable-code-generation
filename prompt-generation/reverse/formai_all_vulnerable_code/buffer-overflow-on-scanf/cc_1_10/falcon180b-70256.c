//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to print the disks on the rod
void print_disks(int n, int rod) {
    int i;
    for (i = n; i >= 1; i--) {
        printf("Disk %d is on rod %d\n", i, rod);
    }
}

// Function to move n disks from source to destination using an auxiliary rod
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Moving disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    tower_of_hanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Moving disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Print the initial state of the rods
    printf("\nInitial state:\n");
    print_disks(n, 'A');
    print_disks(0, 'B');
    print_disks(0, 'C');

    // Move the disks from rod A to rod C
    printf("\n\nMoving disks from rod A to rod C:\n");
    tower_of_hanoi(n, 'A', 'C', 'B');

    // Print the final state of the rods
    printf("\n\nFinal state:\n");
    print_disks(n, 'C');
    print_disks(0, 'A');
    print_disks(0, 'B');

    return 0;
}