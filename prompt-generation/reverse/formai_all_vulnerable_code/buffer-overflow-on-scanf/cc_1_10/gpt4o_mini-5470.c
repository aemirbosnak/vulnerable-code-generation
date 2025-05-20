//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void printTower(char towers[3][20], int heights[3]) {
    printf("\n\nCurrent Towers State:\n");
    printf("     A      B      C\n");
    printf("-----------------------\n");

    for (int level = 0; level < 20; level++) {
        char row[3] = {' ', ' ', ' '};
        
        for (int i = 0; i < 3; i++) {
            if (heights[i] > level) {
                row[i] = towers[i][heights[i]-level-1];
            }
        }
        
        printf("  |  %c  |  %c  |  %c  |\n", row[0], row[1], row[2]);
    }
    printf("-----------------------\n\n");
}

void moveDisk(int n, char fromTower, char toTower, char auxTower, char towers[3][20], int heights[3]) {
    if (n == 1) {
        // Move disk from 'fromTower' to 'toTower'
        printf("Move disk from %c to %c\n", fromTower, toTower);
        
        // Move disk in towers
        int fromIndex = fromTower - 'A';
        int toIndex = toTower - 'A';
        
        // Pop from 'fromTower'
        char disk = towers[fromIndex][heights[fromIndex] - 1];
        heights[fromIndex]--;
        // Push to 'toTower'
        towers[toIndex][heights[toIndex]] = disk;
        heights[toIndex]++;
        
        // Print current state of towers
        printTower(towers, heights);
        sleep(1); // Pause for a second to visualize the move
    } else {
        // Move n-1 disks from 'fromTower' to 'auxTower'
        moveDisk(n-1, fromTower, auxTower, toTower, towers, heights);
        // Move the nth disk from 'fromTower' to 'toTower'
        moveDisk(1, fromTower, toTower, auxTower, towers, heights);
        // Move the n-1 disks from 'auxTower' to 'toTower'
        moveDisk(n-1, auxTower, toTower, fromTower, towers, heights);
    }
}

int main() {
    int n;
    char towers[3][20] = {{'A', 'B', 'C'}, {0}, {0}}; // 3 towers with maximum height of 20
    int heights[3] = {0, 0, 0};

    // Initialize Tower A with 'n' disks
    printf("Welcome to the Curious Tower of Hanoi!\n");
    printf("Enter the number of disks (between 1 and 20): ");
    
    // Get user input
    scanf("%d", &n);

    // Check for valid input
    if (n < 1 || n > 20) {
        printf("Please enter a valid number of disks between 1 and 20.\n");
        return 1;
    }

    for (int i = n; i >= 1; i--) {
        towers[0][heights[0]] = '0' + i; // Push disks onto Tower A
        heights[0]++;
    }

    printTower(towers, heights); // Display the initial state
    printf("Starting to move %d disks from A to C...\n", n);
    sleep(2); // Pause before starting the moves

    moveDisk(n, 'A', 'C', 'B', towers, heights);
    
    printf("All disks have been successfully moved from A to C!\n");
    return 0;
}