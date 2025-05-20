//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>

// Function to print the current state of the rods
void printRods(int n, char source, char auxiliary, char destination) {
    printf("\nCurrent state of rods:\n");
    printf("Source (%c): ", source);
    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\nAuxiliary (%c): -\n", auxiliary);
    printf("Destination (%c): -\n", destination);
    printf("-------------------------------------------------\n");
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        printRods(n, source, auxiliary, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    printRods(n, source, auxiliary, destination);
    
    // Move the n-1 disks from auxiliary to destination rod
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Main function to get user input and execute the program
int main() {
    int numDisks;

    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("Enter the number of disks (1 - 10): ");
    
    // Validating user input
    while (1) {
        if (scanf("%d", &numDisks) != 1 || numDisks < 1 || numDisks > 10) {
            printf("Please enter a valid number of disks (1 - 10): ");
            while(getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }

    printf("\nMoving %d disks from rod A to rod C using rod B as auxiliary:\n", numDisks);
    printRods(numDisks, 'A', 'B', 'C');
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    
    printf("All disks successfully moved from rod A to rod C!\n");
    return 0;
}