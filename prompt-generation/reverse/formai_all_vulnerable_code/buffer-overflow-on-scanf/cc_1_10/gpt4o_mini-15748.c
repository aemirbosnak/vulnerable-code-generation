//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to move disks from source to destination
void moveDisk(int disk, char from_rod, char to_rod) {
    printf("Surprise! Moving disk %d from rod %c to rod %c.\n", disk, from_rod, to_rod);
    // Simulating some delay for dramatic effect
    usleep(500000); // 0.5 seconds
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: If there's only one disk, move it and return
    if (n == 1) {
        moveDisk(n, from_rod, to_rod);
        return;
    }
    
    // Move n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the nth disk from source to destination
    moveDisk(n, from_rod, to_rod);
    
    // Move the n-1 disks from auxiliary to destination rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Function to start the process & display instructions
void startTowerOfHanoi(int n) {
    printf("✨ Welcome to the Tower of Hanoi Surprise Challenge! 🎉\n");
    printf("You have %d disks. Let's see if you can solve this puzzle!\n\n", n);
    printf("You have three rods:\n");
    printf("1. Source rod (A)\n");
    printf("2. Auxiliary rod (B)\n");
    printf("3. Destination rod (C)\n");
    printf("Move all disks from rod A to rod C using rod B as auxiliary.\n\n");
    
    // Start the Tower of Hanoi
    towerOfHanoi(n, 'A', 'C', 'B');
    
    printf("\n🎊 Congratulations! You've successfully moved all disks! 🎊\n");
}

/*
 * Main function
 * Netizens welcome a surprise challenge!
 */
int main() {
    int n;
    printf("Welcome, adventurous spirit! 🌟 How many disks do you wish to use? ");
    scanf("%d", &n);
    
    // Validate input
    if (n <= 0) {
        printf("Oops! Please enter a positive integer for the number of disks.\n");
        return 1;
    }
    
    // Invoke the Tower of Hanoi challenge
    startTowerOfHanoi(n);
    
    // Farewell and encouragement message
    printf("Thank you for playing the Tower of Hanoi Surprise Challenge! Until next time! 🎈\n");
    return 0;
}