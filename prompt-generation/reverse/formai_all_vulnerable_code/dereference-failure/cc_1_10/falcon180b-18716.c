//Falcon-180B DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DEPTH 100
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int x, y, z;
} Vector;

typedef struct {
    Vector position;
    Vector direction;
    int age;
} Particle;

void init_particle(Particle *particle) {
    particle->position.x = rand() % MAX_WIDTH;
    particle->position.y = rand() % MAX_HEIGHT;
    particle->position.z = rand() % MAX_DEPTH;
    particle->direction.x = (rand() % 2)? 1 : -1;
    particle->direction.y = (rand() % 2)? 1 : -1;
    particle->direction.z = (rand() % 2)? 1 : -1;
    particle->age = 0;
}

void update_particle(Particle *particle) {
    particle->age++;
    if (particle->age >= 100) {
        init_particle(particle);
    } else {
        particle->position.x += particle->direction.x;
        particle->position.y += particle->direction.y;
        particle->position.z += particle->direction.z;
    }
}

void draw_particle(Particle particle) {
    int x = particle.position.x;
    int y = particle.position.y;
    int z = particle.position.z;
    printf("*");
}

void draw_scene(int width, int height, int depth, Particle *particles, int num_particles) {
    for (int i = 0; i < num_particles; i++) {
        Particle particle = particles[i];
        if (particle.position.z == depth) {
            draw_particle(particle);
        }
    }
}

int main() {
    srand(time(NULL));

    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int depth = MAX_DEPTH;

    Particle *particles = malloc(sizeof(Particle) * 1000);
    for (int i = 0; i < 1000; i++) {
        init_particle(&particles[i]);
    }

    while (1) {
        system("clear");

        for (int i = 0; i < 1000; i++) {
            update_particle(&particles[i]);
        }

        draw_scene(width, height, depth, particles, 1000);

        usleep(100000);
    }

    return 0;
}