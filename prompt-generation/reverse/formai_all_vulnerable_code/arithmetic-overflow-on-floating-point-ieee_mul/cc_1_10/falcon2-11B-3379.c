//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// Function to calculate the gravitational force between two planets
double gravityForce(double mass1, double mass2, double distance)
{
    double G = 6.67430e-11; // Universal Gravitational Constant
    return (G * mass1 * mass2) / pow(distance, 2);
}

// Function to calculate the acceleration of a planet
double planetAcceleration(double mass, double force)
{
    return force / mass;
}

// Function to simulate the movement of a planet
void simulatePlanet(double x, double y, double mass, double force)
{
    double dx = 0;
    double dy = 0;
    double dt = 0.01; // Time step
    int count = 0;
    
    while (count < 10000)
    {
        dx = dx + (force / mass) * dt;
        dy = dy + (force / mass) * dt;
        x = x + dx;
        y = y + dy;
        count++;
    }
    
    printf("Planet's trajectory:\n");
    printf("x = %f, y = %f\n", x, y);
}

int main()
{
    // Create two planets
    double mass1 = 5.97e24; // Earth's mass
    double mass2 = 7.34e22; // Moon's mass
    double distance = 384400; // Average distance between Earth and Moon
    
    // Calculate gravitational force
    double force = gravityForce(mass1, mass2, distance);
    
    // Simulate the movement of the Moon
    simulatePlanet(0, 0, mass2, force);
    
    return 0;
}