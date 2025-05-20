//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the initial state of the system.
#define MASS 1.0
#define VELOCITY 1.0
#define POSITION 0.0

// Define the time step.
#define DT 0.01

// Define the gravitational constant.
#define G 9.81

// Define the number of time steps.
#define N 1000

// Define the initial state of the system.
double mass = MASS;
double velocity = VELOCITY;
double position = POSITION;

// Define the time step.
double dt = DT;

// Define the gravitational constant.
double g = G;

// Define the number of time steps.
int n = N;

// Define the array to store the positions of the system.
double positions[N];

// Define the array to store the velocities of the system.
double velocities[N];

// Define the main function.
int main() {
  // Initialize the system.
  positions[0] = position;
  velocities[0] = velocity;

  // Run the simulation.
  for (int i = 1; i < n; i++) {
    // Calculate the acceleration of the system.
    double acceleration = -g * mass / pow(positions[i - 1], 2);

    // Update the velocity of the system.
    velocities[i] = velocities[i - 1] + acceleration * dt;

    // Update the position of the system.
    positions[i] = positions[i - 1] + velocities[i] * dt;
  }

  // Print the results of the simulation.
  for (int i = 0; i < n; i++) {
    printf("%f %f\n", positions[i], velocities[i]);
  }

  return 0;
}