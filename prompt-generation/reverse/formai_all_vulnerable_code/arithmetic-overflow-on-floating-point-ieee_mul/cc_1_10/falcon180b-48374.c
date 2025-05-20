//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Robot;

void move(Robot *robot, double distance, double angle) {
    double dx = distance * cos(angle);
    double dy = distance * sin(angle);
    robot->x += dx;
    robot->y += dy;
    robot->theta += angle;
}

void turn(Robot *robot, double angle) {
    robot->theta += angle;
}

void rotate(Robot *robot, double angle) {
    double cos_theta = cos(robot->theta);
    double sin_theta = sin(robot->theta);
    double new_x = robot->x * cos_theta - robot->y * sin_theta;
    double new_y = robot->x * sin_theta + robot->y * cos_theta;
    robot->x = new_x;
    robot->y = new_y;
}

int main() {
    Robot robot;
    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    printf("Enter the initial position of the robot (x y): ");
    scanf("%lf %lf", &robot.x, &robot.y);

    printf("Enter the initial orientation of the robot (theta): ");
    scanf("%lf", &robot.theta);

    printf("Enter the distance to move forward: ");
    double distance = 0;
    scanf("%lf", &distance);

    printf("Enter the angle to turn: ");
    double angle = 0;
    scanf("%lf", &angle);

    move(&robot, distance, angle);

    printf("The robot has moved to (%lf, %lf) with an orientation of %lf\n", robot.x, robot.y, robot.theta);

    return 0;
}