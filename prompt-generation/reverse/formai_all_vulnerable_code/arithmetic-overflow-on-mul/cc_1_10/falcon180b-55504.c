//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PARTICLES 1000
#define G 9.81

// particle structure
typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
} particle;

// initialize particle
void init_particle(particle *p, double x, double y, double z, double vx, double vy, double vz) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
}

// update particle
void update_particle(particle *p, double dt) {
    // calculate acceleration due to gravity
    p->ax = p->vx;
    p->ay = p->vy;
    p->az = p->vz;

    // update velocity and position
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;

    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// check for collision with ground
int check_collision(particle *p) {
    if (p->z < 0) {
        return 1;
    }
    return 0;
}

// generate random particle
void generate_random_particle(particle *p) {
    double radius = 10;
    double theta = 2 * M_PI * rand() / RAND_MAX;
    double phi = acos(2 * rand() / RAND_MAX - 1);

    p->x = radius * sin(theta) * cos(phi);
    p->y = radius * sin(theta) * sin(phi);
    p->z = radius * cos(theta);

    double v = sqrt(2 * G * radius) * sin(phi);
    p->vx = v * cos(theta) * cos(phi);
    p->vy = v * sin(theta) * cos(phi);
    p->vz = v * sin(phi);
}

// main function
int main() {
    srand(time(NULL));

    particle particles[MAX_PARTICLES];
    int num_particles = 0;

    // generate random particles
    while (num_particles < MAX_PARTICLES) {
        generate_random_particle(&particles[num_particles]);
        num_particles++;
    }

    // simulate particle motion
    double dt = 0.001;
    int num_steps = 1000;

    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < num_particles; j++) {
            update_particle(&particles[j], dt);
        }
    }

    // print particle positions
    for (int j = 0; j < num_particles; j++) {
        printf("Particle %d: x = %.2f, y = %.2f, z = %.2f\n", j, particles[j].x, particles[j].y, particles[j].z);
    }

    return 0;
}