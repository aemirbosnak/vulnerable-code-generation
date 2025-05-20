//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to move the vehicle forward
void moveForward(float speed) {
    printf("Moving Forward at %f km/h\n", speed);
}

// Function to move the vehicle backward
void moveBackward(float speed) {
    printf("Moving Backward at %f km/h\n", speed);
}

// Function to move the vehicle left
void moveLeft(float angle) {
    printf("Moving Left at %f degrees\n", angle);
}

// Function to move the vehicle right
void moveRight(float angle) {
    printf("Moving Right at %f degrees\n", angle);
}

// Function to stop the vehicle
void stop() {
    printf("Vehicle Stopped\n");
}

// Function to turn the vehicle right
void turnRight(float speed, float angle) {
    printf("Turning Right at %f km/h and %f degrees\n", speed, angle);
}

// Function to turn the vehicle left
void turnLeft(float speed, float angle) {
    printf("Turning Left at %f km/h and %f degrees\n", speed, angle);
}

// Main function to control the vehicle
void controlVehicle(char direction) {
    if (direction == 'F') {
        moveForward(10.0);
    } else if (direction == 'B') {
        moveBackward(10.0);
    } else if (direction == 'L') {
        moveLeft(45.0);
    } else if (direction == 'R') {
        moveRight(45.0);
    } else if (direction == 'S') {
        stop();
    } else if (direction == 'T') {
        turnRight(10.0, 45.0);
    } else if (direction == 'W') {
        turnLeft(10.0, 45.0);
    } else {
        printf("Invalid direction\n");
    }
}

int main() {
    char direction;
    printf("Enter direction: ");
    scanf("%c", &direction);
    controlVehicle(direction);
    return 0;
}