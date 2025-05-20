//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
#include <unistd.h>

// Function to perform Tower of Hanoi operation
void towerOfHanoi(int n, char source, char target, char auxiliary, int *moves) {
    if (n == 1) {
        (*moves)++;
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    towerOfHanoi(n - 1, source, auxiliary, target, moves);
    
    (*moves)++;
    printf("Move disk %d from %c to %c\n", n, source, target);
    
    towerOfHanoi(n - 1, auxiliary, target, source, moves);
}

// Function to display an artistic representation of the Tower of Hanoi
void drawTower(int levels, int moves) {
    printf("\n--- Artistic Representation of Tower of Hanoi ---\n");
    printf("Levels: %d | Moves: %d\n\n", levels, moves);
    
    for (int i = levels; i > 0; i--) {
        for (int j = 1; j <= (levels * 2); j++) {
            if (j < (levels - i + 1) || j > (levels + i - 1)) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("===============================================\n");
}

// Main function to get user input and execute the program
int main() {
    int levels;
    int moves = 0;

    printf("Welcome to the Artistic Tower of Hanoi!\n");
    printf("Enter the number of disks (levels) in the tower (1-10): ");
    
    // Basic Input Validation
    while (1) {
        scanf("%d", &levels);
        if (levels < 1 || levels > 10) {
            printf("Please enter a valid number of disks (1-10): ");
        } else {
            break;
        }
    }
    
    printf("\nStarting the Tower of Hanoi with %d disks...\n", levels);
    sleep(1); // Wait for a second to build suspense
    
    // Draw initial tower state
    drawTower(levels, moves);
    
    // Perform the Tower of Hanoi
    towerOfHanoi(levels, 'A', 'C', 'B', &moves);
    
    // Draw final tower state
    drawTower(levels, moves);
    
    printf("All disks successfully moved!\n");
    printf("Total moves: %d\n", moves);
    
    return 0;
}