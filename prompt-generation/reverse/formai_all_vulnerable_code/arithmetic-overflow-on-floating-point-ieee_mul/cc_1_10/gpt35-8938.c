//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant in m^3 kg^-1 s^-2

typedef struct {
    char name[20]; // name of planet
    double mass; // mass of planet in kg
    double x, y; // position relative to origin in m
    double vx, vy; // velocity in m/s
} planet;

int num_planets = 3; // number of planets in system
planet planets[3] = { // array of planets
    {"Earth", 5.97e24, 0, 0, 0, 0},
    {"Mars", 6.39e23, 2.28e11, 0, 0, 24000},
    {"Jupiter", 1.90e27, 7.78e11, 0, 0, 13000}
};

double distance(planet p1, planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double force(planet p1, planet p2) {
    return G * p1.mass * p2.mass / pow(distance(p1, p2), 2);
}

void update_velocities() {
    for (int i = 0; i < num_planets; i++) {
        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double f = force(planets[i], planets[j]);
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double angle = atan2(dy, dx);
                planets[i].vx += f * cos(angle) / planets[i].mass;
                planets[i].vy += f * sin(angle) / planets[i].mass;
            }
        }
    }
}

void update_positions(double dt) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

void print_positions() {
    for (int i = 0; i < num_planets; i++) {
        planet p = planets[i];
        printf("%s: (%f, %f)\n", p.name, p.x, p.y);
    }
    printf("\n");
}

int main() {
    double dt = 100; // time step in seconds
    int num_steps = 10; // number of time steps to simulate

    for (int i = 0; i < num_steps; i++) {
        update_velocities();
        update_positions(dt);
        print_positions();
    }

    return 0;
}