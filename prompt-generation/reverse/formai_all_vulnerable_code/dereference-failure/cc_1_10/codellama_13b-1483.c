//Code Llama-13B DATASET v1.0 Category: Physics simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
  double x, y, z;
} Vector;

typedef struct {
  double mass;
  Vector position;
  Vector velocity;
  Vector acceleration;
} Particle;

void initParticle(Particle *p, double mass, double x, double y, double z) {
  p->mass = mass;
  p->position.x = x;
  p->position.y = y;
  p->position.z = z;
  p->velocity.x = 0.0;
  p->velocity.y = 0.0;
  p->velocity.z = 0.0;
  p->acceleration.x = 0.0;
  p->acceleration.y = 0.0;
  p->acceleration.z = 0.0;
}

void updateParticle(Particle *p, double dt) {
  p->velocity.x += p->acceleration.x * dt;
  p->velocity.y += p->acceleration.y * dt;
  p->velocity.z += p->acceleration.z * dt;
  p->position.x += p->velocity.x * dt;
  p->position.y += p->velocity.y * dt;
  p->position.z += p->velocity.z * dt;
}

void updateParticles(Particle *particles, int numParticles, double dt) {
  for (int i = 0; i < numParticles; i++) {
    updateParticle(&particles[i], dt);
  }
}

int main() {
  int numParticles = 10;
  Particle *particles = (Particle *)malloc(sizeof(Particle) * numParticles);
  for (int i = 0; i < numParticles; i++) {
    initParticle(&particles[i], 1.0, 0.0, 0.0, 0.0);
  }

  double dt = 0.01;
  for (int i = 0; i < 1000; i++) {
    updateParticles(particles, numParticles, dt);
    for (int j = 0; j < numParticles; j++) {
      printf("Particle %d: (%.2f, %.2f, %.2f)\n", j, particles[j].position.x, particles[j].position.y, particles[j].position.z);
    }
  }

  return 0;
}