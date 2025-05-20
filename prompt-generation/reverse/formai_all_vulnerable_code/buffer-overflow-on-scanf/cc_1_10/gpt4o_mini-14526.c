//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAP_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    char direction; // 'N', 'E', 'S', 'W'
} Robot;

void initRobot(Robot *robot) {
    robot->pos.x = 0;
    robot->pos.y = 0;
    robot->direction = 'N';
}

void printMap(Robot *robot) {
    char map[MAP_SIZE][MAP_SIZE] = { '.' };
    
    map[robot->pos.y][robot->pos.x] = 'R'; // R for robot
    
    printf("\nRobot Map:\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void moveForward(Robot *robot) {
    switch (robot->direction) {
        case 'N':
            if (robot->pos.y > 0) robot->pos.y--;
            break;
        case 'E':
            if (robot->pos.x < MAP_SIZE - 1) robot->pos.x++;
            break;
        case 'S':
            if (robot->pos.y < MAP_SIZE - 1) robot->pos.y++;
            break;
        case 'W':
            if (robot->pos.x > 0) robot->pos.x--;
            break;
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

void processCommand(Robot *robot, char command) {
    switch (command) {
        case 'F':
            moveForward(robot);
            break;
        case 'L':
            turnLeft(robot);
            break;
        case 'R':
            turnRight(robot);
            break;
        default:
            printf("Invalid command! Use 'F' to move forward, 'L' to turn left, 'R' to turn right.\n");
            break;
    }
}

int main() {
    Robot robot;
    initRobot(&robot);

    char command;
    while (1) {
        printMap(&robot);
        printf("Enter command (F: Forward, L: Left, R: Right, Q: Quit): ");
        scanf(" %c", &command);
        
        if (command == 'Q') {
            printf("Quitting...\n");
            break;
        }

        processCommand(&robot, command);
    }

    return 0;
}