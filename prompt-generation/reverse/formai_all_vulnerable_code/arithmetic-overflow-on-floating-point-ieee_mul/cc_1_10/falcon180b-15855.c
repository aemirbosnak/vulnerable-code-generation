//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, z;
} Vector3D;

typedef struct {
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
    double mass;
    double force;
} Drone;

Drone createDrone(double x, double y, double z, double m) {
    Drone d;
    d.position.x = x;
    d.position.y = y;
    d.position.z = z;
    d.velocity.x = 0;
    d.velocity.y = 0;
    d.velocity.z = 0;
    d.acceleration.x = 0;
    d.acceleration.y = 0;
    d.acceleration.z = 0;
    d.mass = m;
    d.force = 0;
    return d;
}

void applyForce(Drone* d, double fx, double fy, double fz) {
    d->force = sqrt(pow(fx, 2) + pow(fy, 2) + pow(fz, 2));
}

void updatePosition(Drone* d, double dt) {
    d->velocity.x += d->acceleration.x * dt;
    d->velocity.y += d->acceleration.y * dt;
    d->velocity.z += d->acceleration.z * dt;

    d->position.x += d->velocity.x * dt;
    d->position.y += d->velocity.y * dt;
    d->position.z += d->velocity.z * dt;
}

int main() {
    Drone d = createDrone(0, 0, 0, 1);

    applyForce(&d, 0, 0, 9.81);

    updatePosition(&d, 0.01);

    printf("Position: (%lf, %lf, %lf)\n", d.position.x, d.position.y, d.position.z);

    return 0;
}