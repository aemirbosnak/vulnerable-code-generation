//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the robot's position and orientation
struct robot {
    double x, y, theta;
};

// Define the robot's movement functions
void move_forward(struct robot* robot, double distance) {
    robot->x += cos(robot->theta) * distance;
    robot->y += sin(robot->theta) * distance;
}

void turn_left(struct robot* robot, double angle) {
    robot->theta -= angle;
}

void turn_right(struct robot* robot, double angle) {
    robot->theta += angle;
}

// Define the robot's control functions
void control_robot(struct robot* robot, int direction, double speed, double turn) {
    switch (direction) {
        case 1:
            move_forward(robot, speed);
            break;
        case 2:
            move_forward(robot, -speed);
            break;
        case 3:
            turn_left(robot, turn);
            break;
        case 4:
            turn_right(robot, turn);
            break;
        default:
            break;
    }
}

// Define the robot's main function
int main() {
    struct robot robot = {0, 0, 0};
    int direction, speed, turn;

    // Initialize the robot's position
    robot.x = 0;
    robot.y = 0;
    robot.theta = 0;

    // Get the robot's movement parameters from the user
    printf("Enter the robot's initial direction (1 = forward, 2 = backward, 3 = left, 4 = right): ");
    scanf("%d", &direction);
    printf("Enter the robot's initial speed: ");
    scanf("%lf", &speed);
    printf("Enter the robot's initial turn angle: ");
    scanf("%lf", &turn);

    // Move the robot
    control_robot(&robot, direction, speed, turn);

    // Print the robot's final position
    printf("The robot's final position is: (%.2lf, %.2lf, %.2lf)\n", robot.x, robot.y, robot.theta);

    return 0;
}