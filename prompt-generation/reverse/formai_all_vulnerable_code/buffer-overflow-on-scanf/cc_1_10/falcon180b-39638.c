//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674 // Gravitational Constant

// Function to calculate the distance between two planets
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the gravitational force between two planets
double gravity(double m1, double m2, double r) {
    return G * m1 * m2 / (r*r);
}

int main() {
    int num_planets;
    double **planets;
    double dt = 0.01; // Time step
    double t = 0.0; // Current time
    double t_end = 1000.0; // End time

    // Initialize the number of planets
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    // Allocate memory for the planets
    planets = (double **)malloc(num_planets * sizeof(double *));
    for (int i = 0; i < num_planets; i++) {
        planets[i] = (double *)malloc(3 * sizeof(double));
        printf("Enter the initial position of planet %d (x y z): ", i+1);
        scanf("%lf %lf %lf", &planets[i][0], &planets[i][1], &planets[i][2]);
        printf("Enter the mass of planet %d: ", i+1);
        scanf("%lf", &planets[i][3]);
    }

    // Run the simulation
    while (t < t_end) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = i+1; j < num_planets; j++) {
                // Calculate the distance between two planets
                double r = distance(planets[i][0], planets[i][1], planets[j][0], planets[j][1]);

                // Calculate the gravitational force between two planets
                double fx = gravity(planets[i][3], planets[j][3], r) * (planets[j][0] - planets[i][0]) / r;
                double fy = gravity(planets[i][3], planets[j][3], r) * (planets[j][1] - planets[i][1]) / r;
                double fz = gravity(planets[i][3], planets[j][3], r) * (planets[j][2] - planets[i][2]) / r;

                // Apply the gravitational force to the planets
                planets[i][0] += fx * dt;
                planets[i][1] += fy * dt;
                planets[i][2] += fz * dt;
                planets[j][0] -= fx * dt;
                planets[j][1] -= fy * dt;
                planets[j][2] -= fz * dt;
            }
        }
        t += dt;
    }

    // Free the memory
    for (int i = 0; i < num_planets; i++) {
        free(planets[i]);
    }
    free(planets);

    return 0;
}