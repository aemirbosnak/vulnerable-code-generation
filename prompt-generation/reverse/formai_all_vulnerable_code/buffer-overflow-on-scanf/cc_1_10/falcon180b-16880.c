//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} robot_t;

void move(robot_t* robot, double v, double omega) {
    double dt = 0.01;
    double dx = v*cos(robot->theta)*dt;
    double dy = v*sin(robot->theta)*dt;
    double dtheta = omega*dt;

    robot->x += dx;
    robot->y += dy;
    robot->theta += dtheta;
}

void turn(robot_t* robot, double omega) {
    double dt = 0.01;
    double dtheta = omega*dt;

    robot->theta += dtheta;
}

void sense(robot_t* robot) {
    printf("Robot is at (%lf, %lf) with heading %lf\n", robot->x, robot->y, robot->theta);
}

int main() {
    srand(time(NULL));

    robot_t robot;
    robot.x = 0;
    robot.y = 0;
    robot.theta = rand() % 360;

    while (1) {
        printf("Enter command (f for forward, b for backward, l for left, r for right, s for sense): ");
        char command;
        scanf("%c", &command);

        switch (command) {
        case 'f':
            move(&robot, 0.1, 0);
            break;
        case 'b':
            move(&robot, -0.1, 0);
            break;
        case 'l':
            turn(&robot, -0.1);
            break;
        case 'r':
            turn(&robot, 0.1);
            break;
        case's':
            sense(&robot);
            break;
        default:
            printf("Invalid command\n");
        }

        usleep(100000); // Sleep for 100ms to simulate movement
    }

    return 0;
}