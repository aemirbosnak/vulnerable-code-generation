//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: Cryptic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define AU 149597870700.0

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double mass;
    char *name;
} body;

body solar_system[] = {
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.9891e30, "Sun"},
    {0.3871e12, 0.0, 0.0, 0.0, 30.0e3, 0.0, 3.302e23, "Mercury"},
    {0.7233e12, 0.0, 0.0, 0.0, 24.0e3, 0.0, 4.867e24, "Venus"},
    {1.082e12, 0.0, 0.0, 0.0, 23.0e3, 0.0, 5.972e24, "Earth"},
    {1.524e12, 0.0, 0.0, 0.0, 20.0e3, 0.0, 6.417e23, "Mars"},
    {5.203e12, 0.0, 0.0, 0.0, 13.0e3, 0.0, 1.899e27, "Jupiter"},
    {9.539e12, 0.0, 0.0, 0.0, 9.0e3, 0.0, 5.685e26, "Saturn"},
    {1.923e13, 0.0, 0.0, 0.0, 6.0e3, 0.0, 8.683e25, "Uranus"},
    {2.872e13, 0.0, 0.0, 0.0, 5.0e3, 0.0, 1.024e26, "Neptune"},
};

double G = 6.674e-11;

double distance(body *a, body *b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2) + pow(b->z - a->z, 2));
}

void update_positions(body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(&bodies[i], &bodies[j]);
            double force = G * bodies[i].mass * bodies[j].mass / pow(dist, 2);
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            bodies[i].vx += dt * force * dx / dist;
            bodies[i].vy += dt * force * dy / dist;
            bodies[i].vz += dt * force * dz / dist;
            bodies[j].vx -= dt * force * dx / dist;
            bodies[j].vy -= dt * force * dy / dist;
            bodies[j].vz -= dt * force * dz / dist;
        }
        bodies[i].x += dt * bodies[i].vx;
        bodies[i].y += dt * bodies[i].vy;
        bodies[i].z += dt * bodies[i].vz;
    }
}

int main() {
    int n = sizeof(solar_system) / sizeof(body);
    double dt = 1e6;
    int i, j;
    for (i = 0; i < 10000; i++) {
        update_positions(solar_system, n, dt);
        for (j = 0; j < n; j++) {
            printf("%s: (%e, %e, %e)\n", solar_system[j].name, solar_system[j].x / AU, solar_system[j].y / AU, solar_system[j].z / AU);
        }
        printf("\n");
    }
    return 0;
}