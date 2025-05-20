//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.67430e-11 // Gravitational constant in m^3 kg^-1 s^-2

typedef struct {
    double mass; // Mass of the planet in kg
    double radius; // Radius of the planet in meters
    double x; // X position of the planet in meters
    double y; // Y position of the planet in meters
    double vx; // Velocity in x direction in m/s
    double vy; // Velocity in y direction in m/s
} Planet;

void initialize_planet(Planet *p, double mass, double radius, double x, double y, double vx, double vy) {
    p->mass = mass;
    p->radius = radius;
    p->x = x;
    p->y = y;
    p->vx = vx;
    p->vy = vy;
}

double calculate_gravitational_force(Planet *p1, Planet *p2) {
    double distance = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    if (distance == 0) return 0; // Prevent division by zero
    return (G * p1->mass * p2->mass) / (distance * distance);
}

void update_velocity(Planet *planet, double fx, double fy, double dt) {
    double ax = fx / planet->mass;
    double ay = fy / planet->mass;
    planet->vx += ax * dt;
    planet->vy += ay * dt;
}

void update_position(Planet *planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
}

void simulate_step(Planet *p1, Planet *p2, double dt) {
    double fx = calculate_gravitational_force(p1, p2);
    double fy = fx; // For simplicity assuming equal force application along both axes
    
    update_velocity(p1, fx, fy, dt);
    update_velocity(p2, -fx, -fy, dt); // Equal and opposite force
    
    update_position(p1, dt);
    update_position(p2, dt);
}

void print_planet_info(Planet *planet) {
    printf("Planet Mass: %.2e kg\n", planet->mass);
    printf("Position: (%.2f, %.2f) m\n", planet->x, planet->y);
    printf("Velocity: (%.2f, %.2f) m/s\n", planet->vx, planet->vy);
}

int main() {
    Planet earth, moon;

    // Initialize Earth with mass and radius (in kg and meters)
    initialize_planet(&earth, 5.972e24, 6371e3, 0.0, 0.0, 0.0, 0.0);
    
    // Initialize Moon with mass and radius (in kg and meters)
    initialize_planet(&moon, 7.34767309e22, 1737.4e3, 384400e3, 0.0, 0.0, 1.022);
    
    // Simulation parameters
    double dt = 1; // Time step in seconds
    double simulation_time = 60 * 60 * 24; // Simulate for one day
    int steps = (int)(simulation_time / dt);
    
    for (int i = 0; i < steps; i++) {
        simulate_step(&earth, &moon, dt);
        
        // Print every 60th step
        if (i % 60 == 0) {
            printf("\nTime: %d seconds\n", i * dt);
            print_planet_info(&earth);
            print_planet_info(&moon);
        }
    }
    
    return 0;
}