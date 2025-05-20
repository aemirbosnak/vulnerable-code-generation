//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

// Robot structure holding its position
typedef struct {
    int x, y;
} Robot;

// Function declarations
void initializeRobot(Robot *robot);
void displayGrid(Robot *robot);
void moveRobot(Robot *robot, char direction);

int main() {
    Robot robot;
    initializeRobot(&robot);
    
    char command;
    printf("Welcome to the Exciting Robot Adventure!\n");
    printf("Your goal: Navigate the robot around the grid! Use 'w' (up), 's' (down), 'a' (left), 'd' (right), or 'q' (quit).\n");

    while (1) {
        displayGrid(&robot);
        printf("Enter your command (w/a/s/d): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("The robot is saying goodbye! Adventure ended.\n");
            break;
        }

        moveRobot(&robot, command);
    }

    return 0;
}

// Function to initialize the robot's position
void initializeRobot(Robot *robot) {
    robot->x = GRID_SIZE / 2; // Start in the middle of the grid
    robot->y = GRID_SIZE / 2;
}

// Function to display the grid with the robot's position
void displayGrid(Robot *robot) {
    system("clear"); // Clear the screen for a fresh display

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == robot->y && j == robot->x) {
                printf(" R "); // Display the Robot
            } else {
                printf(" . "); // Empty space
            }
        }
        printf("\n");
    }
}

// Function to move the robot based on the user's command
void moveRobot(Robot *robot, char direction) {
    printf("Robot is moving... ");
    switch (direction) {
        case 'w':
            if (robot->y > 0) {
                robot->y--;
                printf("Move up! Yay!\n");
            } else {
                printf("Can't move up! (Out of bounds)\n");
            }
            break;
        case 's':
            if (robot->y < GRID_SIZE - 1) {
                robot->y++;
                printf("Move down! Whee!\n");
            } else {
                printf("Can't move down! (Out of bounds)\n");
            }
            break;
        case 'a':
            if (robot->x > 0) {
                robot->x--;
                printf("Move left! Woohoo!\n");
            } else {
                printf("Can't move left! (Out of bounds)\n");
            }
            break;
        case 'd':
            if (robot->x < GRID_SIZE - 1) {
                robot->x++;
                printf("Move right! Yippee!\n");
            } else {
                printf("Can't move right! (Out of bounds)\n");
            }
            break;
        default:
            printf("Invalid command! Please use w/a/s/d!\n");
            break;
    }
}