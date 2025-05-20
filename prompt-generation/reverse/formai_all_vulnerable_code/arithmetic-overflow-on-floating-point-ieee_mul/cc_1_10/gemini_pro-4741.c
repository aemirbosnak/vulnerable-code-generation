//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass of the Sun in kilograms
#define M_SUN 1.989e30

// Define the gravitational constant in meters cubed per kilogram per second squared
#define G 6.674e-11

// Define the time step in seconds
#define DT 1000

// Define the number of planets in the solar system
#define N_PLANETS 8

// Define the masses of the planets in kilograms
double m_planets[] = {
    3.301e23, // Mercury
    4.867e24, // Venus
    5.972e24, // Earth
    6.417e23, // Mars
    1.898e27, // Jupiter
    5.684e26, // Saturn
    8.683e25, // Uranus
    1.024e26  // Neptune
};

// Define the initial positions of the planets in meters
double x_planets[] = {
    5.79e10, // Mercury
    1.082e11, // Venus
    1.496e11, // Earth
    2.279e11, // Mars
    7.783e11, // Jupiter
    1.426e12, // Saturn
    2.870e12, // Uranus
    4.495e12  // Neptune
};

// Define the initial velocities of the planets in meters per second
double v_planets[] = {
    47360, // Mercury
    35020, // Venus
    29780, // Earth
    24070, // Mars
    13070, // Jupiter
    9690, // Saturn
    6810, // Uranus
    5430  // Neptune
};

// Define the initial accelerations of the planets in meters per second squared
double a_planets[] = {
    0, // Mercury
    0, // Venus
    0, // Earth
    0, // Mars
    0, // Jupiter
    0, // Saturn
    0, // Uranus
    0  // Neptune
};

// Main function
int main()
{
    // Initialize the simulation
    int i, j;
    for (i = 0; i < N_PLANETS; i++) {
        a_planets[i] = -G * M_SUN / pow(x_planets[i], 2);
    }

    // Run the simulation
    for (i = 0; i < 10000; i++) {
        // Update the positions of the planets
        for (j = 0; j < N_PLANETS; j++) {
            x_planets[j] += v_planets[j] * DT + 0.5 * a_planets[j] * pow(DT, 2);
        }

        // Update the velocities of the planets
        for (j = 0; j < N_PLANETS; j++) {
            v_planets[j] += a_planets[j] * DT;
        }

        // Update the accelerations of the planets
        for (j = 0; j < N_PLANETS; j++) {
            a_planets[j] = -G * M_SUN / pow(x_planets[j], 2);
        }

        // Print the positions of the planets
        for (j = 0; j < N_PLANETS; j++) {
            printf("%d %e\n", i, x_planets[j]);
        }
    }

    return 0;
}