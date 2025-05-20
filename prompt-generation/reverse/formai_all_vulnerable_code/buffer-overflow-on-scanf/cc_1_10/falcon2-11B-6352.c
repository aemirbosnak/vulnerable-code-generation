//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: if there are no disks left
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Recursive case: move n-1 disks from rod 1 to rod 3 using rod 2 as the auxiliary rod
    solveTowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the nth disk from rod 1 to rod 2
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Recursive case: move n-1 disks from rod 2 to rod 3 using rod 1 as the auxiliary rod
    solveTowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
    // Get the number of disks from the user
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Print the initial state of the Tower of Hanoi
    printf("Initial state:\n");
    printf("Rod 1: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\nRod 2: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\nRod 3: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Solve the Tower of Hanoi problem
    solveTowerOfHanoi(n, 'A', 'B', 'C');
    
    // Print the final state of the Tower of Hanoi
    printf("Final state:\n");
    printf("Rod 1: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\nRod 2: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\nRod 3: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}