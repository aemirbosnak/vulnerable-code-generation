//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define ROBOT_SPEED 50
#define ROBOT_RADIUS 10
#define ROBOT_ANGLE_THRESHOLD 0.1
#define ROBOT_LINEAR_ACCELERATION 1
#define ROBOT_ANGULAR_ACCELERATION 1

typedef struct {
    double x;
    double y;
    double theta;
} RobotPosition;

void updateRobotPosition(RobotPosition* robot, double dx, double dy) {
    robot->x += dx * cos(robot->theta);
    robot->y += dx * sin(robot->theta);
    robot->theta += dy;
}

void drawRobot(RobotPosition robot) {
    printf("Robot: ");
    printf("x = %.2f\ty = %.2f\ttheta = %.2f\n", robot.x, robot.y, robot.theta);
}

int main() {
    srand(time(NULL));
    RobotPosition robot = {0, 0, 0};
    int choice;

    while (1) {
        printf("Choose your move:\n");
        printf("1. Move forward\n2. Turn left\n3. Turn right\n4. Stop\n");
        scanf("%d", &choice);

        if (choice == 1) {
            double distance = ROBOT_SPEED * ROBOT_LINEAR_ACCELERATION;
            updateRobotPosition(&robot, distance, 0);
        } else if (choice == 2) {
            double angle = rand() % 360;
            updateRobotPosition(&robot, 0, angle);
        } else if (choice == 3) {
            double angle = rand() % 360;
            updateRobotPosition(&robot, 0, -angle);
        } else if (choice == 4) {
            drawRobot(robot);
        }
    }

    return 0;
}