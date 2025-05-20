//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
    double dx, dy, vx, vy, angle, coefficient;
    int i, iterations;

    // Input parameters
    printf("Enter initial x and y coordinates: ");
    scanf("%lf %lf", &dx, &dy);
    printf("Enter initial velocity components (vx and vy): ");
    scanf("%lf %lf", &vx, &vy);
    printf("Enter angle of reflection (in degrees): ");
    scanf("%lf", &angle);
    printf("Enter coefficient of restitution (0 <= coefficient <= 1): ");
    scanf("%lf", &coefficient);

    // Calculate the initial horizontal and vertical components of the velocity
    vx = cos(angle * M_PI / 180.0);
    vy = sin(angle * M_PI / 180.0);

    // Initialize the simulation variables
    iterations = 1000;
    dx = dy = 0;
    vx = vy = 0;

    // Simulate the ball bouncing
    for (i = 0; i < iterations; i++) {
        // Update the velocity components
        vx += vx * coefficient;
        vy += vy * coefficient;

        // Update the horizontal and vertical coordinates
        dx += vx * cos(angle * M_PI / 180.0);
        dy += vy * sin(angle * M_PI / 180.0);

        // Calculate the new angle of reflection
        angle = acos(dy / sqrt(dx * dx + dy * dy));

        // Update the velocity components
        vx = cos(angle * M_PI / 180.0);
        vy = sin(angle * M_PI / 180.0);
    }

    // Output the final coordinates and velocity components
    printf("Final x and y coordinates: %.2lf %.2lf\n", dx, dy);
    printf("Final velocity components: %.2lf %.2lf\n", vx, vy);

    return 0;
}