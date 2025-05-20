//FormAI DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

#define g 9.8 // Acceleration due to gravity (m/s^2)
#define c 0.1 // Air resistance coefficient

int main() {
    double v0, theta, m, x0, y0, x, y, t, vx, vy, ax, ay, Fx, Fy;
    double dt = 0.01; // Time step (s)

    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &v0);

    printf("Enter firing angle (degrees): ");
    scanf("%lf", &theta);
    theta = theta * M_PI / 180; // Convert to radians

    printf("Enter mass of bullet (kg): ");
    scanf("%lf", &m);

    printf("Enter initial x position (m): ");
    scanf("%lf", &x0);

    printf("Enter initial y position (m): ");
    scanf("%lf", &y0);

    // Calculate initial velocities
    vx = v0 * cos(theta);
    vy = v0 * sin(theta);

    // Initialize time and positions
    t = 0;
    x = x0;
    y = y0;

    // Simulation loop
    while (y >= 0) {
        // Calculate forces
        Fx = -c * vx * vx * vx / fabs(vx);
        Fy = -m*g - c * vy * vy * vy / fabs(vy);

        // Calculate accelerations
        ax = Fx / m;
        ay = Fy / m;

        // Update velocities and positions
        vx = vx + ax * dt;
        vy = vy + ay * dt;
        x = x + vx * dt;
        y = y + vy * dt;

        // Update time
        t = t + dt;
    }

    printf("Bullet hit the ground after %.2lf seconds\n", t);
    printf("Distance traveled: %.2lf meters\n", x - x0);

    return 0;
}