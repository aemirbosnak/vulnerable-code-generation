//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the structure for the robot
typedef struct {
    double x;
    double y;
    double theta;
} Robot;

// Define the function for initializing the robot
void initRobot(Robot* robot) {
    robot->x = 0.0;
    robot->y = 0.0;
    robot->theta = 0.0;
}

// Define the function for moving the robot forward
void moveForward(Robot* robot, double distance) {
    double deltaTheta = distance / robot->theta;
    robot->x += cos(robot->theta) * distance;
    robot->y += sin(robot->theta) * distance;
    robot->theta += deltaTheta;
}

// Define the function for turning the robot left
void turnLeft(Robot* robot, double angle) {
    robot->theta -= angle;
}

// Define the function for turning the robot right
void turnRight(Robot* robot, double angle) {
    robot->theta += angle;
}

// Define the function for calculating the distance between two points
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

// Define the main function
int main() {
    // Initialize the robot
    Robot robot;
    initRobot(&robot);

    // Move the robot forward
    moveForward(&robot, 10.0);

    // Turn the robot left
    turnLeft(&robot, PI / 4);

    // Move the robot forward
    moveForward(&robot, 5.0);

    // Turn the robot right
    turnRight(&robot, PI / 4);

    // Move the robot forward
    moveForward(&robot, 5.0);

    // Print the final position of the robot
    printf("Final position of the robot: (%lf, %lf, %lf)\n", robot.x, robot.y, robot.theta);

    return 0;
}