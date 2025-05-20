//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to print the moves
void moveDisk(int disk, char fromRod, char toRod) {
    printf("🏰 Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char sourceRod, char auxiliaryRod, char targetRod) {
    // Base case: If there is only one disk
    if (n == 1) {
        moveDisk(1, sourceRod, targetRod);
        return;
    }
    
    // Move n-1 disks from source to auxiliary, using target as a helper
    towerOfHanoi(n - 1, sourceRod, targetRod, auxiliaryRod);
    
    // Move the remaining disk from source to target
    moveDisk(n, sourceRod, targetRod);
    
    // Move the n-1 disks from auxiliary to target, using source as a helper
    towerOfHanoi(n - 1, auxiliaryRod, sourceRod, targetRod);
}

// Main function
int main() {
    int numDisks;
    
    printf("🌀 Welcome to the Tower of Hanoi! 🌀\n");
    printf("How many disks do you want to play with? ");
    
    // User input for number of disks
    scanf("%d", &numDisks);
    
    // Input validation
    if (numDisks <= 0) {
        printf("🚫 Oops! Please enter a positive number of disks. 🚫\n");
        return 1; // Exit the program with error code
    }
    
    // Start the Tower of Hanoi puzzle
    printf("\n🚀 Let's move those disks! 🚀\n");
    printf("🎉 Moving %d disks from Rod A to Rod C using Rod B 🎉\n\n", numDisks);
    
    // Call the function to solve Tower of Hanoi
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    
    printf("\n🎉 Congratulations! All disks are moved to Rod C! 🎉\n");
    printf("👍 Thanks for playing! Come again! 👍\n");
    
    return 0; // Exit the program successfully
}