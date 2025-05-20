//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <math.h>

#define G 6.674e-11     // Gravitational constant
#define M_SUN 1.988e30  // Mass of the Sun

struct Vector {
    double x;
    double y;
};

struct Object {
    double mass;
    struct Vector pos;
    struct Vector vel;
};

void update_position(struct Object *obj, double dt) {
    obj->pos.x += obj->vel.x * dt;
    obj->pos.y += obj->vel.y * dt;
}

void update_velocity(struct Object *obj, struct Vector acc, double dt) {
    obj->vel.x += acc.x * dt;
    obj->vel.y += acc.y * dt;
}

struct Vector gravitational_force(struct Object obj1, struct Object obj2) {
    double dist = sqrt(pow(obj2.pos.x - obj1.pos.x, 2) + pow(obj2.pos.y - obj1.pos.y, 2));
    double f_mag = G * obj1.mass * obj2.mass / pow(dist, 2);
    struct Vector f;
    f.x = f_mag * (obj2.pos.x - obj1.pos.x) / dist;
    f.y = f_mag * (obj2.pos.y - obj1.pos.y) / dist;
    return f;
}

int main() {
    struct Object sun = {M_SUN, {0, 0}, {0, 0}};
    struct Object earth = {5.972e24, {1.496e11, 0}, {0, 2.97e4}};
    double dt = 3600;

    for (int i = 0; i < 365; i++) {
        struct Vector force = gravitational_force(sun, earth);
        update_velocity(&earth, force, dt);
        update_position(&earth, dt);
        printf("Day %d: Earth position: (%.2f, %.2f)\n", i+1, earth.pos.x, earth.pos.y);
    }

    return 0;
}