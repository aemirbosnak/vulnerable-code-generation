//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11 // Gravitational constant
#define TIME_STEP 0.01 // Time step for simulation
#define NUM_PLANETS 3 // Number of planets

typedef struct {
    char name[20];
    double mass; // Mass in kg
    double x;    // Position in m
    double y;    // Position in m
    double vx;   // Velocity in m/s
    double vy;   // Velocity in m/s
} Planet;

void init_planets(Planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Enter the name of planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        printf("Enter mass (in kg) of %s: ", planets[i].name);
        scanf("%lf", &planets[i].mass);
        printf("Enter initial x position (in m) of %s: ", planets[i].name);
        scanf("%lf", &planets[i].x);
        printf("Enter initial y position (in m) of %s: ", planets[i].name);
        scanf("%lf", &planets[i].y);
        planets[i].vx = 0; // Starting with no initial velocity in x
        planets[i].vy = 0; // Starting with no initial velocity in y
    }
}

void calculate_gravitational_force(Planet p1, Planet p2, double *fx, double *fy) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double distance = sqrt(dx * dx + dy * dy);
    
    if (distance == 0) return; // Avoid division by zero

    double force = G * p1.mass * p2.mass / (distance * distance);
    
    *fx += force * (dx / distance); // Force in x direction
    *fy += force * (dy / distance); // Force in y direction
}

void update_planets(Planet *planets) {
    double fx[NUM_PLANETS] = {0};
    double fy[NUM_PLANETS] = {0};

    // Calculate forces between each pair of planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                calculate_gravitational_force(planets[i], planets[j], &fx[i], &fy[i]);
            }
        }
    }

    // Update position and velocity of each planet
    for (int i = 0; i < NUM_PLANETS; i++) {
        double ax = fx[i] / planets[i].mass; // Acceleration in x direction
        double ay = fy[i] / planets[i].mass; // Acceleration in y direction

        planets[i].vx += ax * TIME_STEP; // Update velocity in x
        planets[i].vy += ay * TIME_STEP; // Update velocity in y
        planets[i].x += planets[i].vx * TIME_STEP; // Update position in x
        planets[i].y += planets[i].vy * TIME_STEP; // Update position in y
    }
}

void display_positions(Planet *planets) {
    printf("\nCurrent positions and velocities:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: Position (%.2f, %.2f), Velocity (%.2f, %.2f)\n",
               planets[i].name, planets[i].x, planets[i].y,
               planets[i].vx, planets[i].vy);
    }
}

int main() {
    Planet planets[NUM_PLANETS];
    init_planets(planets);

    int steps = 1000; // Number of simulation steps
    for (int i = 0; i < steps; i++) {
        update_planets(planets);
        display_positions(planets);
        usleep(100000); // Sleep for 0.1 second to slow down output
    }

    printf("Simulation completed.\n");
    return 0;
}