//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate angle between two points
double angle(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double angle = atan2(dy, dx);
    return angle * 180 / PI;
}

// Function to move the robot
void move(double speed, double turn) {
    printf("Moving at %.2f m/s and turning at %.2f degrees.\n", speed, turn);
}

// Function to stop the robot
void stop() {
    printf("Robot stopped.\n");
}

// Function to turn the robot left
void turn_left(double angle) {
    printf("Turning left by %.2f degrees.\n", angle);
}

// Function to turn the robot right
void turn_right(double angle) {
    printf("Turning right by %.2f degrees.\n", angle);
}

int main() {
    double x1, y1, x2, y2;
    double speed, turn;
    char choice;

    // Initialize robot position
    x1 = 0;
    y1 = 0;

    // Get user input for speed and turn
    printf("Enter speed (in m/s): ");
    scanf("%lf", &speed);
    printf("Enter turn (in degrees): ");
    scanf("%lf", &turn);

    while (1) {
        printf("Enter command (m for move, s for stop, l for left turn, r for right turn): ");
        scanf(" %c", &choice);

        switch (choice) {
            case'm':
                move(speed, turn);
                break;
            case's':
                stop();
                break;
            case 'l':
                printf("Enter turn angle: ");
                scanf("%lf", &turn);
                turn_left(turn);
                break;
            case 'r':
                printf("Enter turn angle: ");
                scanf("%lf", &turn);
                turn_right(turn);
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}