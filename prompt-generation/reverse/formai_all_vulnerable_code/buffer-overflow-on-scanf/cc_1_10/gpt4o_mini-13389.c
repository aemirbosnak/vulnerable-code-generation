//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20
#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    char direction; // 'N' = North, 'E' = East, 'S' = South, 'W' = West
} Robot;

void initializeRobot(Robot *robot) {
    robot->x = GRID_SIZE / 2;
    robot->y = GRID_SIZE / 2;
    robot->direction = 'N'; // Starting facing North
}

void printStatus(Robot *robot) {
    printf("Robot Status:\n");
    printf("Location: (%d, %d)\n", robot->x, robot->y);
    printf("Facing: %c\n", robot->direction);
    printf("------------------------------\n");
}

void moveForward(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->y++; break;
        case 'E': robot->x++; break;
        case 'S': robot->y--; break;
        case 'W': robot->x--; break;
    }
}

void moveBackward(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->y--; break;
        case 'E': robot->x--; break;
        case 'S': robot->y++; break;
        case 'W': robot->x++; break;
    }
}

void turnLeft(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->direction = 'W'; break;
        case 'E': robot->direction = 'N'; break;
        case 'S': robot->direction = 'E'; break;
        case 'W': robot->direction = 'S'; break;
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

void updatePosition(Robot *robot) {
    if (robot->x < 0) robot->x = 0;
    if (robot->x >= GRID_SIZE) robot->x = GRID_SIZE - 1;
    if (robot->y < 0) robot->y = 0;
    if (robot->y >= GRID_SIZE) robot->y = GRID_SIZE - 1;
}

void executeCommand(Robot *robot, const char *command) {
    if (strcmp(command, "move") == 0) {
        moveForward(robot);
    } else if (strcmp(command, "back") == 0) {
        moveBackward(robot);
    } else if (strcmp(command, "left") == 0) {
        turnLeft(robot);
    } else if (strcmp(command, "right") == 0) {
        turnRight(robot);
    } else {
        printf("Unknown command: %s\n", command);
    }
    updatePosition(robot);
    printStatus(robot);
}

int main() {
    Robot robot;
    char command[MAX_COMMAND_LENGTH];
    
    initializeRobot(&robot);
    printf("Welcome to the Robot Control Program!\n");
    printStatus(&robot);

    while (1) {
        printf("Enter a command (move, back, left, right, exit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the Robot Control Program.\n");
            break;
        }
        
        executeCommand(&robot, command);
    }

    return 0;
}