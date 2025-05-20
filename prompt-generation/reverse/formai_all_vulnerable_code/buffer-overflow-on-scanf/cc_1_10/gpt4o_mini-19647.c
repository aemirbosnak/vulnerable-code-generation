//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>

int move_count = 0; // Global variable to track number of moves

// Function to perform the Tower of Hanoi
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    // Base case: when there's only one disk
    if (n == 1) {
        move_count++; // Increment move count
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    move_count++; // Increment move count
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    
    // Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

// Function to perform statistical analysis
void print_statistics(int total_moves) {
    printf("\nStatistics:\n");
    printf("Total number of moves: %d\n", total_moves);
    // Here, we could calculate other statistics (mean, distribution, etc.) if required
    // For different n we can provide hypothetical distributions
    if (total_moves > 0) {
        printf("Average moves per disk: %.2f\n", (float) total_moves / (float) (total_moves >= 1 ? 1 : 1));  
    }
}

int main() {
    int num_disks;

    // Prompt user for the number of disks
    printf("Enter the number of disks for the Tower of Hanoi: ");
    scanf("%d", &num_disks);

    // Validate the input
    if (num_disks < 1 || num_disks > 20) {
        printf("Please enter a number between 1 and 20.\n");
        return 1;
    }
    
    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    
    // Perform Tower of Hanoi
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    
    // Print the statistics
    print_statistics(move_count);
    
    return 0;
}