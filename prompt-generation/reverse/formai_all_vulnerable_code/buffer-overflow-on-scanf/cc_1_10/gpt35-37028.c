//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11     // gravitational constant

typedef struct Vector {   // vector struct with 3 components
    double x;
    double y;
    double z;
} Vector;

typedef struct Planet {   // planet struct with mass and position vector
    double mass;
    Vector pos;
} Planet;

int main() {
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);
    Planet planets[num_planets];     // array of planets

    // get planet information from user
    for (int i = 0; i < num_planets; i++) {
        printf("Enter mass of planet %d: ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter x, y, z coordinates of planet %d: ", i+1);
        scanf("%lf %lf %lf", &planets[i].pos.x, &planets[i].pos.y, &planets[i].pos.z);
    }

    double time_step;
    printf("Enter the time step: ");
    scanf("%lf", &time_step);

    int num_iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    // simulate planet motion over time
    for (int i = 0; i < num_iterations; i++) {
        for (int j = 0; j < num_planets; j++) {
            Vector force = {0, 0, 0};   // initialize force vector to zero
            for (int k = 0; k < num_planets; k++) {
                if (k != j) {
                    // calculate gravitational force between planets
                    Vector r = {planets[k].pos.x - planets[j].pos.x,
                                planets[k].pos.y - planets[j].pos.y,
                                planets[k].pos.z - planets[j].pos.z};
                    double dist = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
                    double f_mag = G * planets[j].mass * planets[k].mass / (dist*dist);
                    Vector f = {f_mag * r.x / dist, f_mag * r.y / dist, f_mag * r.z / dist};
                    force.x += f.x;
                    force.y += f.y;
                    force.z += f.z;
                }
            }

            // calculate planet acceleration and new position
            Vector acceleration = {force.x / planets[j].mass,
                                   force.y / planets[j].mass,
                                   force.z / planets[j].mass};
            planets[j].pos.x += time_step * (planets[j].pos.x + acceleration.x/2);
            planets[j].pos.y += time_step * (planets[j].pos.y + acceleration.y/2);
            planets[j].pos.z += time_step * (planets[j].pos.z + acceleration.z/2);
        }
    }

    // print final planet positions
    printf("\nFinal planet positions:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%lf, %lf, %lf)\n", i+1, planets[i].pos.x, planets[i].pos.y, planets[i].pos.z);
    }

    return 0;
}