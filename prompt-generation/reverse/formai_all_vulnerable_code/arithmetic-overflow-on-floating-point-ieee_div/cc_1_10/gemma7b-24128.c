//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 5

// Define the mass of each planet
double masses[] = {1.0e30, 2.0e30, 3.0e30, 4.0e30, 5.0e30};

// Define the position and velocity of each planet
double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
double y[] = {0.0, 0.0, 0.0, 0.0, 0.0};
double vx[] = {0.0, 0.5, -0.2, 0.3, -0.4};
double vy[] = {0.0, 0.0, 0.0, 0.0, 0.0};

// Calculate the gravitational force between two masses
double force(double m1, double m2, double dx, double dy)
{
    double distance = sqrt(dx * dx + dy * dy);
    return (6.674e-11 * m1 * m2) / distance;
}

// Update the position and velocity of each planet
void update(double dt)
{
    for (int i = 0; i < NUM_PLANETS; i++)
    {
        double ax = force(masses[i], masses[0], x[i] - x[0], y[i] - y[0]) * vx[i] * dt;
        double ay = force(masses[i], masses[0], x[i] - x[0], y[i] - y[0]) * vy[i] * dt;
        x[i] += ax * dt;
        y[i] += ay * dt;
    }
}

int main()
{
    // Set the time step
    double dt = 0.01;

    // Simulate the planets for a number of steps
    for (int t = 0; t < 1000; t++)
    {
        update(dt);
    }

    // Print the final positions of the planets
    for (int i = 0; i < NUM_PLANETS; i++)
    {
        printf("Planet %d: x = %.2f, y = %.2f\n", i + 1, x[i], y[i]);
    }

    return 0;
}