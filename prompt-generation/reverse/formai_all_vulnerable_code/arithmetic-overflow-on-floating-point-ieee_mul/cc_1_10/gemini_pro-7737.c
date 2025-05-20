//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11   // Gravitational constant
#define M_EARTH 5.972e24    // Mass of Earth in kilograms
#define M_MOON 7.348e22     // Mass of Moon in kilograms
#define R_EARTH 6.371e6     // Radius of Earth in meters
#define R_MOON 1.737e6      // Radius of Moon in meters

typedef struct {
  double m;          // Mass in kilograms
  double r;          // Radius from the center of the Earth in meters
  double x;          // X-coordinate in meters
  double y;          // Y-coordinate in meters
  double vx;         // X-component of velocity in meters per second
  double vy;         // Y-component of velocity in meters per second
  double ax;         // X-component of acceleration in meters per second squared
  double ay;         // Y-component of acceleration in meters per second squared
} Body;

int main() {

  Body earth, moon;

  // Initialize the Earth and Moon
  earth.m = M_EARTH;
  earth.r = R_EARTH;
  earth.x = 0;
  earth.y = 0;
  earth.vx = 0;
  earth.vy = 0;
  earth.ax = 0;
  earth.ay = 0;

  moon.m = M_MOON;
  moon.r = R_MOON;
  moon.x = 3.844e8;
  moon.y = 0;
  moon.vx = 0;
  moon.vy = 1200;
  moon.ax = 0;
  moon.ay = 0;

  // Simulation parameters
  double dt = 1;              // Time step in seconds
  const double t_max = 10000;   // Maximum simulation time in seconds

  // Time loop
  for (double t = 0; t < t_max; t += dt) {
    // Calculate the force between the Earth and the Moon
    double force_x = G * earth.m * moon.m * (earth.x - moon.x) / pow(earth.r + moon.r, 3);
    double force_y = G * earth.m * moon.m * (earth.y - moon.y) / pow(earth.r + moon.r, 3);

    // Calculate the acceleration of the Earth and the Moon
    earth.ax = -force_x / earth.m;
    earth.ay = -force_y / earth.m;

    moon.ax = force_x / moon.m;
    moon.ay = force_y / moon.m;

    // Update the velocity and position of the Earth and the Moon
    earth.vx += earth.ax * dt;
    earth.vy += earth.ay * dt;

    earth.x += earth.vx * dt;
    earth.y += earth.vy * dt;

    moon.vx += moon.ax * dt;
    moon.vy += moon.ay * dt;

    moon.x += moon.vx * dt;
    moon.y += moon.vy * dt;

    // Print the position of the Moon
    printf("Time = %f s, Moon position = (%.2f, %.2f) km\n", t, moon.x / 1000, moon.y / 1000);
  }

  return 0;
}