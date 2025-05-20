//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

// Function to print the current state of the pegs
void printPegs(int n, char source, char target, char auxiliary, int sourcePeg[], int targetPeg[], int auxiliaryPeg[]) {
    printf("State of the pegs:\n");
    printf("Source (Peg %c): ", source);
    for (int i = n; i > 0; i--) {
        if (sourcePeg[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\nTarget (Peg %c): ", target);
    for (int i = n; i > 0; i--) {
        if (targetPeg[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\nAuxiliary (Peg %c): ", auxiliary);
    for (int i = n; i > 0; i--) {
        if (auxiliaryPeg[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n\n");
}

// Recursive function to solve the Tower of Hanoi
void moveDisks(int n, char source, char target, char auxiliary, int sourcePeg[], int targetPeg[], int auxiliaryPeg[]) {
    if (n == 1) {
        // Move disk from source to target
        printf("Moving disk 1 from Peg %c to Peg %c\n", source, target);
        sourcePeg[1] = 0;
        targetPeg[1] = 1;
        printPegs(n, source, target, auxiliary, sourcePeg, targetPeg, auxiliaryPeg);
        return;
    }

    // Move top n-1 disks from source to auxiliary, using target as a helper
    moveDisks(n - 1, source, auxiliary, target, sourcePeg, auxiliaryPeg, targetPeg);

    // Move the nth disk from source to target
    printf("Moving disk %d from Peg %c to Peg %c\n", n, source, target);
    sourcePeg[n] = 0;
    targetPeg[n] = 1;
    printPegs(n, source, target, auxiliary, sourcePeg, targetPeg, auxiliaryPeg);

    // Move the n-1 disks from auxiliary to target, using source as a helper
    moveDisks(n - 1, auxiliary, target, source, auxiliaryPeg, targetPeg, sourcePeg);
}

// Function to initialize pegs
void initializePegs(int n, int sourcePeg[], int targetPeg[], int auxiliaryPeg[]) {
    for (int i = 1; i <= n; i++) {
        sourcePeg[i] = 1; // source peg has all disks
        targetPeg[i] = 0; // target peg is empty
        auxiliaryPeg[i] = 0; // auxiliary peg is empty
    }
}

int main() {
    int n; // Number of disks

    // Asking user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize pegs
    int sourcePeg[n + 1], targetPeg[n + 1], auxiliaryPeg[n + 1];
    initializePegs(n, sourcePeg, targetPeg, auxiliaryPeg);
    
    // Print initial state
    printPegs(n, 'A', 'C', 'B', sourcePeg, targetPeg, auxiliaryPeg);
    
    // Solve the Tower of Hanoi
    moveDisks(n, 'A', 'C', 'B', sourcePeg, targetPeg, auxiliaryPeg);
    
    // Final state
    printf("The puzzle is completed!\n");
    printPegs(n, 'A', 'C', 'B', sourcePeg, targetPeg, auxiliaryPeg);

    return 0;
}