//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.674e-11 // N * m^2 / kg^2
#define EARTH_MASS 5.972e24 // kg
#define EARTH_RADIUS 6.371e6 // m
#define SUN_MASS 1.989e30 // kg

typedef struct {
  double x, y, z; // in m
} vector;

typedef struct {
  double mass; // in kg
  vector position; // in m
  vector velocity; // in m/s
} celestial_body;

vector normalize(vector v) {
  double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

  if (length != 0) {
    v.x /= length;
    v.y /= length;
    v.z /= length;
  }

  return v;
}

vector add(vector a, vector b) {
  vector v;

  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;

  return v;
}

vector subtract(vector a, vector b) {
  vector v;

  v.x = a.x - b.x;
  v.y = a.y - b.y;
  v.z = a.z - b.z;

  return v;
}

vector multiply(vector v, double scalar) {
  v.x *= scalar;
  v.y *= scalar;
  v.z *= scalar;

  return v;
}

double distance(vector a, vector b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dz = a.z - b.z;

  return sqrt(dx * dx + dy * dy + dz * dz);
}

void update_position(celestial_body *body, double time_step) {
  body->position = add(body->position, multiply(body->velocity, time_step));
}

void update_velocity(celestial_body *body, vector acceleration, double time_step) {
  body->velocity = add(body->velocity, multiply(acceleration, time_step));
}

vector gravitational_force(celestial_body a, celestial_body b) {
  vector direction = normalize(subtract(b.position, a.position));
  double magnitude = GRAVITY_CONSTANT * a.mass * b.mass / pow(distance(a.position, b.position), 2);
  vector force = multiply(direction, magnitude);

  return force;
}

int main() {
  celestial_body sun = {
    .mass = SUN_MASS,
    .position = { .x = 0, .y = 0, .z = 0 },
    .velocity = { .x = 0, .y = 0, .z = 0 }
  };

  celestial_body earth = {
    .mass = EARTH_MASS,
    .position = { .x = 0, .y = EARTH_RADIUS + 4e7, .z = 0 },
    .velocity = { .x = 3e4, .y = 0, .z = 0 }
  };

  double time_step = 60; // in seconds
  double sim_duration = 365 * 24 * 3600; // in seconds

  for (double t = 0; t < sim_duration; t += time_step) {
    vector force = gravitational_force(earth, sun);
    vector acceleration = multiply(force, 1 / earth.mass);

    update_velocity(&earth, acceleration, time_step);
    update_position(&earth, time_step);

    printf("t = %f, x = %f, y = %f, z = %f\n", t, earth.position.x, earth.position.y, earth.position.z);
  }

  return 0;
}