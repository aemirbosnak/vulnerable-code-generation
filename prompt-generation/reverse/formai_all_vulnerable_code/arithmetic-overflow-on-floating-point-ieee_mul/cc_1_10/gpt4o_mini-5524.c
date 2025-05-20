//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.67430e-11  // gravitational constant
#define PI 3.14159265

typedef struct {
    char name[20];
    double mass;      // in kg
    double radius;    // in meters
    double x;         // position in x-axis
    double y;         // position in y-axis
    double vx;        // velocity in x-direction
    double vy;        // velocity in y-direction
} Planet;

void initialize_planet(Planet* p, const char* name, double mass, double radius, double x, double y, double vx, double vy) {
    snprintf(p->name, sizeof(p->name), "%s", name);
    p->mass = mass;
    p->radius = radius;
    p->x = x;
    p->y = y;
    p->vx = vx;
    p->vy = vy;
}

double calculate_gravitational_force(Planet* p1, Planet* p2) {
    double distance = sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
    if (distance == 0) return 0; // Prevent division by zero
    return (G * p1->mass * p2->mass) / (distance * distance);
}

void update_velocities(Planet* p1, Planet* p2, double dt) {
    double force = calculate_gravitational_force(p1, p2);
    
    // Unit vector in the direction of the force
    double distance_x = p2->x - p1->x;
    double distance_y = p2->y - p1->y;
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    
    if (distance == 0) return; // Avoid update if planets occupy the same space
    
    double ax = (force / p1->mass) * (distance_x / distance);
    double ay = (force / p1->mass) * (distance_y / distance);
    
    p1->vx += ax * dt;
    p1->vy += ay * dt;

    ax = (force / p2->mass) * (-distance_x / distance);
    ay = (force / p2->mass) * (-distance_y / distance);

    p2->vx += ax * dt;
    p2->vy += ay * dt;
}

void update_positions(Planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void print_planet_state(const Planet* p, double time) {
    printf("Time: %.2f s | Planet: %s | Position: (%.2f, %.2f) | Velocity: (%.2f, %.2f)\n",
           time, p->name, p->x, p->y, p->vx, p->vy);
}

int main() {
    Planet planets[2];

    initialize_planet(&planets[0], "Earth", 5.972e24, 6.371e6, 0, 0, 0, 0);
    initialize_planet(&planets[1], "Moon", 7.348e22, 1.737e6, 3.844e8, 0, 0, 1022); // Moon at a distance

    double total_time = 3600; // Simulate for 1 hour
    double dt = 5;            // Time step of 5 seconds
    double time = 0;

    while (time <= total_time) {
        update_velocities(&planets[0], &planets[1], dt);
        update_positions(&planets[0], dt);
        update_positions(&planets[1], dt);
        
        print_planet_state(&planets[0], time);
        print_planet_state(&planets[1], time);
        
        time += dt;
        printf("\n");
    }

    return 0;
}