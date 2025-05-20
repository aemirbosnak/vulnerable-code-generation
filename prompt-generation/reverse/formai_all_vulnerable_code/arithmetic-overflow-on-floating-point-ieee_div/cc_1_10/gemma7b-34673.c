//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

// Define the masses of each planet (in kilograms)
double masses[NUM_PLANETS] = {
    1.9891e30,  // Sun
    5.972e24,  // Earth
    1.001e25,  // Mars
    1.898e25,  // Jupiter
    5.90e24,  // Venus
    9.54e24,  // Saturn
    8.98e24  // Uranus
};

// Define the orbital radii of each planet (in meters)
double radii[NUM_PLANETS] = {
    0,  // Sun
    1.52e11,  // Earth
    2.48e11,  // Mars
    5.20e11,  // Jupiter
    6.79e11,  // Venus
    1.52e12,  // Saturn
    2.86e12  // Uranus
};

// Define the orbital velocities of each planet (in meters per second)
double velocities[NUM_PLANETS] = {
    0,  // Sun
    29.78e3,  // Earth
    24.02e3,  // Mars
    13.06e3,  // Jupiter
    29.78e3,  // Venus
    12.08e3,  // Saturn
    9.74e3  // Uranus
};

int main()
{
    // Simulate the Solar System
    for (int i = 0; i < NUM_PLANETS; i++)
    {
        // Calculate the acceleration of each planet due to gravity
        double acceleration = masses[i] / (6.674e-11) * masses[0] / radii[i] * radii[0];

        // Update the orbital velocity of each planet
        velocities[i] += acceleration * 0.01;

        // Print the orbital velocity of each planet
        printf("Planet %d: Velocity = %.2e m/s\n", i + 1, velocities[i]);
    }

    return 0;
}