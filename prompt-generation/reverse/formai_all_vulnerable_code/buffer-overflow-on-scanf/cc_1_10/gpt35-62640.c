//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11  // Gravitational constant in m^3/(kg*s^2)

typedef struct {
    double x, y, z;  // x, y, z components of position vector
    double vx, vy, vz;  // x, y, z components of velocity vector
    double ax, ay, az;  // x, y, z components of acceleration vector
    double mass;  // mass of the planet
} planet;

void initialize_planets(planet *p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter values for planet %d:\n", i+1);
        printf("Position (x y z): ");
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
        printf("Velocity (vx vy vz): ");
        scanf("%lf %lf %lf", &p[i].vx, &p[i].vy, &p[i].vz);
        printf("Mass: ");
        scanf("%lf", &p[i].mass);
        p[i].ax = p[i].ay = p[i].az = 0;  // initialize acceleration vector to 0
    }
}

void update_planet(planet *p, double dt) {
    p->x += p->vx * dt + 0.5 * p->ax * dt * dt;
    p->y += p->vy * dt + 0.5 * p->ay * dt * dt;
    p->z += p->vz * dt + 0.5 * p->az * dt * dt;
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void compute_acceleration(planet *p, int n) {
    double dx, dy, dz, r, fx, fy, fz;
    int i, j;
    for (i = 0; i < n; i++) {
        fx = fy = fz = 0;  // initialize forces to 0
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;  // skip self-interaction
            }
            dx = p[j].x - p[i].x;
            dy = p[j].y - p[i].y;
            dz = p[j].z - p[i].z;
            r = sqrt(dx*dx + dy*dy + dz*dz);
            fx += GRAV_CONST * p[j].mass * dx / (r*r*r);
            fy += GRAV_CONST * p[j].mass * dy / (r*r*r);
            fz += GRAV_CONST * p[j].mass * dz / (r*r*r);
        }
        p[i].ax = fx / p[i].mass;
        p[i].ay = fy / p[i].mass;
        p[i].az = fz / p[i].mass;
    }
}

int main() {
    int n;
    double dt, t;
    printf("Enter number of planets: ");
    scanf("%d", &n);
    planet planets[n];
    initialize_planets(planets, n);
    printf("Enter time step (seconds): ");
    scanf("%lf", &dt);
    printf("Enter total simulation time (seconds): ");
    scanf("%lf", &t);

    printf("Simulation running...\n");

    int i, j;
    double time;
    for (time = 0; time < t; time += dt) {
        compute_acceleration(planets, n);
        for (i = 0; i < n; i++) {
            update_planet(&planets[i], dt);
        }
    }
    printf("Simulation completed!\n");

    printf("Planet positions and velocities at end of simulation:\n");
    for (i = 0; i < n; i++) {
        printf("Planet %d:\n", i+1);
        printf("Position: (%lf, %lf, %lf)\n", planets[i].x, planets[i].y, planets[i].z);
        printf("Velocity: (%lf, %lf, %lf)\n", planets[i].vx, planets[i].vy, planets[i].vz);
    }
    return 0;
}