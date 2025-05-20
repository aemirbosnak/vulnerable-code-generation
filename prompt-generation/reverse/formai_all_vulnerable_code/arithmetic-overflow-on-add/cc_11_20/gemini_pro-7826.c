//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RND() ((double)rand() / (RAND_MAX + 1))

typedef struct {
    double x, y;
} vector;

typedef struct {
    vector pos;
    vector vel;
} particle;

int main() {
    srand(time(NULL));

    int n = 1000;
    particle *particles = malloc(n * sizeof(particle));

    for (int i = 0; i < n; i++) {
        particles[i].pos.x = RND() * 1000.0;
        particles[i].pos.y = RND() * 1000.0;
        particles[i].vel.x = 0.0;
        particles[i].vel.y = 0.0;
    }

    int t = 0;
    while (1) {
        for (int i = 0; i < n; i++) {
            particles[i].pos.x += particles[i].vel.x * 0.1;
            particles[i].pos.y += particles[i].vel.y * 0.1;

            if (particles[i].pos.x < 0.0 || particles[i].pos.x > 1000.0) {
                particles[i].vel.x = -particles[i].vel.x;
            }

            if (particles[i].pos.y < 0.0 || particles[i].pos.y > 1000.0) {
                particles[i].vel.y = -particles[i].vel.y;
            }

            for (int j = i + 1; j < n; j++) {
                vector diff = { particles[i].pos.x - particles[j].pos.x,
                                particles[i].pos.y - particles[j].pos.y };
                double dist = sqrt(diff.x * diff.x + diff.y * diff.y);

                if (dist < 10.0) {
                    diff.x /= dist;
                    diff.y /= dist;

                    double force = 0.1 / (dist * dist);
                    particles[i].vel.x += force * diff.x;
                    particles[i].vel.y += force * diff.y;

                    particles[j].vel.x -= force * diff.x;
                    particles[j].vel.y -= force * diff.y;
                }
            }
        }

        printf("Time: %d\n", t);

        for (int i = 0; i < n; i++) {
            printf("Particle: %d\n", i);
            printf("Position: (%f, %f)\n", particles[i].pos.x, particles[i].pos.y);
            printf("Velocity: (%f, %f)\n", particles[i].vel.x, particles[i].vel.y);
            printf("\n");
        }

        t++;
    }

    free(particles);

    return 0;
}