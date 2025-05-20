//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant in m^3/(kg s^2)

struct planet {
    char name[20];
    float mass; // in kg
    float x; // x-coordinate in m
    float y; // y-coordinate in m
    float z; // z-coordinate in m
    float vx; // x-velocity in m/s
    float vy; // y-velocity in m/s
    float vz; // z-velocity in m/s
};

void update_velocity(struct planet *p1, struct planet *p2, float delta_t) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    float dz = p2->z - p1->z;
    float distance = sqrt(dx*dx + dy*dy + dz*dz);
    float force = G * p1->mass * p2->mass / (distance * distance);
    float fx = force * dx / distance;
    float fy = force * dy / distance;
    float fz = force * dz / distance;
    p1->vx += fx/p1->mass * delta_t;
    p1->vy += fy/p1->mass * delta_t;
    p1->vz += fz/p1->mass * delta_t;
}

void update_position(struct planet *p, float delta_t) {
    p->x += p->vx * delta_t;
    p->y += p->vy * delta_t;
    p->z += p->vz * delta_t;
}

void print_planet(struct planet *p) {
    printf("%s\n", p->name);
    printf("x: %f m, y: %f m, z: %f m\n", p->x, p->y, p->z);
    printf("vx: %f m/s, vy: %f m/s, vz: %f m/s\n", p->vx, p->vy, p->vz);
}

int main() {
    struct planet earth = {"Earth", 5.972e24, 0, 0, 0, 0, 0, 0};
    struct planet moon = {"Moon", 7.342e22, 3.844e8, 0, 0, 0, 1022, 0};
    struct planet sun = {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0};
    float delta_t = 86400; // time step in seconds (1 day)
    int num_steps = 365; // number of time steps in 1 year
    for (int i = 0; i < num_steps; i++) {
        // update earth's velocity due to moon's gravity
        update_velocity(&earth, &moon, delta_t);
        // update earth's velocity due to sun's gravity
        update_velocity(&earth, &sun, delta_t);
        // update moon's velocity due to earth's gravity
        update_velocity(&moon, &earth, delta_t);
        // update moon's velocity due to sun's gravity
        update_velocity(&moon, &sun, delta_t);
        // update sun's velocity due to earth's gravity
        update_velocity(&sun, &earth, delta_t);
        // update sun's velocity due to moon's gravity
        update_velocity(&sun, &moon, delta_t);
        // update positions of all planets
        update_position(&earth, delta_t);
        update_position(&moon, delta_t);
        update_position(&sun, delta_t);
    }
    // print final positions and velocities of all planets
    print_planet(&earth);
    print_planet(&moon);
    print_planet(&sun);
    return 0;
}