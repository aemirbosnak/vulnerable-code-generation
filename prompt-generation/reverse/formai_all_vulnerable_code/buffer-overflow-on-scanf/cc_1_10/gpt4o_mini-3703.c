//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DISK 64

// Function to execute the moves with an added paranoid twist
void paranoid_move(int n, char from_rod, char to_rod, char aux_rod) {
    // Guarding against invalid disk numbers
    if (n < 1 || n > MAX_DISK) {
        fprintf(stderr, "Warning: Invalid number of disks! Exiting for safety...\n");
        exit(1);
    }

    // Recursive case
    if (n == 1) {
        printf("Moving disk 1 from %c to %c... Checking surroundings...\n", from_rod, to_rod);
        sleep(1); // Simulating paranoia with a sleep
        printf("Disk 1 safely moved from %c to %c.\n", from_rod, to_rod);
        return;
    }

    // Move n-1 disks from 'from_rod' to 'aux_rod'
    paranoid_move(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the nth disk from 'from_rod' to 'to_rod'
    printf("Moving disk %d from %c to %c... Checking surroundings...\n", n, from_rod, to_rod);
    sleep(1); // More paranoia
    printf("Disk %d safely moved from %c to %c.\n", n, from_rod, to_rod);
    
    // Move the n-1 disks from 'aux_rod' to 'to_rod'
    paranoid_move(n - 1, aux_rod, to_rod, from_rod);
}

// Function to verify disk movement safety
void verify_safety(const char* message) {
    printf("%s\n", message);
    sleep(2); // Allow the paranoia to settle
    printf("Verification complete. Continuing...\n");
}

// Main function
int main() {
    int n;
    
    printf("Welcome to the paranoid Tower of Hanoi!\n");
    
    // Asking the user for input with a paranoid check
    printf("Enter the number of disks (up to %d): ", MAX_DISK);
    scanf("%d", &n);
    
    verify_safety("Verifying input...");
    
    if (n < 1 || n > MAX_DISK) {
        fprintf(stderr, "Warning: Input out of range! Please be more careful next time.\n");
        exit(1);
    }
    
    // Begin the moves
    printf("Starting the Tower of Hanoi with %d disks...\n", n);
    
    verify_safety("Before initiating the moves...");
    
    paranoid_move(n, 'A', 'C', 'B');
    
    verify_safety("Successfully completed all moves.");
    
    printf("All disks moved safely. Thank you for your vigilance during this operation.\n");
    
    return 0;
}