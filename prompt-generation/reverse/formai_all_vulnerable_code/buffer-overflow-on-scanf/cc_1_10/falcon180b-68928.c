//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Robot;

void move(Robot *robot, double distance, double direction) {
    double dx = distance * cos(direction);
    double dy = distance * sin(direction);
    robot->x += dx;
    robot->y += dy;
    robot->theta += direction;
}

void turn(Robot *robot, double angle) {
    robot->theta += angle;
}

void print_robot(Robot robot) {
    printf("Robot is at (%lf, %lf) facing %lf degrees\n", robot.x, robot.y, robot.theta);
}

int main() {
    Robot robot = {0, 0, 0};

    printf("Enter the initial position of the robot (x y): ");
    scanf("%lf %lf", &robot.x, &robot.y);

    printf("Enter the initial direction of the robot (in degrees): ");
    scanf("%lf", &robot.theta);

    printf("Enter the distance to move forward (in meters): ");
    double distance = 5;

    printf("Enter the direction to move (in degrees): ");
    double direction = 90;

    move(&robot, distance, direction);
    print_robot(robot);

    printf("Enter the angle to turn (in degrees): ");
    double turn_angle = 45;

    turn(&robot, turn_angle);
    print_robot(robot);

    return 0;
}