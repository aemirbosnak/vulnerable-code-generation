//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11     // gravitational constant
#define TIMESTEP 1        // time step for simulation
#define NUM_PLANETS 3     // number of planets in the simulation

struct Vector {
  double x;
  double y;
};

struct Planet {
  double mass;
  double radius;
  struct Vector position;
  struct Vector velocity;
  struct Vector acceleration;
};

struct Simulation {
  struct Planet planets[NUM_PLANETS];
};

void calculate_acceleration(struct Planet *planet1, struct Planet *planet2, struct Vector *acceleration) {
  double distance = sqrt(pow(planet2->position.x - planet1->position.x, 2) + pow(planet2->position.y - planet1->position.y, 2));
  double force = G * planet1->mass * planet2->mass / pow(distance, 2);
  double acceleration_magnitude = force / planet1->mass;
  acceleration->x += acceleration_magnitude * (planet2->position.x - planet1->position.x) / distance;
  acceleration->y += acceleration_magnitude * (planet2->position.y - planet1->position.y) / distance;
}

void calculate_simulations(struct Simulation *simulation) {
  for (int i = 0; i < NUM_PLANETS; i++) {
    struct Vector acceleration = { 0, 0 };
    for (int j = 0; j < NUM_PLANETS; j++) {
      if (i == j) continue;
      calculate_acceleration(&simulation->planets[i], &simulation->planets[j], &acceleration);
    }
    simulation->planets[i].acceleration = acceleration;
  }
}

void update_positions(struct Simulation *simulation) {
  for (int i = 0; i < NUM_PLANETS; i++) {
    simulation->planets[i].velocity.x += simulation->planets[i].acceleration.x * TIMESTEP;
    simulation->planets[i].velocity.y += simulation->planets[i].acceleration.y * TIMESTEP;
    simulation->planets[i].position.x += simulation->planets[i].velocity.x * TIMESTEP;
    simulation->planets[i].position.y += simulation->planets[i].velocity.y * TIMESTEP;
  }
}

int main() {
  struct Simulation simulation = {
    .planets = {
      {
        .mass = 5.972e24,
        .radius = 6371000,
        .position = { 0, 0 },
        .velocity = { 0, 0 },
        .acceleration = { 0, 0 }
      },
      {
        .mass = 3.285e23,
        .radius = 1737100,
        .position = { 0, 384400000 },
        .velocity = { 1022, 0 },
        .acceleration = { 0, 0 }
      },
      {
        .mass = 6.39e23,
        .radius = 3390000,
        .position = { 0, -227920000 },
        .velocity = { -2410, 0 },
        .acceleration = { 0, 0 }
      },
    }
  };

  for (int i = 0; i < 5000; i++) {
    calculate_simulations(&simulation);
    update_positions(&simulation);
    printf("Earth: %f,%f\n", simulation.planets[0].position.x, simulation.planets[0].position.y);
    printf("Moon: %f,%f\n", simulation.planets[1].position.x, simulation.planets[1].position.y);
    printf("Mars: %f,%f\n", simulation.planets[2].position.x, simulation.planets[2].position.y);
  }

  return 0;
}