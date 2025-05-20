//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum boundaries for the robot's movements
#define MAX_X 10
#define MAX_Y 10

// Robot structure to hold its properties
typedef struct {
    int x;
    int y;
    char direction[10];
} Robot;

// Function prototypes
void initializeRobot(Robot *robot);
void moveForward(Robot *robot);
void turnLeft(Robot *robot);
void turnRight(Robot *robot);
void reportPosition(Robot *robot);
void displayInstructions();

int main() {
    Robot myRobot;
    initializeRobot(&myRobot);
    
    int choice;
    displayInstructions();
    
    while(1) {
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                moveForward(&myRobot);
                break;
            case 2:
                turnLeft(&myRobot);
                break;
            case 3:
                turnRight(&myRobot);
                break;
            case 4:
                reportPosition(&myRobot);
                break;
            case 5:
                displayInstructions();
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// Function to initialize the robot's position and direction
void initializeRobot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
    strcpy(robot->direction, "North");
    printf("Robot initialized at position (%d, %d) facing %s.\n", robot->x, robot->y, robot->direction);
}

// Function to move the robot forward based on its current direction
void moveForward(Robot *robot) {
    if (strcmp(robot->direction, "North") == 0) {
        if (robot->y < MAX_Y) robot->y++;
    } else if (strcmp(robot->direction, "South") == 0) {
        if (robot->y > 0) robot->y--;
    } else if (strcmp(robot->direction, "East") == 0) {
        if (robot->x < MAX_X) robot->x++;
    } else if (strcmp(robot->direction, "West") == 0) {
        if (robot->x > 0) robot->x--;
    }
    printf("Robot moved forward. New position: (%d, %d).\n", robot->x, robot->y);
}

// Function to turn the robot left (90 degrees)
void turnLeft(Robot *robot) {
    if (strcmp(robot->direction, "North") == 0) {
        strcpy(robot->direction, "West");
    } else if (strcmp(robot->direction, "West") == 0) {
        strcpy(robot->direction, "South");
    } else if (strcmp(robot->direction, "South") == 0) {
        strcpy(robot->direction, "East");
    } else if (strcmp(robot->direction, "East") == 0) {
        strcpy(robot->direction, "North");
    }
    printf("Robot turned left. New direction: %s.\n", robot->direction);
}

// Function to turn the robot right (90 degrees)
void turnRight(Robot *robot) {
    if (strcmp(robot->direction, "North") == 0) {
        strcpy(robot->direction, "East");
    } else if (strcmp(robot->direction, "East") == 0) {
        strcpy(robot->direction, "South");
    } else if (strcmp(robot->direction, "South") == 0) {
        strcpy(robot->direction, "West");
    } else if (strcmp(robot->direction, "West") == 0) {
        strcpy(robot->direction, "North");
    }
    printf("Robot turned right. New direction: %s.\n", robot->direction);
}

// Function to report the current position and direction of the robot
void reportPosition(Robot *robot) {
    printf("Current position: (%d, %d), facing %s.\n", robot->x, robot->y, robot->direction);
}

// Function to display available instructions for the user
void displayInstructions() {
    printf("\nRobot Movement Control Instructions:\n");
    printf("1 - Move Forward\n");
    printf("2 - Turn Left\n");
    printf("3 - Turn Right\n");
    printf("4 - Report Position\n");
    printf("5 - Display Instructions\n");
    printf("6 - Exit\n");
}