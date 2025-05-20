//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

// Function to perform the Tower of Hanoi operation
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: when there's only one disk, move it from from_rod to to_rod
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Move top n-1 disks from from_rod to aux_rod, using to_rod as auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the nth disk from from_rod to to_rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Move the n-1 disks from aux_rod to to_rod, using from_rod as auxiliary
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
   
    printf("Welcome to the SHOCKING Tower of Hanoi game!\n");
   
    // User enters a number of disks
    printf("Enter the number of disks (greater than zero): ");
    scanf("%d", &n);
    
    // Input validation
    if (n < 1) {
        printf("Whoa! That's a shocker! The number must be greater than zero.\n");
        return 1;
    }
    
    // Display the starting state
    printf("Let's start moving those %d disks!\n", n);
    printf("The initial setup:\n");
    printf("Rod A (from) --> [");
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
        if (i > 1) printf(", "); // Just for aesthetics
    }
    printf("]\nRod B (to) --> []\nRod C (aux) --> []\n\n");

    // Perform the moves
    towerOfHanoi(n, 'A', 'B', 'C');

    // Display the ending state
    printf("\nThe final configuration is:\n");
    printf("Rod A (from) --> []\nRod B (to) --> [");
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n) printf(", ");
    }
    printf("]\nRod C (aux) --> []\n");
    
    printf("And just like that – the disks have been moved! What a journey!\n");

    return 0;
}