//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 9.81
#define PI 3.14159265358979323846
#define RADIUS_EARTH 6371e3
#define TIME_STEP 0.01
#define TOTAL_TIME 1000

typedef struct {
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
} Particle;

void init_particle(Particle* p, double x, double y, double vx, double vy) {
    p->x = x;
    p->y = y;
    p->vx = vx;
    p->vy = vy;
    p->ax = 0;
    p->ay = 0;
}

void update_acceleration(Particle* p, double dt) {
    double ax = 0;
    double ay = G / (p->x * p->x + p->y * p->y);
    p->ax = ax;
    p->ay = ay;
}

void update_velocity(Particle* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void update_position(Particle* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main() {
    srand(time(NULL));
    Particle earth = {0, 0, 0, 0, 0, 0};
    Particle projectile = {0, 0, 100, 0, 0, 0};
    init_particle(&projectile, 0, 0, 100, 0);
    double t = 0;
    while (t < TOTAL_TIME) {
        update_acceleration(&projectile, TIME_STEP);
        update_velocity(&projectile, TIME_STEP);
        update_position(&projectile, TIME_STEP);
        update_acceleration(&earth, TIME_STEP);
        update_velocity(&earth, TIME_STEP);
        update_position(&earth, TIME_STEP);
        double distance = sqrt(pow(projectile.x - earth.x, 2) + pow(projectile.y - earth.y, 2));
        if (distance > RADIUS_EARTH + 100) {
            printf("Projectile missed the Earth.\n");
            break;
        }
        t += TIME_STEP;
    }
    return 0;
}