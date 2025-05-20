//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISTANCE 1000

// Function to generate a random number between min and max
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate the distance between two points
int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    // Initialize the variables
    int x = 0, y = 0, targetX = 0, targetY = 0, distance = 0, moves = 0;
    bool gameOn = true;

    // Generate random target coordinates
    targetX = generateRandom(0, MAX_DISTANCE);
    targetY = generateRandom(0, MAX_DISTANCE);

    printf("Current position: (%d, %d)\n", x, y);
    printf("Target position: (%d, %d)\n", targetX, targetY);

    // Game loop
    while (gameOn) {
        // Get user input
        char direction;
        printf("Enter direction (u/d/l/r): ");
        scanf("%c", &direction);

        // Calculate new position based on user input
        switch (direction) {
            case 'u':
                y++;
                break;
            case 'd':
                y--;
                break;
            case 'l':
                x--;
                break;
            case 'r':
                x++;
                break;
            default:
                printf("Invalid input!\n");
                continue;
        }

        // Calculate the distance to the target
        distance = calculateDistance(x, y, targetX, targetY);
        moves++;

        // Check if the target is reached
        if (distance == 0) {
            printf("Target reached in %d moves!\n", moves);
            gameOn = false;
        } else {
            printf("New position: (%d, %d)\n", x, y);
            printf("Distance to target: %d\n", distance);
        }
    }

    return 0;
}