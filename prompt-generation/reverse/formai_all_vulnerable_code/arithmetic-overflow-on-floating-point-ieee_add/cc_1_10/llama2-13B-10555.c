//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 100

struct particle {
    float x;
    float y;
    float vx;
    float vy;
};

struct world {
    struct particle particles[WORLD_SIZE];
    int num_particles;
};

void simulate(struct world *world) {
    for (int i = 0; i < WORLD_SIZE; i++) {
        struct particle *particle = &world->particles[i];
        particle->vx += GRAVITY;
        particle->vy += GRAVITY;
        particle->x += particle->vx;
        particle->y += particle->vy;
        if (particle->x < 0 || particle->x >= WORLD_SIZE) {
            particle->vx = -particle->vx;
        }
        if (particle->y < 0 || particle->y >= WORLD_SIZE) {
            particle->vy = -particle->vy;
        }
    }
}

int main() {
    struct world world;
    world.num_particles = 5;
    for (int i = 0; i < world.num_particles; i++) {
        struct particle *particle = &world.particles[i];
        particle->x = rand() % WORLD_SIZE;
        particle->y = rand() % WORLD_SIZE;
        particle->vx = rand() % 2 - 1;
        particle->vy = rand() % 2 - 1;
    }
    simulate(&world);
    for (int i = 0; i < world.num_particles; i++) {
        struct particle *particle = &world.particles[i];
        printf("%.2f,%.2f\n", particle->x, particle->y);
    }
    return 0;
}