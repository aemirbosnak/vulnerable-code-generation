//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the robot's position and orientation
struct {
    double x, y, z;
    double roll, pitch, yaw;
} robot;

// Define the robot's movement and rotation functions
void moveForward(double distance) {
    double dx = cos(robot.yaw) * distance;
    double dy = sin(robot.yaw) * distance;
    robot.x += dx;
    robot.y += dy;
}

void turn(double angle) {
    robot.yaw += angle;
}

// Define the robot's shape-shifting functions
void shiftToSphere() {
    robot.x = 0;
    robot.y = 0;
    robot.z = 0;
    robot.roll = 0;
    robot.pitch = 0;
    robot.yaw = 0;
}

void shiftToBox() {
    robot.x = 0;
    robot.y = 0;
    robot.z = 0;
    robot.roll = 0;
    robot.pitch = 0;
    robot.yaw = 0;
}

void shiftToCylinder() {
    robot.x = 0;
    robot.y = 0;
    robot.z = 0;
    robot.roll = 0;
    robot.pitch = 0;
    robot.yaw = 0;
}

// Define the robot's main control loop
int main() {
    shiftToSphere();

    while (1) {
        printf("Enter command (forward/turn/shift): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "forward") == 0) {
            printf("Enter distance: ");
            double distance;
            scanf("%lf", &distance);
            moveForward(distance);
        } else if (strcmp(command, "turn") == 0) {
            printf("Enter angle: ");
            double angle;
            scanf("%lf", &angle);
            turn(angle);
        } else if (strcmp(command, "sphere") == 0) {
            shiftToSphere();
        } else if (strcmp(command, "box") == 0) {
            shiftToBox();
        } else if (strcmp(command, "cylinder") == 0) {
            shiftToCylinder();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}