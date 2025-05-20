//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUN_MASS 1.989e30 // kg
#define EARTH_MASS 5.972e24 // kg
#define MOON_MASS 7.348e22 // kg
#define GRAV_CONST 6.674e-11 // m^3 kg^-1 s^-2

#define TIME_STEP 60*60*24 // seconds
#define DURATION 365*24*60*60 // seconds

typedef struct {
    double x;
    double y;
    double z;
} vec_t;

typedef struct {
    vec_t position;
    vec_t velocity;
    double mass;
} body_t;

vec_t vec_add(vec_t a, vec_t b) {
    vec_t c = {a.x + b.x, a.y + b.y, a.z + b.z};
    return c;
}

vec_t vec_sub(vec_t a, vec_t b) {
    vec_t c = {a.x - b.x, a.y - b.y, a.z - b.z};
    return c;
}

double vec_mag(vec_t a) {
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

vec_t vec_scale(vec_t a, double scalar) {
    vec_t c = {a.x * scalar, a.y * scalar, a.z * scalar};
    return c;
}

vec_t force(body_t a, body_t b) {
    vec_t dist = vec_sub(a.position, b.position);
    double mag = GRAV_CONST * a.mass * b.mass / pow(vec_mag(dist), 2);
    return vec_scale(dist, -mag/vec_mag(dist));
}

void update_step(body_t *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        vec_t force_total = {0, 0, 0};
        for (int j = 0; j < num_bodies; j++) {
            if (i != j) {
                vec_t current_force = force(bodies[i], bodies[j]);
                force_total = vec_add(force_total, current_force);
            }
        }
        vec_t acceleration = vec_scale(force_total, 1/bodies[i].mass);
        bodies[i].position = vec_add(bodies[i].position, vec_scale(bodies[i].velocity, TIME_STEP));
        bodies[i].velocity = vec_add(bodies[i].velocity, vec_scale(acceleration, TIME_STEP));
    }
}

int main() {
    body_t sun = {{0, 0, 0}, {0, 0, 0}, SUN_MASS};
    body_t earth = {{149.6e9, 0, 0}, {0, 29.6e3, 0}, EARTH_MASS};
    body_t moon = {{149.6e9 + 384.4e6, 0, 0}, {0, 29.6e3 + 1e3, 0}, MOON_MASS};
    body_t bodies[] = {sun, earth, moon};
    int num_bodies = sizeof(bodies) / sizeof(body_t);
    double time_elapsed = 0;
    while (time_elapsed < DURATION) {
        update_step(bodies, num_bodies);
        printf("Time elapsed: %.2f seconds\n", time_elapsed);
        printf("Earth position: (%e, %e, %e)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon position: (%e, %e, %e)\n", moon.position.x, moon.position.y, moon.position.z);
        time_elapsed += TIME_STEP;
    }
    return 0;
}