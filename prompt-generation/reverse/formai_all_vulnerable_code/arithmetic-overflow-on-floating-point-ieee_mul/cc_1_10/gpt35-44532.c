//FormAI DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define G 6.67e-11   // Gravitational constant

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
    double radius;
} Body;

void update_position(Body *body, double dt) {
    body->position.x += body->velocity.x * dt;
    body->position.y += body->velocity.y * dt;
}

Vector2D calculate_force(Body *body1, Body *body2) {
    double distance = sqrt(pow(body1->position.x - body2->position.x, 2) + pow(body1->position.y - body2->position.y, 2));
    double force = G * ((body1->mass * body2->mass) / pow(distance, 2));
    Vector2D direction = {
        .x = (body2->position.x - body1->position.x) / distance,
        .y = (body2->position.y - body1->position.y) / distance
    };
    return (Vector2D) {.x = force * direction.x, .y = force * direction.y};
}

void update_velocity(Body *body, Vector2D force, double dt) {
    Vector2D acceleration = {
        .x = force.x / body->mass,
        .y = force.y / body->mass
    };
    body->velocity.x += acceleration.x * dt;
    body->velocity.y += acceleration.y * dt;
}

void simulate(Body *bodies, int num_bodies, double total_time, double time_step) {
    for (double current_time = 0; current_time < total_time; current_time += time_step) {
        for (int i = 0; i < num_bodies; i++) {
            Vector2D force = {0, 0};
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    Vector2D force_ij = calculate_force(&bodies[i], &bodies[j]);
                    force.x += force_ij.x;
                    force.y += force_ij.y;
                }
            }
            update_velocity(&bodies[i], force, time_step);
        }
        for (int i = 0; i < num_bodies; i++) {
            update_position(&bodies[i], time_step);
        }
    }
}

int main() {
    Body sun = {
        .position = { .x = 0, .y = 0 },
        .velocity = { .x = 0, .y = 0 },
        .mass = 1.989e30,
        .radius = 696340e3
    };
    Body earth = {
        .position = { .x = 1.496e11, .y = 0 },
        .velocity = { .x = 0, .y = 29800 },
        .mass = 5.972e24,
        .radius = 6371e3
    };
    Body moon = {
        .position = { .x = 1.496e11 + 384400e3, .y = 0 },
        .velocity = { .x = 0, .y = 29800 + 1022 },
        .mass = 7.342e22,
        .radius = 1737.5e3
    };
    Body bodies[3] = {sun, earth, moon};
    simulate(bodies, 3, 31536000, 86400);    // simulate for 1 year with time step of 1 day
    return 0;
}