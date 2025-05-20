//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define ROBOT_SPEED 50

// Function to calculate distance between two points
double calculate_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// Function to calculate angle between two points
double calculate_angle(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double angle = atan2(dy, dx);
    if (angle < 0) {
        angle += 2 * PI;
    }
    return angle;
}

// Function to move the robot
void move_robot(double x, double y, double angle) {
    printf("Moving robot to (%f, %f) with angle %f\n", x, y, angle);
}

// Function to rotate the robot
void rotate_robot(double angle) {
    printf("Rotating robot by %f degrees\n", angle);
}

int main() {
    // Initialize robot position and angle
    double robot_x = 0;
    double robot_y = 0;
    double robot_angle = 0;

    // Get user input for robot movement
    char input[50];
    printf("Enter robot movement command (e.g. move 10 20 90): ");
    scanf("%s", input);

    // Parse user input
    int num_tokens = sscanf(input, "move %lf %lf %lf", &robot_x, &robot_y, &robot_angle);
    if (num_tokens!= 3) {
        printf("Invalid robot movement command\n");
        return 1;
    }

    // Calculate distance and angle between current and target position
    double distance = calculate_distance(robot_x, robot_y, robot_x + ROBOT_SPEED * cos(robot_angle), robot_y + ROBOT_SPEED * sin(robot_angle));
    double target_angle = calculate_angle(robot_x, robot_y, robot_x + ROBOT_SPEED * cos(robot_angle), robot_y + ROBOT_SPEED * sin(robot_angle));

    // Move the robot
    if (distance > 0) {
        move_robot(robot_x + ROBOT_SPEED * cos(robot_angle), robot_y + ROBOT_SPEED * sin(robot_angle), target_angle);
    }

    // Rotate the robot
    if (abs(target_angle - robot_angle) > 0.1) {
        rotate_robot(target_angle - robot_angle);
    }

    return 0;
}