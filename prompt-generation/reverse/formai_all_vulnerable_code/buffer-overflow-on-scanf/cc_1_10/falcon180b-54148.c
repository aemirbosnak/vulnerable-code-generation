//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define G 9.81

typedef struct {
    double x, y, z;
} vector;

typedef struct {
    double roll, pitch, yaw;
} euler_angle;

typedef struct {
    double x, y, z, vx, vy, vz;
} drone;

void init_drone(drone *d) {
    d->x = 0;
    d->y = 0;
    d->z = 0;
    d->vx = 0;
    d->vy = 0;
    d->vz = 0;
}

void move_drone(drone *d, euler_angle *e, double dt) {
    double r = cos(e->yaw) * cos(e->pitch);
    double p = sin(e->yaw) * cos(e->pitch);
    double y = sin(e->pitch);

    double vx = d->vx - r * cos(e->roll) * d->vy - p * sin(e->roll) * d->vz;
    double vy = d->vy + r * sin(e->roll) * d->vx + p * cos(e->roll) * d->vz;
    double vz = d->vz + y * d->vx - r * sin(e->roll) * d->vy;

    d->x += d->vx * dt;
    d->y += d->vy * dt;
    d->z += d->vz * dt;

    d->vx = vx;
    d->vy = vy;
    d->vz = vz;
}

int main() {
    srand(time(NULL));

    drone d;
    init_drone(&d);

    while (1) {
        printf("Enter command (up/down/left/right/forward/backward/stop): ");
        char cmd[10];
        scanf("%s", cmd);

        if (strcmp(cmd, "up") == 0) {
            d.vz += 5;
        } else if (strcmp(cmd, "down") == 0) {
            d.vz -= 5;
        } else if (strcmp(cmd, "left") == 0) {
            d.vy -= 5;
        } else if (strcmp(cmd, "right") == 0) {
            d.vy += 5;
        } else if (strcmp(cmd, "forward") == 0) {
            d.vx += 5;
        } else if (strcmp(cmd, "backward") == 0) {
            d.vx -= 5;
        } else if (strcmp(cmd, "stop") == 0) {
            d.vx = 0;
            d.vy = 0;
            d.vz = 0;
        }

        euler_angle e;
        e.roll = 0;
        e.pitch = 0;
        e.yaw = 0;

        move_drone(&d, &e, 0.1);

        printf("Position: (%lf, %lf, %lf)\n", d.x, d.y, d.z);
        printf("Velocity: (%lf, %lf, %lf)\n", d.vx, d.vy, d.vz);
    }

    return 0;
}