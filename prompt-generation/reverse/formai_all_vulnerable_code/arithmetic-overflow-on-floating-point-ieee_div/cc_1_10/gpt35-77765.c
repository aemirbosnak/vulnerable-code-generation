//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Structure to store the position and velocity of an object
typedef struct {
  double x;
  double y;
  double z;
} Vector;

// Structure to store the mass and state (i.e., position and velocity) of an object
typedef struct {
  double mass;
  Vector state[2]; // Two state vectors for current and next time step
} Body;

// Function to calculate the gravitational force between two bodies
Vector force(Body b1, Body b2) {
  Vector r = {b2.state[0].x - b1.state[0].x, b2.state[0].y - b1.state[0].y, b2.state[0].z - b1.state[0].z};
  double dist = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
  double f = G * b1.mass * b2.mass / (dist*dist);
  Vector f_vec = {f * r.x/dist, f * r.y/dist, f * r.z/dist};
  return f_vec;
}

int main() {
  // Set up the solar system
  Body sun = {1.9885e30, {{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}}}; // Mass of sun and initial state at rest
  Body earth = {5.97e24, {{{147.1e9, 0.0, 0.0}, {0.0, 30.29e3, 0.0}}, {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}}}; // Mass of earth and initial state
  Body moon = {7.35e22, {{{147.1e9, 0.0, 0.0}, {0.0, 30.336e3, 0.0}}, {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}}}; // Mass of moon and initial state
  
  // Simulation parameters
  double dt = 3600.0; // Time step in seconds
  double t_max = 365.25*24*60*60; // Simulation time in seconds
  int n = (int)(t_max/dt); // Number of time steps
  
  // Simulation loop
  for (int i = 0; i < n; i++) {
    // Calculate forces on earth and moon
    Vector f_earth = {0.0, 0.0, 0.0};
    Vector f_moon = {0.0, 0.0, 0.0};
    f_earth = force(sun, earth);
    f_moon = force(sun, moon);
    f_moon.x += force(earth, moon).x;
    f_moon.y += force(earth, moon).y;
    f_moon.z += force(earth, moon).z;
    
    // Update earth and moon states using Verlet integration
    for (int j = 0; j < 3; j++) {
      double a_earth = f_earth.x/earth.mass;
      double a_moon = f_moon.x/moon.mass;
      earth.state[1].x = 2*earth.state[0].x - earth.state[0].x + a_earth*dt*dt;
      moon.state[1].x = 2*moon.state[0].x - moon.state[0].x + a_moon*dt*dt;
      
      a_earth = f_earth.y/earth.mass;
      a_moon = f_moon.y/moon.mass;
      earth.state[1].y = 2*earth.state[0].y - earth.state[0].y + a_earth*dt*dt;
      moon.state[1].y = 2*moon.state[0].y - moon.state[0].y + a_moon*dt*dt;
      
      a_earth = f_earth.z/earth.mass;
      a_moon = f_moon.z/moon.mass;
      earth.state[1].z = 2*earth.state[0].z - earth.state[0].z + a_earth*dt*dt;
      moon.state[1].z = 2*moon.state[0].z - moon.state[0].z + a_moon*dt*dt;

      earth.state[0] = earth.state[1];
      moon.state[0] = moon.state[1];
    }
    
    // Print current positions of earth and moon
    printf("Time: %f s\n", (i+1)*dt);
    printf("Earth: (%f, %f, %f) m\n", earth.state[0].x, earth.state[0].y, earth.state[0].z);
    printf("Moon: (%f, %f, %f) m\n", moon.state[0].x, moon.state[0].y, moon.state[0].z);
  }

  return 0;
}