//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants for the robot's movement
#define MOTOR_SPEED 50
#define WHEEL_DIAMETER 6
#define PI 3.14159

// Function to calculate the distance traveled by the robot
double distanceTraveled(int numRev) {
    double circumference = WHEEL_DIAMETER * PI;
    double distance = numRev * circumference;
    return distance;
}

int main() {
    int leftWheelRev = 0, rightWheelRev = 0;
    char dir;
    
    printf("Enter a direction (F = forward, B = backward, L = left, R = right): ");
    scanf(" %c", &dir);
    
    switch (dir) {
        case 'F':
            leftWheelRev = rightWheelRev = 50;
            break;
        case 'B':
            leftWheelRev = rightWheelRev = -50;
            break;
        case 'L':
            leftWheelRev = -50;
            rightWheelRev = 50;
            break;
        case 'R':
            leftWheelRev = 50;
            rightWheelRev = -50;
            break;
        default:
            printf("Invalid direction!");
            return 0;
    }
    
    // Calculate the distance traveled by each wheel
    double leftDistance = distanceTraveled(leftWheelRev);
    double rightDistance = distanceTraveled(rightWheelRev);
    
    // Calculate the angle turned by the robot
    double angle = (rightDistance - leftDistance) / (2 * WHEEL_DIAMETER);
    angle = angle * (180 / PI);
    
    printf("The robot traveled %.2f inches.\n", (leftDistance + rightDistance) / 2);
    printf("The robot turned %.2f degrees.\n", angle);
    
    return 0;
}