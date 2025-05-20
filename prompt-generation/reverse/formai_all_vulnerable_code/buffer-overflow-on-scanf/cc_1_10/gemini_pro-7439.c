//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} planet_t;

const double G = 6.674e-11;  // Gravitational constant (N m^2 / kg^2)
const double DT = 1e3;        // Time step (s)

void update_positions(planet_t *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].x += planets[i].vx * DT;
        planets[i].y += planets[i].vy * DT;
    }
}

void update_velocities(planet_t *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        for (int j = i + 1; j < num_planets; j++) {
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double distance = sqrt(dx * dx + dy * dy);
            double force = G * planets[i].mass * planets[j].mass / (distance * distance);
            double theta = atan2(dy, dx);
            planets[i].vx += force * cos(theta) / planets[i].mass * DT;
            planets[i].vy += force * sin(theta) / planets[i].mass * DT;
            planets[j].vx -= force * cos(theta) / planets[j].mass * DT;
            planets[j].vy -= force * sin(theta) / planets[j].mass * DT;
        }
    }
}

int main() {
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    planet_t *planets = malloc(sizeof(planet_t) * num_planets);

    for (int i = 0; i < num_planets; i++) {
        printf("Enter the mass, x-coordinate, y-coordinate, x-velocity, and y-velocity of planet %d: ", i + 1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
    }

    int num_steps;
    printf("Enter the number of time steps: ");
    scanf("%d", &num_steps);

    for (int step = 0; step < num_steps; step++) {
        update_positions(planets, num_planets);
        update_velocities(planets, num_planets);
    }

    for (int i = 0; i < num_planets; i++) {
        printf("The final position of planet %d is (%lf, %lf)\n", i + 1, planets[i].x, planets[i].y);
    }

    free(planets);

    return 0;
}