//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// A celestial body with mass, position and velocity
typedef struct Planet{
  double mass;
  double position[3];
  double velocity[3];
} Planet;
// Function to calculate the distance between two planets
double planetDistance(Planet planet1, Planet planet2){
  double dx = planet1.position[0] - planet2.position[0];
  double dy = planet1.position[1] - planet2.position[1];
  double dz = planet1.position[2] - planet2.position[2];
  return sqrt(dx*dx + dy*dy + dz*dz);
}
// Function to calculate the gravitational force between two planets
double gravityForce(Planet planet1, Planet planet2){
  double G = 6.67408e-11; // Gravitational constant
  double distance = planetDistance(planet1, planet2);
  return G * planet1.mass * planet2.mass / pow(distance, 2);
}
// Function to update the velocity of a planet based on the gravitational force of other planets
void updateVelocity(Planet *planet, Planet *others, int numPlanets){
  int i;
  double Fx=0, Fy=0, Fz=0;
  for (i = 0; i < numPlanets; i++){
    if(planet == &others[i]){
      continue;
    }
    double force = gravityForce(*planet, others[i]);
    double dx = planet->position[0] - others[i].position[0];
    double dy = planet->position[1] - others[i].position[1];
    double dz = planet->position[2] - others[i].position[2];
    double distance = planetDistance(*planet, others[i]);
    Fx += force*dx/distance;
    Fy += force*dy/distance;
    Fz += force*dz/distance;
  }
  planet->velocity[0] += Fx / planet->mass;
  planet->velocity[1] += Fy / planet->mass;
  planet->velocity[2] += Fz / planet->mass;
}
// Function to update the position of a planet based on its velocity
void updatePosition(Planet *planet){
  planet->position[0] += planet->velocity[0];
  planet->position[1] += planet->velocity[1];
  planet->position[2] += planet->velocity[2];
}
// Main function
int main(){
  // Create a system of planets
  int numPlanets = 3;
  Planet planets[numPlanets];
  // Set the mass, position and velocity of each planet
  planets[0].mass = 1e24; // Sun
  planets[0].position[0] = 0;
  planets[0].position[1] = 0;
  planets[0].position[2] = 0;
  planets[0].velocity[0] = 0;
  planets[0].velocity[1] = 0;
  planets[0].velocity[2] = 0;
  planets[1].mass = 5.972e24; // Earth
  planets[1].position[0] = 1.5e11;
  planets[1].position[1] = 0;
  planets[1].position[2] = 0;
  planets[1].velocity[0] = 0;
  planets[1].velocity[1] = 30000;
  planets[1].velocity[2] = 0;
  planets[2].mass = 7.348e22; // Mars
  planets[2].position[0] = 2.4e11;
  planets[2].position[1] = 0;
  planets[2].position[2] = 0;
  planets[2].velocity[0] = 0;
  planets[2].velocity[1] = 24000;
  planets[2].velocity[2] = 0;
  // Simulate the motion of the planets for 1000 time steps
  int i, j;
  double dt = 3600; // 1 hour in seconds
  for (i = 0; i < 1000; i++){
    // Update the velocity of each planet based on the gravitational force of other planets
    for (j = 0; j < numPlanets; j++){
      updateVelocity(&planets[j], planets, numPlanets);
    }
    // Update the position of each planet based on its velocity
    for (j = 0; j < numPlanets; j++){
      updatePosition(&planets[j]);
    }
    // Print the positions of the planets
    printf("Time: %d\n", i*dt);
    for (j = 0; j < numPlanets; j++){
      printf("Planet %d: (%.2e, %.2e, %.2e)\n", j+1, planets[j].position[0], planets[j].position[1], planets[j].position[2]);
    }
    printf("\n");
  }
  return 0;
}