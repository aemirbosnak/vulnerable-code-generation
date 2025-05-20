//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the robot's position, velocity, and acceleration
struct robot {
    double x;
    double y;
    double theta;
    double vx;
    double vy;
    double omega;
};

// Define the robot's movement functions
void move_forward(struct robot *r) {
    r->vx += cos(r->theta) * r->omega;
    r->vy += sin(r->theta) * r->omega;
    r->x += r->vx;
    r->y += r->vy;
}

void turn_left(struct robot *r) {
    r->theta -= r->omega;
}

void turn_right(struct robot *r) {
    r->theta += r->omega;
}

// Define the robot's movement control functions
void control_robot(struct robot *r) {
    printf("Please enter the robot's desired movement:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Please enter the robot's forward speed (m/s): ");
            scanf("%lf", &r->omega);
            move_forward(r);
            break;
        case 2:
            printf("Please enter the robot's turn speed (rad/s): ");
            scanf("%lf", &r->omega);
            turn_left(r);
            break;
        case 3:
            printf("Please enter the robot's turn speed (rad/s): ");
            scanf("%lf", &r->omega);
            turn_right(r);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Define the main function
int main() {
    // Initialize the robot's position, velocity, and acceleration
    struct robot r = {0, 0, 0, 0, 0, 0};
    // Prompt the user to control the robot
    while (1) {
        control_robot(&r);
        // Display the robot's current position
        printf("The robot is currently at (%lf, %lf) with a heading of %lf rad.\n", r.x, r.y, r.theta);
    }
    return 0;
}