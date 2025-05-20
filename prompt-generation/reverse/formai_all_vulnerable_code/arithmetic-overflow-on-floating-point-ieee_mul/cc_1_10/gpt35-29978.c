//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11
#define M_SUN 1.9885e30

struct Vector {
    double x, y;
};

struct Body {
    struct Vector position, velocity, acceleration;
    double mass;
};

void calculate_acceleration(struct Body *body1, struct Body *body2) {
    double distance = sqrt(pow(body1->position.x-body2->position.x, 2) + pow(body1->position.y-body2->position.y, 2));
    double acceleration_magnitude = G * body2->mass / pow(distance, 2);
    double angle = atan2(body2->position.y-body1->position.y, body2->position.x-body1->position.x);
    body1->acceleration.x += acceleration_magnitude * cos(angle);
    body1->acceleration.y += acceleration_magnitude * sin(angle);
}

void update_position(struct Body *body, double dt) {
    body->position.x += body->velocity.x * dt + 0.5 * body->acceleration.x * pow(dt, 2);
    body->position.y += body->velocity.y * dt + 0.5 * body->acceleration.y * pow(dt, 2);
}

void update_velocity(struct Body *body, double dt) {
    body->velocity.x += body->acceleration.x * dt;
    body->velocity.y += body->acceleration.y * dt;
}

int main() {
    struct Body sun = {.mass = M_SUN};

    struct Body earth = {
        .position = {.x = 147e9, .y = 0},
        .velocity = {.x = 0, .y = 29.78e3},
        .mass = 5.972e24
    };

    for (double t = 0; t < 31557600; t += 86400) {
        earth.acceleration.x = 0;
        earth.acceleration.y = 0;
        calculate_acceleration(&earth, &sun);
        update_position(&earth, 86400);
        calculate_acceleration(&earth, &sun);
        update_velocity(&earth, 86400);
        printf("Day %d: (%f, %f)\n", (int) (t/86400), earth.position.x, earth.position.y);
    }
}