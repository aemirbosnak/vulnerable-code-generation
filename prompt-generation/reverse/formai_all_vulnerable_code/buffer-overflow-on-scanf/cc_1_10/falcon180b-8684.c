//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define WHEEL_BASE 0.25 // Distance between the two wheels
#define WHEEL_DIAMETER 0.1 // Diameter of each wheel
#define ENCODER_TICKS_PER_REV 100 // Number of ticks per revolution of the encoder

// Function to calculate the distance traveled by the robot based on the number of encoder ticks
double calculateDistance(int ticks) {
    double distance = (double)ticks * (2 * PI * WHEEL_DIAMETER) / ENCODER_TICKS_PER_REV;
    return distance;
}

// Function to calculate the angle turned by the robot based on the number of encoder ticks
double calculateAngle(int ticks) {
    double angle = (double)ticks * (2 * PI / ENCODER_TICKS_PER_REV);
    return angle;
}

// Function to move the robot forward by the specified distance
void moveForward(double distance) {
    printf("Moving forward by %f meters\n", distance);
}

// Function to turn the robot by the specified angle
void turn(double angle) {
    printf("Turning by %f radians\n", angle);
}

// Recursive function to move the robot in a specified direction
void move(double distance, double angle) {
    if (distance > 0) {
        moveForward(distance);
    }
    if (angle!= 0) {
        turn(angle);
    }
}

// Main function to control the movement of the robot
int main() {
    int choice;
    double distance, angle;

    while (1) {
        printf("\nEnter your choice:\n1. Move forward\n2. Turn\n3. Move forward and turn\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the distance to move forward (in meters): ");
            scanf("%lf", &distance);
            moveForward(distance);
            break;
        case 2:
            printf("Enter the angle to turn (in radians): ");
            scanf("%lf", &angle);
            turn(angle);
            break;
        case 3:
            printf("Enter the distance to move forward (in meters): ");
            scanf("%lf", &distance);
            printf("Enter the angle to turn (in radians): ");
            scanf("%lf", &angle);
            move(distance, angle);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}