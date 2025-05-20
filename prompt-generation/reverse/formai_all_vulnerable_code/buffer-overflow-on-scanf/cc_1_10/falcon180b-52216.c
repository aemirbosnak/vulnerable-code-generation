//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROBOTS 100
#define MAX_COMMANDS 100

struct Robot {
    int id;
    int x;
    int y;
    int direction;
};

struct Command {
    int robotId;
    int command;
};

void moveRobot(struct Robot* robot, int command) {
    switch(command) {
        case 0: // Move forward
            robot->x += 1;
            break;
        case 1: // Turn left
            robot->direction = (robot->direction + 3) % 4;
            break;
        case 2: // Turn right
            robot->direction = (robot->direction + 1) % 4;
            break;
        case 3: // Move backward
            robot->x -= 1;
            break;
    }
}

int main() {
    int numRobots, numCommands;
    scanf("%d %d", &numRobots, &numCommands);

    struct Robot robots[MAX_ROBOTS];
    for(int i=0; i<numRobots; i++) {
        robots[i].id = i;
        robots[i].x = 0;
        robots[i].y = 0;
        robots[i].direction = 0; // North
    }

    struct Command commands[MAX_COMMANDS];
    for(int i=0; i<numCommands; i++) {
        scanf("%d %d", &commands[i].robotId, &commands[i].command);
    }

    for(int i=0; i<numCommands; i++) {
        moveRobot(&robots[commands[i].robotId], commands[i].command);
    }

    for(int i=0; i<numRobots; i++) {
        printf("Robot %d is at (%d,%d)\n", i, robots[i].x, robots[i].y);
    }

    return 0;
}