//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
// C Robot movement control example program
// This program is designed to control the movement of a robot using UART communication
// It receives commands from a remote device and moves the robot accordingly

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define constants 
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

// Variable to hold robot position
int posX = 0;
int posY = 0;

// Function to move the robot forward
void moveForward(int distance) {
    posX += distance;
    printf("Moving forward %d units\n", distance);
}

// Function to move the robot backward
void moveBackward(int distance) {
    posX -= distance;
    printf("Moving backward %d units\n", distance);
}

// Function to move the robot left
void moveLeft(int distance) {
    posY -= distance;
    printf("Moving left %d units\n", distance);
}

// Function to move the robot right
void moveRight(int distance) {
    posY += distance;
    printf("Moving right %d units\n", distance);
}

// Function to stop the robot
void stop() {
    printf("Stopping robot\n");
}

// Function to parse and execute the received command
void executeCommand(char command, int distance) {
    // Check the received command and call the appropriate function
    switch (command) {
        case FORWARD:
            moveForward(distance);
            break;
        case BACKWARD:
            moveBackward(distance);
            break;
        case LEFT:
            moveLeft(distance);
            break;
        case RIGHT:
            moveRight(distance);
            break;
        case STOP:
            stop();
            break;
        default:
            printf("Invalid command\n");
    }
}

int main() {
    char input[20];
    char command;
    int distance;
    
    // Keep listening for incoming commands
    while (true) {
        // Wait for input
        printf("Waiting for command...\n");
        scanf("%s", input);
        
        // Parse input and extract command and distance
        command = input[0];
        distance = atoi(input+1);
        
        // Execute the received command
        executeCommand(command, distance);
    }
    
    return 0;
}