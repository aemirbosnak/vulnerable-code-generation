//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

// Structure to represent a planet
typedef struct {
    char name[20];
    double mass;   // in kg
    double pos_x;  // x position in meters
    double pos_y;  // y position in meters
} Planet;

// Function to calculate the distance between two planets
double calculate_distance(Planet p1, Planet p2) {
    double distance = sqrt(pow(p2.pos_x - p1.pos_x, 2) + pow(p2.pos_y - p1.pos_y, 2));
    return distance;
}

// Function to calculate gravitational force between two planets
double calculate_gravitational_force(Planet p1, Planet p2) {
    double distance = calculate_distance(p1, p2);
    if (distance == 0) {
        return 0; // Avoid division by zero
    }
    return (G * p1.mass * p2.mass) / (distance * distance);
}

// Function to display the planet details
void display_planet_info(Planet p) {
    printf("Planet Name: %s\n", p.name);
    printf("Mass: %.2e kg\n", p.mass);
    printf("Position: (%.2f m, %.2f m)\n", p.pos_x, p.pos_y);
}

int main() {
    // Create two planets
    Planet earth = {"Earth", 5.972e24, 0.0, 0.0};
    Planet moon = {"Moon", 7.348e22, 384400000.0, 0.0}; // Distance from Earth to Moon

    // Display planet information
    printf("Planet Information:\n");
    display_planet_info(earth);
    printf("\n");
    display_planet_info(moon);
    printf("\n");

    // Calculate and display the gravitational force
    double force = calculate_gravitational_force(earth, moon);
    printf("Gravitational Force between %s and %s: %.2e N\n", earth.name, moon.name, force);

    // Simulate dynamics (Optional, for future consideration)
    printf("\nSimulation of gravitational attraction will be shown below:\n");
    // For simplicity, assume a time step of 1 second
    double time_step = 1.0; 
    double velocity_x = 0.0; // Initial velocity in x
    double velocity_y = 0.0; // Initial velocity in y

    for (int i = 0; i < 10; i++) { // Simulate for 10 seconds
        // Update position based on the gravitational force acting on the moon
        double force_on_moon = calculate_gravitational_force(earth, moon);
        double acceleration = force_on_moon / moon.mass; // F = ma => a = F/m

        // Update velocities based on acceleration
        velocity_x += acceleration * time_step; // only effect in x-direction for this example
        velocity_y += 0; // no y-direction movement in this simple example

        moon.pos_x += velocity_x * time_step; // Update position

        // Display updated positions for each time step
        printf("Time: %d s, Moon Position: (%.2f m, %.2f m)\n", i + 1, moon.pos_x, moon.pos_y);
    }

    return 0;
}