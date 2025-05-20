//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PLANETS 5

typedef struct {
    double x, y, vx, vy, mass;
} Planet;

void update_velocities(Planet planets[MAX_PLANETS], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        double total_x = 0, total_y = 0;
        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double distance = sqrt(dx*dx + dy*dy);
                total_x += (dx * planets[j].mass / distance) / (2.0 * M_PI * pow(distance, 2));
                total_y += (dy * planets[j].mass / distance) / (2.0 * M_PI * pow(distance, 2));
            }
        }
        planets[i].vx += total_x;
        planets[i].vy += total_y;
    }
}

void update_positions(Planet planets[MAX_PLANETS], int num_planets, double dt) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

int main() {
    Planet planets[MAX_PLANETS];

    planets[0].x = 0; planets[0].y = 0; planets[0].mass = 5.972e24; // Earth
    planets[1].x = 1.521e11; planets[1].y = 0; planets[1].mass = 7.348e22; // Moon
    planets[2].x = 7.441e11; planets[2].y = 0; planets[2].mass = 5.97e24; // Mars
    planets[3].x = -5.43e11; planets[3].y = 0; planets[3].mass = 7.348e22; // Phobos
    planets[4].x = -3.78e11; planets[4].y = 1.268e11; planets[4].mass = 1.07e23; // Deimos

    const double dt = 3600; // seconds

    int num_planets = 5;

    for (int step = 0; step < 1000; step++) {
        update_velocities(planets, num_planets);
        update_positions(planets, num_planets, dt);
        printf("Step %d: ", step);
        for (int i = 0; i < num_planets; i++) {
            printf("Planet %d: x = %.12f, y = %.12f\n", i, planets[i].x, planets[i].y);
        }
    }

    return 0;
}