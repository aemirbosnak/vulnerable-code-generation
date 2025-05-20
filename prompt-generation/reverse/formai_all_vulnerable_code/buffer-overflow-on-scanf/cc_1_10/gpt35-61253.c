//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: satisfied
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define G 6.674E-11 // Gravitational constant
#define MAX_PLANETS 10 // Maximum number of planets
#define INTERVAL 86400 // One day in seconds

typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double mass; // Mass
} Planet;

void calculate_forces(Planet planets[], int n) {
    int i, j;
    double dx, dy, dz, dist, fx, fy, fz;

    for (i = 0; i < n; i++) {
        fx = fy = fz = 0.0;

        for (j = 0; j < n; j++) {
            if (i != j) {
                dx = planets[j].x - planets[i].x;
                dy = planets[j].y - planets[i].y;
                dz = planets[j].z - planets[i].z;

                dist = sqrt(dx*dx + dy*dy + dz*dz);
                fx += G * planets[i].mass * planets[j].mass * dx / pow(dist, 3);
                fy += G * planets[i].mass * planets[j].mass * dy / pow(dist, 3);
                fz += G * planets[i].mass * planets[j].mass * dz / pow(dist, 3);
            }
        }

        planets[i].vx += fx / planets[i].mass * INTERVAL;
        planets[i].vy += fy / planets[i].mass * INTERVAL;
        planets[i].vz += fz / planets[i].mass * INTERVAL;
    }
}

void update_positions(Planet planets[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        planets[i].x += planets[i].vx * INTERVAL;
        planets[i].y += planets[i].vy * INTERVAL;
        planets[i].z += planets[i].vz * INTERVAL;
    }
}

int main() {
    int i; 
    Planet planets[MAX_PLANETS];
    int n; // Number of planets
    double t; // Time elapsed
    bool continue_simulation = true;

    printf("Enter number of planets (max %d): ", MAX_PLANETS);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Planet %d:\n", i+1);
        printf("Mass (kg): ");
        scanf("%lf", &planets[i].mass);
        printf("x,y,z (m): ");
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        printf("vx,vy,vz (m/s): ");
        scanf("%lf %lf %lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    t = 0.0;
    while (continue_simulation) {
        calculate_forces(planets, n);
        update_positions(planets, n);
        t += INTERVAL;

        printf("Time: %g s\n", t);
        for (i = 0; i < n; i++) {
            printf("Planet %d: x=%g m, y=%g m, z=%g m\n", i+1, planets[i].x, planets[i].y, planets[i].z);
        }

        printf("Do you want to continue (y/n)? ");
        char c;
        scanf(" %c", &c);
        if (c == 'n') {
            continue_simulation = false;
        }
    }

    return 0;
}