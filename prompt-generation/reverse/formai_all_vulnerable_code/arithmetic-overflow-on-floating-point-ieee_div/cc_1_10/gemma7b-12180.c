//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational Constant

// Define the masses of the planets
#define M_EARTH 5.972e24 // Mass of the Earth (kg)
#define M_MOON 7.348e22 // Mass of the Moon (kg)
#define M_MARS 0.643e24 // Mass of Mars (kg)
#define M_VENUS 0.815e24 // Mass of Venus (kg)

// Define the positions and velocities of the planets
#define X_EARTH 0 // Position of Earth (m)
#define Y_EARTH 0 // Position of Earth (m)
#define V_EARTH 0 // Velocity of Earth (m/s)
#define Y_EARTH 0 // Velocity of Earth (m/s)

#define X_MOON 3.844e8 // Position of Moon (m)
#define Y_MOON 0 // Position of Moon (m)
#define V_MOON 0 // Velocity of Moon (m/s)
#define Y_MOON 0 // Velocity of Moon (m/s)

#define X_MARS 2.48e8 // Position of Mars (m)
#define Y_MARS 0 // Position of Mars (m)
#define V_MARS 0 // Velocity of Mars (m/s)
#define Y_MARS 0 // Velocity of Mars (m/s)

#define X_VENUS 0 // Position of Venus (m)
#define Y_VENUS 0 // Position of Venus (m)
#define V_VENUS 0 // Velocity of Venus (m/s)
#define Y_VENUS 0 // Velocity of Venus (m/s)

// Calculate the acceleration due to gravity
double acceleration(double mass, double x, double y) {
  double distance = sqrt(x*x + y*y);
  double acceleration_magnitude = G * mass / distance * distance;
  return acceleration_magnitude;
}

int main() {
  // Calculate the acceleration of each planet due to gravity
  double acceleration_earth = acceleration(M_EARTH, X_MOON - X_EARTH, Y_MOON - Y_EARTH);
  double acceleration_moon = acceleration(M_MOON, X_EARTH - X_MOON, Y_EARTH - Y_MOON);
  double acceleration_mars = acceleration(M_MARS, X_EARTH - X_MARS, Y_EARTH - Y_MARS);
  double acceleration_venus = acceleration(M_VENUS, X_EARTH - X_VENUS, Y_EARTH - Y_VENUS);

  // Print the acceleration of each planet
  printf("The acceleration of the Earth due to gravity is: %.2e m/s^2\n", acceleration_earth);
  printf("The acceleration of the Moon due to gravity is: %.2e m/s^2\n", acceleration_moon);
  printf("The acceleration of Mars due to gravity is: %.2e m/s^2\n", acceleration_mars);
  printf("The acceleration of Venus due to gravity is: %.2e m/s^2\n", acceleration_venus);

  return 0;
}