//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MOTOR_SPEED 100
#define WHEEL_RADIUS 2.5
#define WHEEL_BASE 17.0
#define MAX_SPEED 0.5
#define MAX_TURN 0.5

// Define the robot's position and orientation
struct robot {
    double x;
    double y;
    double theta;
};

// Initialize the robot's position and orientation
void init_robot(struct robot* r) {
    r->x = 0.0;
    r->y = 0.0;
    r->theta = 0.0;
}

// Move the robot forward by a given distance
void move_forward(struct robot* r, double distance) {
    double delta_theta = distance / WHEEL_BASE * tan(r->theta);
    r->x += cos(r->theta) * distance;
    r->y += sin(r->theta) * distance;
    r->theta += delta_theta;
}

// Turn the robot by a given angle
void turn(struct robot* r, double angle) {
    r->theta += angle;
}

// Limit the robot's speed and turn rate
void limit_speed(struct robot* r) {
    if (r->theta > MAX_TURN) {
        r->theta = MAX_TURN;
    } else if (r->theta < -MAX_TURN) {
        r->theta = -MAX_TURN;
    }
    if (sqrt(pow(r->x, 2) + pow(r->y, 2)) > MAX_SPEED) {
        double factor = MAX_SPEED / sqrt(pow(r->x, 2) + pow(r->y, 2));
        r->x *= factor;
        r->y *= factor;
    }
}

// Print the robot's position and orientation
void print_robot(struct robot* r) {
    printf("X: %.2f, Y: %.2f, Theta: %.2f\n", r->x, r->y, r->theta);
}

// Main function
int main() {
    struct robot r;
    init_robot(&r);
    double distance = 20.0;
    double angle = 90.0;

    // Move forward
    move_forward(&r, distance);
    print_robot(&r);

    // Turn
    turn(&r, angle);
    print_robot(&r);

    // Limit speed and turn rate
    limit_speed(&r);
    print_robot(&r);

    return 0;
}