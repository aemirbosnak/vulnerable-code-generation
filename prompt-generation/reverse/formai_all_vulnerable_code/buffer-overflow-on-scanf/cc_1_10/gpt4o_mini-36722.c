//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVES 100

typedef struct {
    int x;
    int y;
    char direction; // N, E, S, W
} Robot;

void initializeRobot(Robot *robot);
void moveForward(Robot *robot);
void moveBackward(Robot *robot);
void turnLeft(Robot *robot);
void turnRight(Robot *robot);
void getCurrentPosition(const Robot *robot);
void displayInstructions();

int main() {
    Robot myRobot;
    initializeRobot(&myRobot);
    
    char command;
    displayInstructions();

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                moveForward(&myRobot);
                break;
            case 's':
                moveBackward(&myRobot);
                break;
            case 'a':
                turnLeft(&myRobot);
                break;
            case 'd':
                turnRight(&myRobot);
                break;
            case 'p':
                getCurrentPosition(&myRobot);
                break;
            case 'q':
                printf("Quitting the program.\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
        }
    }
    
    return 0;
}

void initializeRobot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
    robot->direction = 'N'; // Start facing North
    printf("Robot initialized at position (%d, %d) facing %c.\n", robot->x, robot->y, robot->direction);
}

void moveForward(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->y++; break;
        case 'E': robot->x++; break;
        case 'S': robot->y--; break;
        case 'W': robot->x--; break;
    }
    printf("Robot moved forward to (%d, %d) facing %c.\n", robot->x, robot->y, robot->direction);
}

void moveBackward(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->y--; break;
        case 'E': robot->x--; break;
        case 'S': robot->y++; break;
        case 'W': robot->x++; break;
    }
    printf("Robot moved backward to (%d, %d) facing %c.\n", robot->x, robot->y, robot->direction);
}

void turnLeft(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->direction = 'W'; break;
        case 'E': robot->direction = 'N'; break;
        case 'S': robot->direction = 'E'; break;
        case 'W': robot->direction = 'S'; break;
    }
    printf("Robot turned left and is now facing %c.\n", robot->direction);
}

void turnRight(Robot *robot) {
    switch (robot->direction) {
        case 'N': robot->direction = 'E'; break;
        case 'E': robot->direction = 'S'; break;
        case 'S': robot->direction = 'W'; break;
        case 'W': robot->direction = 'N'; break;
    }
    printf("Robot turned right and is now facing %c.\n", robot->direction);
}

void getCurrentPosition(const Robot *robot) {
    printf("Robot current position: (%d, %d) facing %c.\n", robot->x, robot->y, robot->direction);
}

void displayInstructions() {
    printf("Robot Control Instructions:\n");
    printf("w - Move Forward\n");
    printf("s - Move Backward\n");
    printf("a - Turn Left\n");
    printf("d - Turn Right\n");
    printf("p - Get Current Position\n");
    printf("q - Quit\n");
}