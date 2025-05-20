//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#define NUM_DISKS 4
#define NUM_TOWERS 3
#define NUM_MOVES (3 * NUM_DISKS - 1)

int main() {
    int towers[NUM_TOWERS][NUM_DISKS];
    int moveCount = 0;

    // Initialize the towers with the disks
    for (int i = 0; i < NUM_DISKS; i++) {
        towers[0][i] = NUM_DISKS - i;
    }

    // Print the initial state of the towers
    printf("Initial state of the towers:\n");
    for (int i = 0; i < NUM_TOWERS; i++) {
        for (int j = 0; j < NUM_DISKS; j++) {
            printf("%d ", towers[i][j]);
        }
        printf("\n");
    }

    // Solve the Tower of Hanoi problem
    for (int i = 0; i < NUM_MOVES; i++) {
        // Find the smallest disk on the leftmost non-empty tower
        int sourceTower = -1;
        for (int j = 0; j < NUM_TOWERS; j++) {
            if (towers[j][0] != 0) {
                sourceTower = j;
                break;
            }
        }

        // Find the destination tower for the smallest disk
        int destinationTower = -1;
        for (int j = 0; j < NUM_TOWERS; j++) {
            if (j != sourceTower && (towers[j][0] == 0 || towers[j][0] > towers[sourceTower][0])) {
                destinationTower = j;
                break;
            }
        }

        // Move the smallest disk from the source tower to the destination tower
        towers[destinationTower][0] = towers[sourceTower][0];
        towers[sourceTower][0] = 0;

        // Increment the move count
        moveCount++;

        // Print the current state of the towers
        printf("Move %d:\n", moveCount);
        for (int j = 0; j < NUM_TOWERS; j++) {
            for (int k = 0; k < NUM_DISKS; k++) {
                printf("%d ", towers[j][k]);
            }
            printf("\n");
        }
    }

    // Print the final state of the towers
    printf("Final state of the towers:\n");
    for (int i = 0; i < NUM_TOWERS; i++) {
        for (int j = 0; j < NUM_DISKS; j++) {
            printf("%d ", towers[i][j]);
        }
        printf("\n");
    }

    return 0;
}