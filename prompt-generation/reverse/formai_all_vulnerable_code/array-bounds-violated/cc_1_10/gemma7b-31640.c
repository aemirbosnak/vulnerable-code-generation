//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

// Define the masses of the planets
double mass[] = {
    3.0e11,  // Sun
    5.9e24,  // Earth
    1.0e25,  // Mars
    1.0e26,  // Jupiter
    5.0e24,  // Venus
    1.0e27,  // Saturn
    8.0e24  // Titan
};

// Define the orbital radii of the planets
double radius[] = {
    0.0,  // Sun
    1.52e11,  // Earth
    2.28e11,  // Mars
    5.20e11,  // Jupiter
    6.79e11,  // Venus
    1.49e12,  // Saturn
    1.22e12  // Titan
};

// Define the orbital speeds of the planets
double speed[] = {
    0.0,  // Sun
    29.78e3,  // Earth
    24.02e3,  // Mars
    13.81e3,  // Jupiter
    24.62e3,  // Venus
    9.60e3,  // Saturn
    0.53e3  // Titan
};

int main()
{
    int i;

    // Initialize the celestial bodies
    for (i = 0; i < 9; i++)
    {
        printf("Planet %d: mass %.2e, radius %.2e, speed %.2e\n", i + 1, mass[i], radius[i], speed[i]);
    }

    return 0;
}