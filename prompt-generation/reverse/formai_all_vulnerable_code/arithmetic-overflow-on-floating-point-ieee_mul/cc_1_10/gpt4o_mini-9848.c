//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    double x; // x position
    double y; // y position
    double mass; // mass of the celestial body
} Body;

void initialize_body(Body *b, double x, double y, double mass) {
    b->x = x;
    b->y = y;
    b->mass = mass;
}

double distance(Body a, Body b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void print_position(Body b) {
    printf("Position of body with mass %.2f: (%.2f, %.2f)\n", b.mass, b.x, b.y);
}

void update_position(Body *b1, Body *b2, double dt) {
    double dist = distance(*b1, *b2);
    if (dist == 0) return; // Avoid division by zero

    // Gravitational force calculation
    double force = (G * b1->mass * b2->mass) / (dist * dist);
    
    // Acceleration of the first body
    double acceleration = force / b1->mass;

    // Direction from b1 to b2
    double dx = (b2->x - b1->x) / dist;
    double dy = (b2->y - b1->y) / dist;

    // Update the position based on the acceleration and direction
    b1->x += dx * acceleration * dt * dt;
    b1->y += dy * acceleration * dt * dt;
}

int main() {
    // Setting the stage for our celestial romance
    Body sun, planet;

    // Initialize the Sun - the steadfast lover
    initialize_body(&sun, 0.0, 0.0, 1.989e30); // Position at origin, mass of the Sun

    // Initialize a loving planet
    initialize_body(&planet, 1.496e11, 0.0, 5.972e24); // Earth's approx distance from Sun along x-axis

    // The romantic simulation begins
    double total_time = 3.154e7; // 1 year in seconds
    double dt = 86400; // 1 day in seconds

    printf("Year-long dance between Sun and Planet\n");
    for (double t = 0; t < total_time; t += dt) {
        print_position(planet); // Log the planet's position
        update_position(&planet, &sun, dt); // Move the planet a step closer to its destiny
    }

    printf("\nFinal position of beloved planet: \n");
    print_position(planet);

    printf("And thus, the cosmic journey of our star-crossed lovers continues...\n");

    return 0;
}