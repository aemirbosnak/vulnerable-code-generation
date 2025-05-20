//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 4

// Function to move a disk from one rod to another
void moveDisk(int source, int dest, int temp) {
    if (source!= dest) {
        // Move the disk to a temporary rod
        moveDisk(source, temp, source);
        
        // Move the disk from the temporary rod to the destination rod
        moveDisk(temp, dest, source);
        
        // Move the disk from the temporary rod to the source rod
        moveDisk(dest, source, temp);
    }
}

int main() {
    // Initialize the initial configuration
    int source = 0, temp = 1, dest = 2;
    int disks[MAX_DISKS];
    int ndisks = 0;
    
    // Read the number of disks
    while (1) {
        printf("Enter the number of disks: ");
        scanf("%d", &ndisks);
        if (ndisks >= 1 && ndisks <= MAX_DISKS) {
            break;
        }
        printf("Invalid number of disks! Please enter again.\n");
    }
    
    // Read the initial configuration
    for (int i = 0; i < ndisks; i++) {
        printf("Enter the disk at position %d: ", i + 1);
        scanf("%d", &disks[i]);
    }
    
    // Solve the problem
    moveDisk(source, dest, temp);
    
    // Print the final configuration
    printf("Final configuration:\n");
    for (int i = 0; i < ndisks; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
    
    return 0;
}