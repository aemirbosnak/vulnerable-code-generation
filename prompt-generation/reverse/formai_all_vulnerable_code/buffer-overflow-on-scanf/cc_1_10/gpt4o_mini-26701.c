//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 5

// Define the robot structure
typedef struct {
    int x;
    int y;
} Robot;

// Function prototypes
void displayInstructions();
void initializeRobot(Robot *robot);
void displayRobotPosition(Robot *robot);
bool moveRobot(Robot *robot, const char *direction);

int main() {
    Robot myRobot;
    initializeRobot(&myRobot);
    char command[10];

    printf("🎉 Hello, dear user! Welcome to the Happy Robot Movement Control! 🎉\n\n");
    displayInstructions();

    while (true) {
        displayRobotPosition(&myRobot);
        printf("Please enter a direction (up, down, left, right) or 'exit' to quit: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("🤖 Goodbye, friend! See you next time! 🎈\n");
            break;
        }

        if (!moveRobot(&myRobot, command)) {
            printf("❌ Oops! The robot can't move that way! 😢\n");
        } else {
            printf("🎉 The robot moved! Hooray! 🎊\n");
        }
    }

    return 0;
}

// Function to display instructions
void displayInstructions() {
    printf("🛠 Instructions: \n");
    printf("Type 'up' to move the robot up. \n");
    printf("Type 'down' to move the robot down. \n");
    printf("Type 'left' to move the robot left. \n");
    printf("Type 'right' to move the robot right. \n");
    printf("Type 'exit' to end the program. 🎊\n");
}

// Function to initialize the robot's position
void initializeRobot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
    printf("🤖 The robot is ready to explore! Starting at (0, 0) 🗺️\n");
}

// Function to display the current position of the robot
void displayRobotPosition(Robot *robot) {
    printf("🤖 Current Position: (%d, %d) 🌈\n", robot->x, robot->y);
}

// Function to move the robot based on user's command
bool moveRobot(Robot *robot, const char *direction) {
    if (strcmp(direction, "up") == 0) {
        if (robot->y < GRID_SIZE - 1) {
            robot->y++;
            return true;
        }
    } else if (strcmp(direction, "down") == 0) {
        if (robot->y > 0) {
            robot->y--;
            return true;
        }
    } else if (strcmp(direction, "left") == 0) {
        if (robot->x > 0) {
            robot->x--;
            return true;
        }
    } else if (strcmp(direction, "right") == 0) {
        if (robot->x < GRID_SIZE - 1) {
            robot->x++;
            return true;
        }
    }

    return false; // If the robot cannot move in the given direction
}