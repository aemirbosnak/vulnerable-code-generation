//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67430e-11
#define DAY 86400
#define YEAR 31557600

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Body;

Body sun = {G, {0, 0, 0}, {0, 0, 0}};
Body earth = {5.972e24, {1, 0, 0}, {0, 29.78e3, 0}};
Body moon = {7.347e22, {384.4e3, 0, 0}, {0, 29.78e3, 0}};

void advance(Body *body, double dt) {
    Vector acc = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            Body *other = (i == 0)? &sun : (j == 0)? &earth : &moon;
            Vector r = {body->position.x - other->position.x, body->position.y - other->position.y, body->position.z - other->position.z};
            double r2 = r.x * r.x + r.y * r.y + r.z * r.z;
            double f = G * body->mass * other->mass / (r2 * r2);
            acc.x += f * r.x / r2;
            acc.y += f * r.y / r2;
            acc.z += f * r.z / r2;
        }
    }
    body->velocity.x += acc.x * dt;
    body->velocity.y += acc.y * dt;
    body->velocity.z += acc.z * dt;
    body->position.x += body->velocity.x * dt;
    body->position.y += body->velocity.y * dt;
    body->position.z += body->velocity.z * dt;
}

void print_body(Body *body) {
    printf("%.2f %.2f %.2f\n", body->position.x / 1e6, body->position.y / 1e6, body->position.z / 1e6);
}

int main(int argc, char **argv) {
    double dt = DAY / 100;
    for (int i = 0; i < 365 * 10; i++) {
        advance(&earth, dt);
        advance(&moon, dt);
    }
    return 0;
}