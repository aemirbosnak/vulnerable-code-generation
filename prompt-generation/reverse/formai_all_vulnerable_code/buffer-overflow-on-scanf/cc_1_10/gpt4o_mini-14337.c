//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// Define the robot structure
typedef struct {
    int x; // X position
    int y; // Y position
} Robot;

// Function to initialize the robot's position
void initializeRobot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
}

// Function to print the current position of the robot
void printPosition(const Robot *robot) {
    printf("Current Position: (%d, %d)\n", robot->x, robot->y);
}

// Function to move the robot
void moveRobot(Robot *robot, char direction) {
    switch (direction) {
        case 'U': // Up
            robot->y += 1;
            break;
        case 'D': // Down
            robot->y -= 1;
            break;
        case 'L': // Left
            robot->x -= 1;
            break;
        case 'R': // Right
            robot->x += 1;
            break;
        default:
            printf("Invalid direction input. Use U, D, L, R.\n");
            break;
    }
}

// Function to take user input for movement and control the robot
void controlRobot(Robot *robot) {
    char command;

    printf("Control the robot: (U: Up, D: Down, L: Left, R: Right, Q: Quit)\n");

    while (true) {
        printPosition(robot);
        printf("Enter direction: ");
        scanf(" %c", &command);

        if (command == 'Q') {
            printf("Exiting robot control.\n");
            break;
        }
        
        moveRobot(robot, command);
    }
}

// Function to perform routine movements
void performRoutine(Robot *robot) {
    // Basic movement routine
    const char *routine = "UDLRUDL";
    int routine_length = 8;

    for (int i = 0; i < routine_length; i++) {
        moveRobot(robot, routine[i]);
        printPosition(robot);
        usleep(500000); // Sleep for 0.5 seconds to visualize movement
    }
}

// Main function
int main() {
    Robot myRobot;

    initializeRobot(&myRobot);
    controlRobot(&myRobot);
    
    // After control, perform a routine if needed
    printf("Executing a basic routine...\n");
    performRoutine(&myRobot);

    printf("Final Position: (%d, %d)\n", myRobot.x, myRobot.y);

    return 0;
}