//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Define robot structure
typedef struct {
    double x, y, theta; // position and orientation
    double v, w; // linear and angular velocity
} Robot;

// Initialize robot at origin with zero velocity and facing north
void initRobot(Robot* r) {
    r->x = 0;
    r->y = 0;
    r->theta = 0;
    r->v = 0;
    r->w = 0;
}

// Move robot forward by given distance in meters
void moveForward(Robot* r, double distance) {
    double dt = 0.1; // time step in seconds
    double v = r->v; // current linear velocity
    double w = r->w; // current angular velocity
    double t = distance / v; // time needed to travel distance
    r->x += v * t;
    r->y += w * t * PI / 180; // convert angular velocity from radians to meters
    r->theta += w * t * 180 / PI; // update orientation in degrees
}

// Turn robot left or right by given angle in degrees
void turn(Robot* r, double angle) {
    double dt = 0.1; // time step in seconds
    double v = r->v; // current linear velocity
    double w = r->w; // current angular velocity
    double t = angle / w; // time needed to turn angle
    r->theta += w * t * 180 / PI; // update orientation in degrees
}

// Main function for robot control
int main() {
    Robot robot;
    initRobot(&robot);

    // Example movement sequence
    moveForward(&robot, 5);
    turn(&robot, 90);
    moveForward(&robot, 3);
    turn(&robot, -45);

    return 0;
}