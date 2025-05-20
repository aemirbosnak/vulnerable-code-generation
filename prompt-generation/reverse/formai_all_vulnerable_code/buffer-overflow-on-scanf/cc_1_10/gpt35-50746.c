//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

typedef struct planet {
    char name[20];
    double mass;
    double x, y, z; // position
    double vx, vy, vz; // velocity
} planet_t;

int main() {
    int num_planets;
    printf("Enter the number of planets you'd like to simulate: ");
    scanf("%d", &num_planets);
    planet_t* planets = malloc(num_planets * sizeof(planet_t));

    for (int i = 0; i < num_planets; i++) {
        printf("Enter the name, mass, and initial position and velocity of planet %d:\n", i+1);
        scanf("%s %lf %lf %lf %lf %lf %lf %lf", planets[i].name, &planets[i].mass,
            &planets[i].x, &planets[i].y, &planets[i].z, &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    double time_step, max_time;
    printf("Enter the time step and maximum time for the simulation: ");
    scanf("%lf %lf", &time_step, &max_time);

    for (double t = 0; t <= max_time; t += time_step) {
        // calculate accelerations
        for (int i = 0; i < num_planets; i++) {
            double ax = 0, ay = 0, az = 0;
            for (int j = 0; j < num_planets; j++) {
                if (j == i) continue;
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dz = planets[j].z - planets[i].z;
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                double a = G * planets[j].mass / (r*r*r);
                ax += a * dx; ay += a * dy; az += a * dz;
            }
            planets[i].vx += ax * time_step;
            planets[i].vy += ay * time_step;
            planets[i].vz += az * time_step;
        }

        // update positions
        for (int i = 0; i < num_planets; i++) {
            planets[i].x += planets[i].vx * time_step;
            planets[i].y += planets[i].vy * time_step;
            planets[i].z += planets[i].vz * time_step;
        }

        printf("Time: %lf\n", t);
        for (int i = 0; i < num_planets; i++) {
            printf("%s: (%lf, %lf, %lf)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
        }
        printf("\n");
    }

    free(planets);
    return 0;
}