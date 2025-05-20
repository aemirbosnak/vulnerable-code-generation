//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11    // gravitational constant
#define DT 86400         // time step of 24 hours

typedef struct vector_t {
    double x, y, z;
} vector_t;

typedef struct body_t {
    char name[20];
    double mass;
    vector_t pos;
    vector_t vel;
} body_t;

const int num_bodies = 9;
body_t bodies[] = {
    {"Sun", 1.9891e30, {0, 0, 0}, {0, 0, 0}},
    {"Mercury", 3.285e23, {4.60012e10, 0, 0}, {0, 3.87067e4, 0}},
    {"Venus", 4.8675e24, {1.07477e11, 0, 0}, {0, 3.5024e4, 0}},
    {"Earth", 5.9724e24, {1.47095e11, 0, 0}, {0, 2.9783e4, 0}},
    {"Mars", 6.4171e23, {2.0662e11, 0, 0}, {0, 2.4077e4, 0}},
    {"Jupiter", 1.8982e27, {7.4052e11, 0, 0}, {0, 1.3071e4, 0}},
    {"Saturn", 5.6834e26, {1.35255e12, 0, 0}, {0, 9.7726e3, 0}},
    {"Uranus", 8.681e25, {2.74131e12, 0, 0}, {0, 6.8352e3, 0}},
    {"Neptune", 1.0244e26, {4.44445e12, 0, 0}, {0, 5.4773e3, 0}}
};

void update_velocities(body_t *bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        vector_t acc = {0, 0, 0};
        for (int j = 0; j < num_bodies; j++) {
            if (i != j) {
                double dx = bodies[j].pos.x - bodies[i].pos.x;
                double dy = bodies[j].pos.y - bodies[i].pos.y;
                double dz = bodies[j].pos.z - bodies[i].pos.z;
                double dist_cubed = pow(sqrt(dx*dx + dy*dy + dz*dz), 3);
                vector_t force = {G * bodies[i].mass * bodies[j].mass * dx / dist_cubed,
                                  G * bodies[i].mass * bodies[j].mass * dy / dist_cubed,
                                  G * bodies[i].mass * bodies[j].mass * dz / dist_cubed};
                acc.x += force.x / bodies[i].mass;
                acc.y += force.y / bodies[i].mass;
                acc.z += force.z / bodies[i].mass;
            }
        }
        bodies[i].vel.x += acc.x * dt;
        bodies[i].vel.y += acc.y * dt;
        bodies[i].vel.z += acc.z * dt;
    }
}

void update_positions(body_t *bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
        bodies[i].pos.z += bodies[i].vel.z * dt;
    }
}

void print_body(body_t body) {
    printf("%-8s | position: %.2e %.2e %.2e | velocity: %.2e %.2e %.2e\n", 
           body.name, body.pos.x, body.pos.y, body.pos.z, body.vel.x, body.vel.y, body.vel.z);
}

void print_bodies(body_t *bodies, int num_bodies) {
    printf("%-8s | %-30s | %-30s\n", "Name", "Position", "Velocity");
    printf("--------|--------------------------------|--------------------------------\n");
    for (int i = 0; i < num_bodies; i++) {
        print_body(bodies[i]);
    }
    printf("\n");
}

int main() {
    int steps = 365; // simulate for one year
    for (int i = 0; i < steps; i++) {
        update_velocities(bodies, num_bodies, DT);
        update_positions(bodies, num_bodies, DT);
    }
    print_bodies(bodies, num_bodies);
    return 0;
}