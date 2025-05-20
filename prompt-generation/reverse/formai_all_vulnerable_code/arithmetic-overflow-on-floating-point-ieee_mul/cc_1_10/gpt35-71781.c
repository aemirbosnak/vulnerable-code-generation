//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 6.6743e-11;

typedef struct {
    double x;
    double y;
} vector_t;

typedef struct {
    vector_t pos;
    vector_t speed;
    double mass;
} planet_t;

void update(planet_t *p, vector_t force, double dt) {
    vector_t acceleration = {
        .x = force.x / p->mass,
        .y = force.y / p->mass
    };
    p->speed.x += acceleration.x * dt;
    p->speed.y += acceleration.y * dt;
    p->pos.x += p->speed.x * dt;
    p->pos.y += p->speed.y * dt;
}

vector_t gravity_force(planet_t *a, planet_t *b) {
    vector_t pos_diff = {
        .x = a->pos.x - b->pos.x,
        .y = a->pos.y - b->pos.y
    };
    double distance = sqrt(pow(pos_diff.x, 2) + pow(pos_diff.y, 2));
    double force_magnitude = G * a->mass * b->mass / pow(distance, 2);
    vector_t force = {
        .x = -force_magnitude * (pos_diff.x / distance),
        .y = -force_magnitude * (pos_diff.y / distance)
    };
    return force;
}

int main() {
    planet_t planets[] = {
        { .pos = { .x = 0, .y = 0 }, .speed = { .x = 0, .y = 0 }, .mass = 5.9742e24 },
        { .pos = { .x = 6.3781e6, .y = 0 }, .speed = { .x = 0, .y = -7.9e3 }, .mass = 1000 }
    };
    int num_planets = sizeof(planets) / sizeof(planet_t);
    double dt = 1;
    int num_steps = 10000;
    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < num_planets; j++) {
            vector_t force = { .x = 0, .y = 0 };
            for (int k = 0; k < num_planets; k++) {
                if (j == k) continue;
                vector_t f = gravity_force(&planets[j], &planets[k]);
                force.x += f.x;
                force.y += f.y;
            }
            update(&planets[j], force, dt);
        }
        printf("Step %d:\n", i+1);
        for (int j = 0; j < num_planets; j++) {
            printf("Planet %d, x = %e, y = %e\n", j, planets[j].pos.x, planets[j].pos.y);
        }
    }
    return 0;
}