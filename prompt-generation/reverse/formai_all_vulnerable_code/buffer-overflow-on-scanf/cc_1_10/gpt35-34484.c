//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 10
#define G 6.67e-11
#define DELTA_T 1.0

// Planet struct definition
typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double ax, ay; // Acceleration
    double mass; // Mass
} Planet;

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

// Function to update velocity and position of a planet
void update_position(Planet *planet) {
    // Update velocity
    planet->vx += planet->ax * DELTA_T;
    planet->vy += planet->ay * DELTA_T;
    
    // Update position
    planet->x += planet->vx * DELTA_T;
    planet->y += planet->vy * DELTA_T;
}

// Function to update acceleration of a planet
void update_acceleration(Planet *planet, Planet *other_planets, int num_planets) {
    double fx = 0, fy = 0;
    
    for (int i = 0; i < num_planets; i++) {
        if (other_planets[i].x == planet->x && other_planets[i].y == planet->y) {
            continue;
        }
        
        double r = distance(planet->x, planet->y, other_planets[i].x, other_planets[i].y);
        double f = G * planet->mass * other_planets[i].mass / (r * r);
        double theta = atan2(other_planets[i].y-planet->y, other_planets[i].x-planet->x);
        
        fx += f * cos(theta);
        fy += f * sin(theta);
    }
    
    planet->ax = fx / planet->mass;
    planet->ay = fy / planet->mass;
}

// Main function
int main() {
    Planet planets[MAX_PLANETS];
    int num_planets;
    
    printf("Enter number of planets (max 10): ");
    scanf("%d", &num_planets);
    
    // Initialize planets
    for (int i = 0; i < num_planets; i++) {
        printf("Enter mass, x, y, vx, vy of planet %d: ", i+1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
        planets[i].ax = 0;
        planets[i].ay = 0;
    }
    
    // Simulation loop
    while (1) {
        // Update accelerations of all planets
        for (int i = 0; i < num_planets; i++) {
            update_acceleration(&planets[i], planets, num_planets);
        }
        
        // Update positions of all planets
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i]);
        }
        
        // Print positions of all planets
        for (int i = 0; i < num_planets; i++) {
            printf("%.2lf %.2lf ", planets[i].x, planets[i].y);
        }
        printf("\n");
    }
    
    return 0;
}