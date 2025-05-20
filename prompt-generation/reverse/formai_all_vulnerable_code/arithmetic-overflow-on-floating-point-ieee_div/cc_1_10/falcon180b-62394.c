//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Define the structure of a robot
typedef struct {
    double x;
    double y;
    double theta;
    double v;
    double w;
} Robot;

// Initialize the robot at the origin with zero velocity
void init_robot(Robot* robot) {
    robot->x = 0;
    robot->y = 0;
    robot->theta = 0;
    robot->v = 0;
    robot->w = 0;
}

// Move the robot forward by a certain distance
void move_forward(Robot* robot, double distance) {
    double delta_theta = distance / robot->v;
    robot->x += robot->v * cos(robot->theta) * delta_theta;
    robot->y += robot->v * sin(robot->theta) * delta_theta;
    robot->theta += delta_theta;
}

// Turn the robot left by a certain angle
void turn_left(Robot* robot, double angle) {
    double delta_theta = angle / robot->w;
    robot->theta += delta_theta;
}

// Turn the robot right by a certain angle
void turn_right(Robot* robot, double angle) {
    double delta_theta = angle / robot->w;
    robot->theta -= delta_theta;
}

// Main function to control the robot's movement
int main() {
    srand(time(NULL));

    // Initialize the robot
    Robot robot;
    init_robot(&robot);

    // Move the robot forward
    move_forward(&robot, 10);
    printf("Moved forward 10 units.\n");

    // Turn the robot left
    turn_left(&robot, 90);
    printf("Turned left 90 degrees.\n");

    // Move the robot forward again
    move_forward(&robot, 20);
    printf("Moved forward 20 units.\n");

    // Turn the robot right
    turn_right(&robot, 180);
    printf("Turned right 180 degrees.\n");

    // Move the robot forward one more time
    move_forward(&robot, 30);
    printf("Moved forward 30 units.\n");

    return 0;
}