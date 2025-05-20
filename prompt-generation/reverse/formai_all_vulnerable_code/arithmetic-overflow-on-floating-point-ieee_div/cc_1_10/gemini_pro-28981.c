//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass and radius of the Sun
#define M_SUN 1.989e30 // kg
#define R_SUN 6.955e8 // m

// Define the mass and radius of the Earth
#define M_EARTH 5.972e24 // kg
#define R_EARTH 6.371e6 // m

// Define the gravitational constant
#define G 6.674e-11 // m^3 kg^-1 s^-2

// Define the simulation timestep
#define DT 1000 // s

// Define the number of time steps
#define NUM_STEPS 10000

// Define the initial positions and velocities of the Sun and Earth
double pos_sun[3] = {0, 0, 0};
double vel_sun[3] = {0, 0, 0};
double pos_earth[3] = {1.5e11, 0, 0};
double vel_earth[3] = {0, 1000, 0};

// Main function
int main() {
  // Open a file to store the data
  FILE *fp = fopen("solar_system.csv", "w");

  // Write the header row
  fprintf(fp, "Time,X_Sun,Y_Sun,Z_Sun,X_Earth,Y_Earth,Z_Earth\n");

  // Loop over the time steps
  for (int i = 0; i < NUM_STEPS; i++) {
    // Calculate the force between the Sun and Earth
    double f_grav[3];
    f_grav[0] = -G * M_SUN * M_EARTH / pow(pos_earth[0] - pos_sun[0], 3) * (pos_earth[0] - pos_sun[0]);
    f_grav[1] = -G * M_SUN * M_EARTH / pow(pos_earth[1] - pos_sun[1], 3) * (pos_earth[1] - pos_sun[1]);
    f_grav[2] = -G * M_SUN * M_EARTH / pow(pos_earth[2] - pos_sun[2], 3) * (pos_earth[2] - pos_sun[2]);

    // Update the velocities of the Sun and Earth
    vel_sun[0] += f_grav[0] * DT / M_SUN;
    vel_sun[1] += f_grav[1] * DT / M_SUN;
    vel_sun[2] += f_grav[2] * DT / M_SUN;
    vel_earth[0] += f_grav[0] * DT / M_EARTH;
    vel_earth[1] += f_grav[1] * DT / M_EARTH;
    vel_earth[2] += f_grav[2] * DT / M_EARTH;

    // Update the positions of the Sun and Earth
    pos_sun[0] += vel_sun[0] * DT;
    pos_sun[1] += vel_sun[1] * DT;
    pos_sun[2] += vel_sun[2] * DT;
    pos_earth[0] += vel_earth[0] * DT;
    pos_earth[1] += vel_earth[1] * DT;
    pos_earth[2] += vel_earth[2] * DT;

    // Write the data to the file
    fprintf(fp, "%f,%f,%f,%f,%f,%f,%f\n", i * DT, pos_sun[0], pos_sun[1], pos_sun[2], pos_earth[0], pos_earth[1], pos_earth[2]);
  }

  // Close the file
  fclose(fp);

  return 0;
}