//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass; // Mass (kg)
    double x; // X coordinate (m)
    double y; // Y coordinate (m)
    double vx; // X velocity (m/s)
    double vy; // Y velocity (m/s)
} Planet;

void update_velocities(Planet *planets, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double r = sqrt(dx * dx + dy * dy);
            double force = G * planets[i].mass * planets[j].mass / (r * r);
            planets[i].vx += force * dx / r;
            planets[i].vy += force * dy / r;
            planets[j].vx -= force * dx / r;
            planets[j].vy -= force * dy / r;
        }
    }
}

void update_positions(Planet *planets, int n) {
    for (int i = 0; i < n; i++) {
        planets[i].x += planets[i].vx * 0.0001;
        planets[i].y += planets[i].vy * 0.0001;
    }
}

int main() {
    int n; // Number of planets
    printf("Enter the number of planets: ");
    scanf("%d", &n);

    Planet *planets = malloc(n * sizeof(Planet));

    for (int i = 0; i < n; i++) {
        printf("Enter the mass, x-coordinate, y-coordinate, x-velocity, and y-velocity of planet %d: ", i + 1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
    }

    int t; // Time (s)
    printf("Enter the simulation time (s): ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        update_velocities(planets, n);
        update_positions(planets, n);
    }

    for (int i = 0; i < n; i++) {
        printf("The position of planet %d: (%lf, %lf)\n", i + 1, planets[i].x, planets[i].y);
    }

    free(planets);
    return 0;
}