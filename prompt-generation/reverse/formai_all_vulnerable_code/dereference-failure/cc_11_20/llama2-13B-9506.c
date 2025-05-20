//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.8
#define WORLD_WIDTH 1000
#define WORLD_HEIGHT 1000

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
} Particle;

int main() {
    Particle** particles = malloc(1000 * sizeof(Particle));
    for (int i = 0; i < 1000; i++) {
        particles[i] = malloc(sizeof(Particle));
        particles[i]->x = (float)rand() / RAND_MAX * WORLD_WIDTH;
        particles[i]->y = (float)rand() / RAND_MAX * WORLD_HEIGHT;
        particles[i]->vx = (float)rand() / RAND_MAX * 2 - 1;
        particles[i]->vy = (float)rand() / RAND_MAX * 2 - 1;
    }

    while (1) {
        for (int i = 0; i < 1000; i++) {
            particles[i]->x += particles[i]->vx;
            particles[i]->y += particles[i]->vy;
            if (particles[i]->x < 0 || particles[i]->x > WORLD_WIDTH ||
                    particles[i]->y < 0 || particles[i]->y > WORLD_HEIGHT) {
                particles[i]->vx = (float)rand() / RAND_MAX * 2 - 1;
                particles[i]->vy = (float)rand() / RAND_MAX * 2 - 1;
            }
        }

        for (int i = 0; i < 1000; i++) {
            for (int j = i + 1; j < 1000; j++) {
                if (particles[i]->x == particles[j]->x && particles[i]->y == particles[j]->y) {
                    particles[i]->vx += particles[j]->vx;
                    particles[i]->vy += particles[j]->vy;
                }
            }
        }

        for (int i = 0; i < 1000; i++) {
            printf("Particle %d: (%f, %f) vx: %f vy: %f\n", i, particles[i]->x, particles[i]->y, particles[i]->vx, particles[i]->vy);
        }

        sleep(0.01);
    }

    return 0;
}