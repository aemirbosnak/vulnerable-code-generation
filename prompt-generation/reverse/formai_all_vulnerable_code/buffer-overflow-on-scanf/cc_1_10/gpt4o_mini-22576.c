//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>

// Function to perform the Tower of Hanoi movement
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    // Base case: only one disk
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);
    
    // Move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);
    
    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, target, source);
}

// Function to get the number of disks from the user
int getNumberOfDisks() {
    int n;
    printf("Welcome to the Tower of Hanoi!\n");
    printf("How many disks do you want to work with? (1-10): ");
    while (1) {
        scanf("%d", &n);
        if (n >= 1 && n <= 10) {
            break;
        }
        printf("Please enter a number between 1 and 10: ");
    }
    return n;
}

// Main function - starting point
int main() {
    int numberOfDisks = getNumberOfDisks();
    
    // Display the process
    printf("\nLet's solve the Tower of Hanoi with %d disk(s):\n", numberOfDisks);
    printf("The towers are labeled as follows: \n");
    printf("Source = A, Target = B, Auxiliary = C\n\n");
    
    // Initiate the movement process
    towerOfHanoi(numberOfDisks, 'A', 'B', 'C');
    
    printf("\nAll disks moved successfully from A to B following Tower of Hanoi rules!\n");
    return 0;
}