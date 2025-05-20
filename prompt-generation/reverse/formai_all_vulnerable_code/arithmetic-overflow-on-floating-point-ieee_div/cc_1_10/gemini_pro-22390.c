//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the masses of Romeo and Juliet
#define ROMEO_MASS 75.0 // kg
#define JULIET_MASS 50.0 // kg

// Define the gravitational constant
#define G 6.674e-11 // m^3 kg^-1 s^-2

// Define the initial positions and velocities of Romeo and Juliet
#define ROMEO_X0 0.0 // m
#define ROMEO_Y0 0.0 // m
#define ROMEO_VX0 0.0 // m/s
#define ROMEO_VY0 0.0 // m/s
#define JULIET_X0 100.0 // m
#define JULIET_Y0 0.0 // m
#define JULIET_VX0 0.0 // m/s
#define JULIET_VY0 0.0 // m/s

// Define the time step
#define DT 0.01 // s

// Define the number of time steps
#define NUM_STEPS 10000

// Define the arrays to store the positions and velocities of Romeo and Juliet
double romeo_x[NUM_STEPS];
double romeo_y[NUM_STEPS];
double romeo_vx[NUM_STEPS];
double romeo_vy[NUM_STEPS];
double juliet_x[NUM_STEPS];
double juliet_y[NUM_STEPS];
double juliet_vx[NUM_STEPS];
double juliet_vy[NUM_STEPS];

// Define the function to calculate the gravitational force between Romeo and Juliet
double gravitational_force(double m1, double m2, double r) {
  return (G * m1 * m2) / (r * r);
}

// Define the function to update the positions and velocities of Romeo and Juliet
void update_positions_and_velocities(double m1, double m2, double x1, double y1, double vx1, double vy1, double x2, double y2, double vx2, double vy2, double dt) {
  // Calculate the gravitational force between Romeo and Juliet
  double fx = gravitational_force(m1, m2, sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
  double fy = gravitational_force(m1, m2, sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

  // Update the positions of Romeo and Juliet
  x1 += vx1 * dt;
  y1 += vy1 * dt;
  x2 += vx2 * dt;
  y2 += vy2 * dt;

  // Update the velocities of Romeo and Juliet
  vx1 += fx / m1 * dt;
  vy1 += fy / m1 * dt;
  vx2 += fx / m2 * dt;
  vy2 += fy / m2 * dt;
}

int main() {
  // Initialize the positions and velocities of Romeo and Juliet
  romeo_x[0] = ROMEO_X0;
  romeo_y[0] = ROMEO_Y0;
  romeo_vx[0] = ROMEO_VX0;
  romeo_vy[0] = ROMEO_VY0;
  juliet_x[0] = JULIET_X0;
  juliet_y[0] = JULIET_Y0;
  juliet_vx[0] = JULIET_VX0;
  juliet_vy[0] = JULIET_VY0;

  // Update the positions and velocities of Romeo and Juliet for each time step
  for (int i = 1; i < NUM_STEPS; i++) {
    update_positions_and_velocities(ROMEO_MASS, JULIET_MASS, romeo_x[i - 1], romeo_y[i - 1], romeo_vx[i - 1], romeo_vy[i - 1], juliet_x[i - 1], juliet_y[i - 1], juliet_vx[i - 1], juliet_vy[i - 1], DT);
  }

  // Print the final positions of Romeo and Juliet
  printf("Romeo's final position: (%f, %f)\n", romeo_x[NUM_STEPS - 1], romeo_y[NUM_STEPS - 1]);
  printf("Juliet's final position: (%f, %f)\n", juliet_x[NUM_STEPS - 1], juliet_y[NUM_STEPS - 1]);

  return 0;
}