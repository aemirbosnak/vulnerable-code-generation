//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67e-11

struct vector {
    double x, y;
};

struct object {
    double mass;
    struct vector position;
    struct vector velocity;
};

struct force {
    struct vector direction;
    double magnitude;
};

struct force calculate_gravitational_force(struct object o1, struct object o2) {
    double distance_squared = pow(o2.position.x - o1.position.x, 2) + pow(o2.position.y - o1.position.y, 2);
    double magnitude = GRAVITATIONAL_CONSTANT * o1.mass * o2.mass / distance_squared;
    struct vector direction = {
        (o2.position.x - o1.position.x) / sqrt(distance_squared),
        (o2.position.y - o1.position.y) / sqrt(distance_squared),
    };
    return (struct force) { .magnitude = magnitude, .direction = direction };
}

void apply_force(struct object *o, struct force f, double duration) {
    double acceleration = f.magnitude / o->mass;
    o->velocity.x += acceleration * f.direction.x * duration;
    o->velocity.y += acceleration * f.direction.y * duration;
    o->position.x += o->velocity.x * duration;
    o->position.y += o->velocity.y * duration;
}

int main() {
    struct object sun = { 1.989e30, { 0, 0 }, { 0, 0 } };
    struct object earth = { 5.97e24, { 147e9, 0 }, { 0, 30300 } };

    double duration = 60 * 60 * 24;
    for (int i = 0; i < 365; i++) {
        struct force f = calculate_gravitational_force(sun, earth);
        apply_force(&earth, f, duration);
        printf("Day %d: x=%e m, y=%e m\n", i + 1, earth.position.x, earth.position.y);
    }

    return 0;
}