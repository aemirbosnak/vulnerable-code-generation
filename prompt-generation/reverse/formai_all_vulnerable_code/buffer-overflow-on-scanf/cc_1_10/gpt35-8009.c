//FormAI DATASET v1.0 Category: Robot movement control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the movement control command
#define MAX_COMMAND_LENGTH 20

// Define the direction constants
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

/*
 * Struct to hold the current position of the robot
 * and its direction of movement.
 */
typedef struct {
    int x; // X coordinate
    int y; // Y coordinate
    int direction; // Direction of movement
} RobotPosition;

// Function to move the robot forward one space in the current direction
void moveForward(RobotPosition* position) {
    switch (position->direction) {
        case NORTH:
            position->y--;
            break;
        case EAST:
            position->x++;
            break;
        case SOUTH:
            position->y++;
            break;
        case WEST:
            position->x--;
            break;
    }
}

// Function to turn the robot left 90 degrees
void turnLeft(RobotPosition* position) {
    switch (position->direction) {
        case NORTH:
            position->direction = WEST;
            break;
        case EAST:
            position->direction = NORTH;
            break;
        case SOUTH:
            position->direction = EAST;
            break;
        case WEST:
            position->direction = SOUTH;
            break;
    }
}

// Function to turn the robot right 90 degrees
void turnRight(RobotPosition* position) {
    switch (position->direction) {
        case NORTH:
            position->direction = EAST;
            break;
        case EAST:
            position->direction = SOUTH;
            break;
        case SOUTH:
            position->direction = WEST;
            break;
        case WEST:
            position->direction = NORTH;
            break;
    }
}

int main() {
    RobotPosition position = {0, 0, NORTH}; // Start at the origin, facing north
    
    while (1) { // Loop indefinitely until break
        char command[MAX_COMMAND_LENGTH]; // Buffer to hold the command
        
        printf("Enter a movement command (F=forward, L=left, R=right, Q=quit): ");
        scanf("%s", command);
        
        switch (command[0]) {
            case 'F':
                moveForward(&position);
                printf("Moved forward!\n");
                break;
            case 'L':
                turnLeft(&position);
                printf("Turned left!\n");
                break;
            case 'R':
                turnRight(&position);
                printf("Turned right!\n");
                break;
            case 'Q':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid command!\n");
                break;
        }
        
        printf("Current position: (%d, %d), facing ", position.x, position.y);
        switch (position.direction) {
            case NORTH:
                printf("north\n");
                break;
            case EAST:
                printf("east\n");
                break;
            case SOUTH:
                printf("south\n");
                break;
            case WEST:
                printf("west\n");
                break;
        }
    }
    
    return 0;
}