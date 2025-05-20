//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x, y, z;
} vector3d;

typedef struct {
  double mass;
  vector3d position;
  vector3d velocity;
} celestial_body;

#define NUM_BODIES 9

celestial_body bodies[NUM_BODIES] = {
  {1.989e30, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}},  // Sun
  {5.972e24, {0.0, 0.0, 0.0}, {30000.0, 0.0, 0.0}},  // Mercury
  {4.869e24, {0.0, 0.0, 0.0}, {24000.0, 0.0, 0.0}},  // Venus
  {5.974e24, {0.0, 0.0, 0.0}, {23000.0, 0.0, 0.0}},  // Earth
  {1.899e27, {0.0, 0.0, 0.0}, {20000.0, 0.0, 0.0}},  // Mars
  {5.685e26, {0.0, 0.0, 0.0}, {18000.0, 0.0, 0.0}},  // Jupiter
  {8.683e25, {0.0, 0.0, 0.0}, {16000.0, 0.0, 0.0}},  // Saturn
  {1.024e26, {0.0, 0.0, 0.0}, {15000.0, 0.0, 0.0}},  // Uranus
  {1.274e26, {0.0, 0.0, 0.0}, {14000.0, 0.0, 0.0}}   // Neptune
};

double gravitational_constant = 6.674e-11;

void calculate_forces() {
  for (int i = 0; i < NUM_BODIES; i++) {
    for (int j = i + 1; j < NUM_BODIES; j++) {
      vector3d r = {bodies[j].position.x - bodies[i].position.x,
                    bodies[j].position.y - bodies[i].position.y,
                    bodies[j].position.z - bodies[i].position.z};

      double distance = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
      double force = gravitational_constant * bodies[i].mass * bodies[j].mass / (distance * distance);

      vector3d unit_vector = {r.x / distance, r.y / distance, r.z / distance};
      vector3d force_vector = {force * unit_vector.x, force * unit_vector.y, force * unit_vector.z};

      bodies[i].velocity.x += force_vector.x / bodies[i].mass;
      bodies[i].velocity.y += force_vector.y / bodies[i].mass;
      bodies[i].velocity.z += force_vector.z / bodies[i].mass;

      bodies[j].velocity.x -= force_vector.x / bodies[j].mass;
      bodies[j].velocity.y -= force_vector.y / bodies[j].mass;
      bodies[j].velocity.z -= force_vector.z / bodies[j].mass;
    }
  }
}

void update_positions() {
  for (int i = 0; i < NUM_BODIES; i++) {
    bodies[i].position.x += bodies[i].velocity.x;
    bodies[i].position.y += bodies[i].velocity.y;
    bodies[i].position.z += bodies[i].velocity.z;
  }
}

int main() {
  int i;

  for (i = 0; i < 10000; i++) {
    calculate_forces();
    update_positions();

    printf("Time step: %d\n", i);
    for (int j = 0; j < NUM_BODIES; j++) {
      printf("Body %d: (%f, %f, %f)\n", j, bodies[j].position.x, bodies[j].position.y, bodies[j].position.z);
    }
    printf("\n");
  }

  return 0;
}