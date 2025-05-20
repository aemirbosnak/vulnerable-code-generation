//FormAI DATASET v1.0 Category: Physics simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.674 * pow(10,-11) // gravitational constant
#define dt 1 // time step
#define MAX_TIME 100 // maximum running time

// structure for a single particle
struct Particle {
    double x; // x-coordinate
    double y; // y-coordinate
    double vx; // velocity in x-direction
    double vy; // velocity in y-direction
    double mass; // mass of the particle
};

// function for calculating the gravitational force between particles
void calculateForce(struct Particle* p1, struct Particle* p2, double* fx, double* fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx * dx + dy * dy);
    double F = G * p1->mass * p2->mass / (r * r);
    *fx = F * dx / r;
    *fy = F * dy / r;
}

// function for updating the position and velocity of a particle
void updatePosition(struct Particle* p, double fx, double fy) {
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main() {
    // initialize particles
    struct Particle p1 = {0, 0, 0, 0, 5 * pow(10,24)}; // Earth
    struct Particle p2 = {0, 6371000, 7700, 0, 1000}; // asteroid
    struct Particle p3 = {0, -1000000, 0, 0, 2 * pow(10,22)}; // small planet
    struct Particle particles[3] = {p1, p2, p3};

    // run simulation
    for (double t = 0; t < MAX_TIME; t += dt) {
        // calculate forces on each particle
        for (int i = 0; i < 3; i++) {
            double fx = 0;
            double fy = 0;
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    double fx_ij, fy_ij;
                    calculateForce(&particles[i], &particles[j], &fx_ij, &fy_ij);
                    fx += fx_ij;
                    fy += fy_ij;
                }
            }
            updatePosition(&particles[i], fx, fy);
        }

        // print current positions of particles
        printf("Time: %f\n", t);
        for (int i = 0; i < 3; i++) {
            printf("Particle %d: (%f, %f)\n", i+1, particles[i].x, particles[i].y);
        }
        printf("\n");
    }

    return 0;
}