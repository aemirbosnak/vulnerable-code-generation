//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Constants
#define G 9.81   // Acceleration due to gravity (m/s^2)
#define DT 0.1   // Time step (s)

// Function prototypes
double calcHeight(double h, double v, double t);
double calcVelocity(double v, double t);
double calcEnergy(double m, double h, double v);

// Main function
int main()
{
    // Variables
    double mass, height, velocity, time, energy;
    bool isFalling = true;

    // User input
    printf("Enter mass (kg): ");
    scanf("%lf", &mass);
    printf("Enter initial height (m): ");
    scanf("%lf", &height);
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &velocity);

    // Simulation loop
    while (isFalling)
    {
        // Calculate new position and velocity
        height = calcHeight(height, velocity, DT);
        velocity = calcVelocity(velocity, DT);

        // Calculate energy
        energy = calcEnergy(mass, height, velocity);

        // Check if object has hit the ground
        if (height <= 0 && velocity <= 0)
        {
            isFalling = false;
            printf("Object has hit the ground\n");
        }

        // Output results
        printf("Time: %5.2f s | Height: %5.2f m | Velocity: %5.2f m/s | Energy: %5.2f J\n", time, height, velocity, energy);

        // Increment time
        time += DT;
    }

    return 0;
}

// Function to calculate new height
double calcHeight(double h, double v, double t)
{
    return h + v * t - 0.5 * G * t * t;
}

// Function to calculate new velocity
double calcVelocity(double v, double t)
{
    return v - G * t;
}

// Function to calculate energy
double calcEnergy(double m, double h, double v)
{
    return m * G * h + 0.5 * m * v * v;
}