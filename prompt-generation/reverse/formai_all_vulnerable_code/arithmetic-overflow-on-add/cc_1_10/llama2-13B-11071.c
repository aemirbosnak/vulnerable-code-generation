//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 100

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
} particle_t;

typedef struct {
    particle_t particles[WORLD_SIZE];
    int num_particles;
} world_t;

void init_world(world_t *world) {
    int i;
    for (i = 0; i < WORLD_SIZE; i++) {
        world->particles[i].x = (float)rand() / RAND_MAX * WORLD_SIZE;
        world->particles[i].y = (float)rand() / RAND_MAX * WORLD_SIZE;
        world->particles[i].vx = (float)rand() / RAND_MAX * 2 - 1;
        world->particles[i].vy = (float)rand() / RAND_MAX * 2 - 1;
        world->num_particles++;
    }
}

void update_world(world_t *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        particle_t *particle = &world->particles[i];
        particle->x += particle->vx;
        particle->y += particle->vy;
        particle->vx += GRAVITY * particle->y;
        particle->vy += GRAVITY * particle->x;
        if (particle->x < 0 || particle->x >= WORLD_SIZE ||
            particle->y < 0 || particle->y >= WORLD_SIZE) {
            particle->vx = (float)rand() / RAND_MAX * 2 - 1;
            particle->vy = (float)rand() / RAND_MAX * 2 - 1;
        }
    }
}

void draw_world(world_t *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        particle_t *particle = &world->particles[i];
        printf("%.2f,%.2f\t%.2f,%.2f\n", particle->x, particle->y, particle->vx, particle->vy);
    }
}

int main() {
    world_t world;
    init_world(&world);
    update_world(&world);
    draw_world(&world);
    return 0;
}