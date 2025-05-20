//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* The gravitational constant. */
#define G 6.67408e-11

/* The mass of the sun in Earth masses. */
#define M_SUN 332946.0

/* The mass of the Earth in Earth masses. */
#define M_EARTH 1.0

/* The time step in seconds. */
#define DT 86400.0

/* The number of planets in the solar system. */
#define N_PLANETS 8

/* The initial positions and velocities of the planets. */
double x[N_PLANETS] = {0.0, 0.0, -1.0, 1.0, 2.0, -2.0, 3.0, -3.0};
double y[N_PLANETS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double z[N_PLANETS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double vx[N_PLANETS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double vy[N_PLANETS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double vz[N_PLANETS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

/* The main function. */
int main(void) {
  /* 
   * Compute the gravitational force on each planet due to the sun.
   */
  for (int i = 0; i < N_PLANETS; i++) {
    double r = sqrt(x[i]*x[i] + y[i]*y[i] + z[i]*z[i]);
    double f = G * M_SUN * M_EARTH / (r*r*r);
    vx[i] -= f * x[i] / r;
    vy[i] -= f * y[i] / r;
    vz[i] -= f * z[i] / r;
  }

  /* 
   * Compute the gravitational force on each planet due to the other planets.
   */
  for (int i = 0; i < N_PLANETS; i++) {
    for (int j = i + 1; j < N_PLANETS; j++) {
      double r = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]));
      double f = G * M_EARTH * M_EARTH / (r*r*r);
      vx[i] -= f * (x[i] - x[j]) / r;
      vy[i] -= f * (y[i] - y[j]) / r;
      vz[i] -= f * (z[i] - z[j]) / r;
      vx[j] += f * (x[i] - x[j]) / r;
      vy[j] += f * (y[i] - y[j]) / r;
      vz[j] += f * (z[i] - z[j]) / r;
    }
  }

   /* 
   * Update the positions and velocities of the planets.
   */
  for (int i = 0; i < N_PLANETS; i++) {
    x[i] += vx[i] * DT;
    y[i] += vy[i] * DT;
    z[i] += vz[i] * DT;
  }

  /* 
   * Print the positions of the planets.
   */
  for (int i = 0; i < N_PLANETS; i++) {
    printf("%f %f %f\n", x[i], y[i], z[i]);
  }

  return 0;
}