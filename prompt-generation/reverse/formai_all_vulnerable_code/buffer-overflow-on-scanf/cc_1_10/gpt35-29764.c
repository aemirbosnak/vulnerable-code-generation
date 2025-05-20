//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, v, alpha, t, dt;
    const float g = 9.8, k = 0.2, m = 0.1;
    int i;

    // Prompt user for initial conditions
    printf("Enter initial horizontal distance (m): ");
    scanf("%f", &x);
    printf("Enter initial vertical distance (m): ");
    scanf("%f", &y);
    printf("Enter initial velocity (m/s): ");
    scanf("%f", &v);
    printf("Enter initial launch angle (degrees): ");
    scanf("%f", &alpha);
    printf("Enter time step (s): ");
    scanf("%f", &dt);

    // Convert launch angle to radians
    alpha = alpha * M_PI / 180;

    // Initialize time variable
    t = 0;

    // Print column headers for output
    printf("Time (s)\tHorizontal distance (m)\tVertical distance (m)\n");

    // Loop through time steps until the projectile hits the ground
    while (y > 0) {
        // Calculate the x and y components of velocity
        float vx = v * cos(alpha);
        float vy = v * sin(alpha) - g*t;

        // Calculate the x and y components of acceleration
        float ax = -k/m * v * vx;
        float ay = -g - k/m * v * vy;

        // Update position and velocity in x direction
        x += vx * dt + 0.5 * ax * dt * dt;
        vx += ax * dt;

        // Update position and velocity in y direction
        y += vy * dt + 0.5 * ay * dt * dt;
        vy += ay * dt;

        // Update time variable
        t += dt;

        // Print output for current time step
        printf("%.2f\t\t%.2f\t\t\t%.2f\n", t, x, y);
    }

    // Print final time and distance
    printf("Projectile hit ground at %.2f seconds, traveling a horizontal distance of %.2f meters.\n", t, x);

    return 0;
}