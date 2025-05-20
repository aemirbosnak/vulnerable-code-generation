//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_SPEED 10
#define MIN_SPEED -10
#define MAX_TURN 30
#define MIN_TURN -30

typedef struct {
    double x;
    double y;
    double theta;
    double v;
    double w;
} Robot;

void initRobot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
    robot->theta = 0;
    robot->v = 0;
    robot->w = 0;
}

void updateRobot(Robot *robot, double dt) {
    robot->x += robot->v * cos(robot->theta) * dt;
    robot->y += robot->v * sin(robot->theta) * dt;
    robot->theta += robot->w * dt;
    robot->v += robot->w * dt;
}

void drawRobot(Robot *robot) {
    printf("Robot at (%.2f, %.2f), theta = %.2f, v = %.2f, w = %.2f\n",
           robot->x, robot->y, robot->theta, robot->v, robot->w);
}

int main() {
    Robot robot;
    initRobot(&robot);

    char command[100];
    while (true) {
        printf("Enter command (forward, backward, left, right, stop): ");
        scanf("%s", command);
        if (strcmp(command, "forward") == 0) {
            robot.v = MAX_SPEED;
        } else if (strcmp(command, "backward") == 0) {
            robot.v = MIN_SPEED;
        } else if (strcmp(command, "left") == 0) {
            robot.w = MAX_TURN;
        } else if (strcmp(command, "right") == 0) {
            robot.w = MIN_TURN;
        } else if (strcmp(command, "stop") == 0) {
            robot.v = 0;
            robot.w = 0;
        } else {
            printf("Invalid command\n");
        }

        updateRobot(&robot, 0.1);
        drawRobot(&robot);
    }

    return 0;
}