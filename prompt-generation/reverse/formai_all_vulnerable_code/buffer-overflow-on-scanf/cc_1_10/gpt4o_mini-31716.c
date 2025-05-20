//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>

// Function to solve the Tower of Hanoi
void hanoi(int n, char source, char target, char auxiliary) {
    // Base case: if there's only one disk to move
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    hanoi(n - 1, source, auxiliary, target);
    
    // Move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);
    
    // Move n-1 disks from auxiliary to target
    hanoi(n - 1, auxiliary, target, source);
}

// Function to display a welcome message
void welcomeMessage() {
    printf("=====================================\n");
    printf("     Welcome to Tower of Hanoi!     \n");
    printf("=====================================\n");
    printf("     Get Ready to Solve It!         \n");
    printf("=====================================\n");
}

// Main function
int main() {
    welcomeMessage();  // Display the welcome message

    int disks;
    // Asking the user for the number of disks
    printf("Enter the number of disks (1 to 20) to be moved: ");
    scanf("%d", &disks);
    
    // Ensuring the number of disks is within a realistic range
    if (disks < 1 || disks > 20) {
        printf("Please enter a valid number of disks between 1 and 20.\n");
        return 1; // Exit with an error code
    }

    // Begin the Tower of Hanoi solution
    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    hanoi(disks, 'A', 'C', 'B');  // A is source, C is target, B is auxiliary
    
    printf("\n=====================================\n");
    printf("      Hurray! You've solved it!      \n");
    printf("        Total moves: %d              \n", (1 << disks) - 1);  // 2^disks - 1
    printf("=====================================\n");

    return 0; // Successful completion
}