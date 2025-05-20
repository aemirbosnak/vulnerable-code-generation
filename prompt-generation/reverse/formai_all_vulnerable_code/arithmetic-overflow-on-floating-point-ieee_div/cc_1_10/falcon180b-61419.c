//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the structure of the robot
typedef struct {
    double x, y, theta;
    double v, w;
} Robot;

// Initialize the robot at the origin with zero velocity
void initRobot(Robot* robot) {
    robot->x = 0;
    robot->y = 0;
    robot->theta = 0;
    robot->v = 0;
    robot->w = 0;
}

// Move the robot forward by a given distance
void moveForward(Robot* robot, double distance) {
    double deltaTheta = distance / robot->v;
    robot->x += distance * cos(robot->theta);
    robot->y += distance * sin(robot->theta);
    robot->theta += deltaTheta;
}

// Turn the robot left by a given angle
void turnLeft(Robot* robot, double angle) {
    double deltaTheta = angle / robot->w;
    robot->theta -= deltaTheta;
}

// Turn the robot right by a given angle
void turnRight(Robot* robot, double angle) {
    double deltaTheta = angle / robot->w;
    robot->theta += deltaTheta;
}

// Move the robot in a circle with a given radius and speed
void moveCircle(Robot* robot, double radius, double speed) {
    double omega = speed / radius;
    robot->v = omega * radius;
    robot->w = omega;
}

// Move the robot in a straight line with a given speed
void moveStraight(Robot* robot, double speed) {
    robot->v = speed;
    robot->w = 0;
}

// Stop the robot
void stopRobot(Robot* robot) {
    robot->v = 0;
    robot->w = 0;
}

// Main function
int main() {
    // Initialize the robot
    Robot robot;
    initRobot(&robot);

    // Move the robot forward
    moveForward(&robot, 10);

    // Turn the robot left
    turnLeft(&robot, PI / 4);

    // Move the robot in a circle
    moveCircle(&robot, 5, 1);

    // Move the robot in a straight line
    moveStraight(&robot, 2);

    // Turn the robot right
    turnRight(&robot, PI / 4);

    // Stop the robot
    stopRobot(&robot);

    return 0;
}