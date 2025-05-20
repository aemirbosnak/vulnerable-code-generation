//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    char direction; // N, S, E, W
} Robot;

void initializeRobot(Robot *robot) {
    robot->x = GRID_SIZE / 2;
    robot->y = GRID_SIZE / 2;
    robot->direction = 'N';
    printf("Robot initialized at position (%d, %d) facing %c\n", robot->x, robot->y, robot->direction);
}

void displayGrid(Robot robot) {
    system("clear"); // Not portable, but works in Unix-like systems
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == robot.y && j == robot.x) {
                printf("R "); // Represent the robot
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("Robot is facing: %c\n", robot.direction);
}

void moveForward(Robot *robot) {
    switch (robot->direction) {
        case 'N': if (robot->y > 0) robot->y--; break;
        case 'S': if (robot->y < GRID_SIZE - 1) robot->y++; break;
        case 'E': if (robot->x < GRID_SIZE - 1) robot->x++; break;
        case 'W': if (robot->x > 0) robot->x--; break;
    }
}

void moveBackward(Robot *robot) {
    switch (robot->direction) {
        case 'N': if (robot->y < GRID_SIZE - 1) robot->y++; break;
        case 'S': if (robot->y > 0) robot->y--; break;
        case 'E': if (robot->x > 0) robot->x--; break;
        case 'W': if (robot->x < GRID_SIZE - 1) robot->x++; break;
    }
}

void turnLeft(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->direction = 'W'; break;
        case 'W': robot->direction = 'S'; break;
        case 'S': robot->direction = 'E'; break;
        case 'E': robot->direction = 'N'; break;
    }
}

void turnRight(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->direction = 'E'; break;
        case 'E': robot->direction = 'S'; break;
        case 'S': robot->direction = 'W'; break;
        case 'W': robot->direction = 'N'; break;
    }
}

void processCommand(Robot *robot, char command) {
    switch (command) {
        case 'w': moveForward(robot); break;
        case 's': moveBackward(robot); break;
        case 'a': turnLeft(robot); break;
        case 'd': turnRight(robot); break;
        default: printf("Invalid command!\n"); break;
    }
    displayGrid(*robot);
}

int main() {
    Robot robot;
    initializeRobot(&robot);
    displayGrid(robot);

    char command;
    while (1) {
        printf("Enter command (w=forward, s=backward, a=turn left, d=turn right, q=quit): ");
        scanf(" %c", &command);
        if (command == 'q') {
            printf("Exiting program...\n");
            break;
        }
        processCommand(&robot, command);
    }
    
    return 0;
}