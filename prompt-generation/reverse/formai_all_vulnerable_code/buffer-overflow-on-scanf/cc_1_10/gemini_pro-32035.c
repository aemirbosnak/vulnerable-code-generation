//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;
    double x;
    double y;
    double vel_x;
    double vel_y;
    double accel_x;
    double accel_y;
} body;

const double G = 6.67408e-11;

int main() {
    int num_planets;
    double delta_t = 0.01;
    double simulation_time = 1000;

    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    body *planets = malloc(sizeof(body) * num_planets);

    for (int i = 0; i < num_planets; i++) {
        printf("Enter mass of planet %d: ", i + 1);
        scanf("%lf", &planets[i].mass);

        printf("Enter x coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].x);

        printf("Enter y coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].y);

        printf("Enter velocity in x of planet %d: ", i + 1);
        scanf("%lf", &planets[i].vel_x);

        printf("Enter velocity in y of planet %d: ", i + 1);
        scanf("%lf", &planets[i].vel_y);

        planets[i].accel_x = 0;
        planets[i].accel_y = 0;
    }

    for (int t = 0; t < simulation_time; t++) {
        // Calculate accelerations
        for (int i = 0; i < num_planets; i++) {
            planets[i].accel_x = 0;
            planets[i].accel_y = 0;

            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue;

                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double r = sqrt(dx * dx + dy * dy);

                // Calculate acceleration
                double accel = G * planets[j].mass / (r * r);

                planets[i].accel_x += accel * dx / r;
                planets[i].accel_y += accel * dy / r;
            }
        }

        // Update velocities and positions
        for (int i = 0; i < num_planets; i++) {
            planets[i].vel_x += planets[i].accel_x * delta_t;
            planets[i].vel_y += planets[i].accel_y * delta_t;

            planets[i].x += planets[i].vel_x * delta_t;
            planets[i].y += planets[i].vel_y * delta_t;
        }
    }

    // Print the final positions of the planets
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.2lf, %.2lf)\n", i + 1, planets[i].x, planets[i].y);
    }

    free(planets);
    return 0;
}