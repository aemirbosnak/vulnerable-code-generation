//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.6743e-11

struct Planet {
    char name[10];
    double mass;
    double x;
    double y;
    double z;
    double fx;
    double fy;
    double fz;
};

void calculate_force(struct Planet *p1, struct Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = GRAVITY_CONSTANT * p1->mass * p2->mass / (distance * distance);
    p1->fx += force * dx / distance;
    p1->fy += force * dy / distance;
    p1->fz += force * dz / distance;
}

void update_position(struct Planet *p, double timestep) {
    p->x += p->fx * timestep / p->mass;
    p->y += p->fy * timestep / p->mass;
    p->z += p->fz * timestep / p->mass;
    p->fx = 0;
    p->fy = 0;
    p->fz = 0;
}

int main() {
    struct Planet planets[3];
    planets[0] = (struct Planet){"earth", 5.97e24, 0, 0, 0, 0, 0, 0};
    planets[1] = (struct Planet){"moon", 7.34e22, 3.84e8, 0, 0, 0, 0, 0};
    planets[2] = (struct Planet){"sun", 1.99e30, 0, 0, 0, 0, 0, 0};

    double timestep = 60.0;
    int num_steps = 1000;

    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = j+1; k < 3; k++) {
                calculate_force(&planets[j], &planets[k]);
                calculate_force(&planets[k], &planets[j]);
            }
        }
        for (int j = 0; j < 3; j++) {
            update_position(&planets[j], timestep);
        }

        printf("Step %d:\n", i);
        printf("  %s: (%.2f, %.2f, %.2f)\n", planets[0].name, planets[0].x, planets[0].y, planets[0].z);
        printf("  %s: (%.2f, %.2f, %.2f)\n", planets[1].name, planets[1].x, planets[1].y, planets[1].z);
        printf("  %s: (%.2f, %.2f, %.2f)\n", planets[2].name, planets[2].x, planets[2].y, planets[2].z);
    }

    return 0;
}