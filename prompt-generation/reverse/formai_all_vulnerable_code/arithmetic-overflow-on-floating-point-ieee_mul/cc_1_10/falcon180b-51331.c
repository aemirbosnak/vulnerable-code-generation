//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

float getDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

float getAngle(float x1, float y1, float x2, float y2) {
    float dx = x2-x1;
    float dy = y2-y1;
    float angle = atan2(dy, dx);
    if (angle < 0) {
        angle += 2*PI;
    }
    return angle;
}

void move(float speed, float angle) {
    float wheelRadius = 0.1; // in meters
    float leftWheelVelocity = speed*cos(angle);
    float rightWheelVelocity = speed*sin(angle);
    printf("Moving at %f m/s with an angle of %f degrees\n", speed, angle*180/PI);
}

void turn(float angle) {
    float wheelRadius = 0.1; // in meters
    float leftWheelVelocity = -sin(angle);
    float rightWheelVelocity = cos(angle);
    printf("Turning at %f degrees/s\n", angle*180/PI);
}

int main() {
    // Initialize robot position
    float x = 0;
    float y = 0;
    float theta = 0;

    // Define goal position
    float goalX = 5;
    float goalY = 10;

    // Move to goal position
    while (getDistance(x, y, goalX, goalY) > 0.1) {
        float angleToGoal = getAngle(x, y, goalX, goalY);
        move(0.5, angleToGoal);
        x += 0.5*cos(theta);
        y += 0.5*sin(theta);
        theta += 0.5*angleToGoal;
    }

    // Turn around and move back to starting position
    theta = 2*PI - theta;
    while (getDistance(x, y, 0, 0) > 0.1) {
        float angleToGoal = getAngle(x, y, 0, 0);
        turn(angleToGoal);
        x += 0.5*cos(theta);
        y += 0.5*sin(theta);
        theta += 0.5*angleToGoal;
    }

    // Done!
    return 0;
}