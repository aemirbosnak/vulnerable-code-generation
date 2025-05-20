//FormAI DATASET v1.0 Category: Physics simulation ; Style: shocked
#include <stdio.h>
#include <math.h>

// Define gravity constant
#define G 6.67e-11

// Define particle structure
struct particle {
    double x;  // x position
    double y;  // y position
    double vx; // x velocity
    double vy; // y velocity
    double ax; // x acceleration
    double ay; // y acceleration
    double mass; // mass of particle
};

int main()
{
    // Create two particles
    struct particle p1, p2;

    // Initialize particle properties
    p1.x = 0;
    p1.y = 0;
    p1.vx = 0;
    p1.vy = 0;
    p1.ax = 0;
    p1.ay = 0;
    p1.mass = 5.97e24;

    p2.x = 0;
    p2.y = 0;
    p2.vx = 0;
    p2.vy = 0;
    p2.ax = 0;
    p2.ay = 0;
    p2.mass = 7.34e22;

    // Define time step and simulation duration
    double t_step = 60; // seconds
    double t_sim = 86400 * 30; // seconds (one month)

    // Simulate particle motion
    for (double t = 0; t < t_sim; t += t_step) {
        // Calculate distance between particles
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double r = sqrt(dx*dx + dy*dy);

        // Calculate gravitational force between particles
        double f = G * p1.mass * p2.mass / (r*r);

        // Calculate x and y components of force on p1
        double fx = f * dx / r;
        double fy = f * dy / r;

        // Calculate x and y components of acceleration on p1
        p1.ax = fx / p1.mass;
        p1.ay = fy / p1.mass;

        // Calculate x and y components of acceleration on p2 (opposite direction)
        p2.ax = -fx / p2.mass;
        p2.ay = -fy / p2.mass;

        // Update particle positions and velocities using Euler method
        p1.vx += p1.ax * t_step;
        p1.vy += p1.ay * t_step;
        p1.x += p1.vx * t_step;
        p1.y += p1.vy * t_step;

        p2.vx += p2.ax * t_step;
        p2.vy += p2.ay * t_step;
        p2.x += p2.vx * t_step;
        p2.y += p2.vy * t_step;
    }

    // Output final particle positions
    printf("Final particle 1 position: (%f, %f)\n", p1.x, p1.y);
    printf("Final particle 2 position: (%f, %f)\n", p2.x, p2.y);

    return 0;
}