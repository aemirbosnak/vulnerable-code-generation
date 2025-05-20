//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.67408e-11

// Define the masses of the planets in Earth masses
#define M_EARTH 1.0
#define M_MARS 0.107
#define M_JUPITER 317.8
#define M_SATURN 95.2
#define M_URANUS 14.5
#define M_NEPTUNE 17.1
#define M_PLUTO 0.002

// Define the semi-major axis of the planets in AU
#define A_EARTH 1.0
#define A_MARS 1.524
#define A_JUPITER 5.204
#define A_SATURN 9.539
#define A_URANUS 19.18
#define A_NEPTUNE 30.06
#define A_PLUTO 39.48

// Define the eccentricities of the planets
#define E_EARTH 0.0167
#define E_MARS 0.0934
#define E_JUPITER 0.0484
#define E_SATURN 0.0565
#define E_URANUS 0.0472
#define E_NEPTUNE 0.0086
#define E_PLUTO 0.2488

// Define the inclinations of the planets in degrees
#define I_EARTH 0.0
#define I_MARS 1.85
#define I_JUPITER 1.31
#define I_SATURN 2.48
#define I_URANUS 0.77
#define I_NEPTUNE 1.77
#define I_PLUTO 17.15

// Define the time step in days
#define DT 10.0

// Define the number of time steps
#define NT 10000

// Define the output file name
#define OUTFILE "solar_system.txt"

// Define the planet struct
typedef struct planet {
  double m; // mass in Earth masses
  double a; // semi-major axis in AU
  double e; // eccentricity
  double i; // inclination in degrees
  double x; // position in AU
  double y; // position in AU
  double z; // position in AU
  double vx; // velocity in AU/day
  double vy; // velocity in AU/day
  double vz; // velocity in AU/day
} planet;

// Initialize the planets
planet planets[] = {
  {M_EARTH, A_EARTH, E_EARTH, I_EARTH, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {M_MARS, A_MARS, E_MARS, I_MARS, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {M_JUPITER, A_JUPITER, E_JUPITER, I_JUPITER, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {M_SATURN, A_SATURN, E_SATURN, I_SATURN, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {M_URANUS, A_URANUS, E_URANUS, I_URANUS, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {M_NEPTUNE, A_NEPTUNE, E_NEPTUNE, I_NEPTUNE, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {M_PLUTO, A_PLUTO, E_PLUTO, I_PLUTO, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

// Calculate the gravitational force between two planets
void calc_force(planet *p1, planet *p2) {
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx*dx + dy*dy + dz*dz);
  double f = G * p1->m * p2->m / (r*r);
  p1->vx += f * dx / r;
  p1->vy += f * dy / r;
  p1->vz += f * dz / r;
  p2->vx -= f * dx / r;
  p2->vy -= f * dy / r;
  p2->vz -= f * dz / r;
}

// Update the positions and velocities of the planets
void update_planets() {
  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < 7; j++) {
      calc_force(&planets[i], &planets[j]);
    }
  }
  for (int i = 0; i < 7; i++) {
    planets[i].x += planets[i].vx * DT;
    planets[i].y += planets[i].vy * DT;
    planets[i].z += planets[i].vz * DT;
  }
}

// Write the positions of the planets to a file
void write_planets() {
  FILE *fp = fopen(OUTFILE, "w");
  for (int i = 0; i < 7; i++) {
    fprintf(fp, "%f %f %f\n", planets[i].x, planets[i].y, planets[i].z);
  }
  fclose(fp);
}

// Main function
int main() {
  // Update the planets for NT time steps
  for (int i = 0; i < NT; i++) {
    update_planets();
  }

  // Write the positions of the planets to a file
  write_planets();

  return 0;
}