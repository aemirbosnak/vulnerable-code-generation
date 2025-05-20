//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>

// Define the number of disks
#define NUM_DISKS 3

// Define the number of pegs
#define NUM_PEGS 3

// Define the number of moves allowed
#define MAX_MOVES 1000

// Function to move a disk from one peg to another
void move_disk(int from_peg, int to_peg, int n) {
    if (n == 1) {
        // Move the disk from peg 1 to peg 2
        printf("Move disk from peg 1 to peg 2\n");
    } else {
        // Move the n-1 disks from peg 1 to peg 3
        move_disk(from_peg, 3, n-1);
        
        // Move the disk from peg 1 to peg 2
        printf("Move disk from peg 1 to peg 2\n");
        
        // Move the n-1 disks from peg 3 to peg 1
        move_disk(3, 1, n-1);
    }
}

// Function to solve the Tower of Hanoi problem
void solve_hanoi(int n) {
    int moves[MAX_MOVES];
    int i, from_peg, to_peg, n_remaining;
    
    // Initialize the moves array
    for (i = 0; i < MAX_MOVES; i++) {
        moves[i] = 0;
    }
    
    // Move the n disks from peg 1 to peg 2
    moves[0] = 1;
    from_peg = 1;
    to_peg = 2;
    n_remaining = n;
    while (n_remaining > 1) {
        move_disk(from_peg, to_peg, n_remaining);
        n_remaining -= 1;
    }
    
    // Move the n disks from peg 2 to peg 3
    moves[0] += 1;
    from_peg = 2;
    to_peg = 3;
    n_remaining = n;
    while (n_remaining > 1) {
        move_disk(from_peg, to_peg, n_remaining);
        n_remaining -= 1;
    }
    
    // Move the n disks from peg 3 to peg 1
    moves[0] += 1;
    from_peg = 3;
    to_peg = 1;
    n_remaining = n;
    while (n_remaining > 1) {
        move_disk(from_peg, to_peg, n_remaining);
        n_remaining -= 1;
    }
    
    // Print the moves array
    printf("Moves: ");
    for (i = 0; i < MAX_MOVES; i++) {
        printf("%d ", moves[i]);
    }
    printf("\n");
}

// Function to display the final state of the Tower of Hanoi problem
void display_hanoi(int n) {
    int i, from_peg, to_peg, n_remaining;
    
    // Move the n disks from peg 1 to peg 2
    for (i = 0; i < n; i++) {
        printf("Move disk %d from peg 1 to peg 2\n", i+1);
    }
    
    // Move the n disks from peg 2 to peg 3
    for (i = 0; i < n; i++) {
        printf("Move disk %d from peg 2 to peg 3\n", i+1);
    }
    
    // Move the n disks from peg 3 to peg 1
    for (i = 0; i < n; i++) {
        printf("Move disk %d from peg 3 to peg 1\n", i+1);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Solve the Tower of Hanoi problem
    solve_hanoi(n);
    
    // Display the final state of the Tower of Hanoi problem
    display_hanoi(n);
    
    return 0;
}