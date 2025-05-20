//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define robot parameters
#define WHEEL_RADIUS 0.05
#define WHEEL_SEPARATION 0.25
#define BASE_LENGTH 0.3

// Define movement functions
void move_forward(double speed) {
    printf("Moving forward at %f m/s\n", speed);
}

void turn(double angle) {
    printf("Turning by %f degrees\n", angle);
}

// Define main function
int main() {
    // Initialize robot position
    double x = 0.0;
    double y = 0.0;
    double theta = 0.0;

    // Get user input for movement
    double speed;
    double angle;

    printf("Enter speed (m/s): ");
    scanf("%lf", &speed);

    printf("Enter turn angle (degrees): ");
    scanf("%lf", &angle);

    // Calculate new robot position
    double delta_theta = angle * PI / 180.0;
    double delta_x = speed * cos(theta) * delta_theta;
    double delta_y = speed * sin(theta) * delta_theta;

    x += delta_x;
    y += delta_y;
    theta += angle;

    // Print final robot position
    printf("Final position: (%f, %f) at %f degrees\n", x, y, theta);

    return 0;
}