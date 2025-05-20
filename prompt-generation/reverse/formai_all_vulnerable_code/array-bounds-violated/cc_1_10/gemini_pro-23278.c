//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the masses of the planets in Earth masses
#define SUN_MASS 332946
#define MERCURY_MASS 0.0553
#define VENUS_MASS 0.815
#define EARTH_MASS 1.0
#define MARS_MASS 0.107
#define JUPITER_MASS 317.8
#define SATURN_MASS 95.2
#define URANUS_MASS 14.54
#define NEPTUNE_MASS 17.15

// Define the gravitational constant
#define G 6.674e-11

// Define the time step
#define DT 0.001

// Define the number of planets
#define NUM_PLANETS 8

// Define the planet positions and velocities
double positions[NUM_PLANETS][3];
double velocities[NUM_PLANETS][3];

// Initialize the planet positions and velocities
void initialize_planets() {
  // Sun
  positions[0][0] = 0;
  positions[0][1] = 0;
  positions[0][2] = 0;
  velocities[0][0] = 0;
  velocities[0][1] = 0;
  velocities[0][2] = 0;

  // Mercury
  positions[1][0] = 0.387;
  positions[1][1] = 0;
  positions[1][2] = 0;
  velocities[1][0] = 0;
  velocities[1][1] = 12.44;
  velocities[1][2] = 0;

  // Venus
  positions[2][0] = 0.723;
  positions[2][1] = 0;
  positions[2][2] = 0;
  velocities[2][0] = 0;
  velocities[2][1] = 7.28;
  velocities[2][2] = 0;

  // Earth
  positions[3][0] = 1.0;
  positions[3][1] = 0;
  positions[3][2] = 0;
  velocities[3][0] = 0;
  velocities[3][1] = 6.0;
  velocities[3][2] = 0;

  // Mars
  positions[4][0] = 1.524;
  positions[4][1] = 0;
  positions[4][2] = 0;
  velocities[4][0] = 0;
  velocities[4][1] = 5.0;
  velocities[4][2] = 0;

  // Jupiter
  positions[5][0] = 5.2;
  positions[5][1] = 0;
  positions[5][2] = 0;
  velocities[5][0] = 0;
  velocities[5][1] = 2.0;
  velocities[5][2] = 0;

  // Saturn
  positions[6][0] = 9.5;
  positions[6][1] = 0;
  positions[6][2] = 0;
  velocities[6][0] = 0;
  velocities[6][1] = 1.5;
  velocities[6][2] = 0;

  // Uranus
  positions[7][0] = 19.2;
  positions[7][1] = 0;
  positions[7][2] = 0;
  velocities[7][0] = 0;
  velocities[7][1] = 1.0;
  velocities[7][2] = 0;

  // Neptune
  positions[8][0] = 30.1;
  positions[8][1] = 0;
  positions[8][2] = 0;
  velocities[8][0] = 0;
  velocities[8][1] = 0.8;
  velocities[8][2] = 0;
}

// Calculate the gravitational force between two planets
void calculate_force(int i, int j) {
  // Calculate the distance between the planets
  double dx = positions[i][0] - positions[j][0];
  double dy = positions[i][1] - positions[j][1];
  double dz = positions[i][2] - positions[j][2];
  double distance = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the force
  double force = G * positions[i][3] * positions[j][3] / (distance * distance);

  // Calculate the direction of the force
  double fx = force * dx / distance;
  double fy = force * dy / distance;
  double fz = force * dz / distance;

  // Apply the force to the planets
  velocities[i][0] += fx / positions[i][3] * DT;
  velocities[i][1] += fy / positions[i][3] * DT;
  velocities[i][2] += fz / positions[i][3] * DT;
  velocities[j][0] -= fx / positions[j][3] * DT;
  velocities[j][1] -= fy / positions[j][3] * DT;
  velocities[j][2] -= fz / positions[j][3] * DT;
}

// Update the planet positions and velocities
void update_planets() {
  // Update the positions
  for (int i = 0; i < NUM_PLANETS; i++) {
    positions[i][0] += velocities[i][0] * DT;
    positions[i][1] += velocities[i][1] * DT;
    positions[i][2] += velocities[i][2] * DT;
  }

  // Update the velocities
  for (int i = 0; i < NUM_PLANETS; i++) {
    for (int j = i + 1; j < NUM_PLANETS; j++) {
      //Only calculate for j > i
      if(j > i){
        calculate_force(i, j);
      }
    }
  }
}

// Print the planet positions
void print_planets() {
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("Planet %d: (%f, %f, %f)\n", i, positions[i][0], positions[i][1], positions[i][2]);
  }
}

int main() {
  // Initialize the planets
  initialize_planets();

  // Simulate the solar system for 100000 time steps
  for (int i = 0; i < 100000; i++) {
    // Update the planets
    update_planets();

    // Print the planet positions
    print_planets();
  }

  return 0;
}