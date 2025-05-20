//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265

// Constants for the physics simulation
const double G = 6.674e-11; // Gravitational constant in m^3 kg^-1 s^-2
const double dt = 0.001; // Time step in seconds

// Structure to represent a celestial body
typedef struct {
    double mass;     // Mass in kilograms
    double x;        // X-coordinate in meters
    double y;        // Y-coordinate in meters    
} Body;

// Array of celestial bodies
Body bodies[100];

// Number of celestial bodies
int num_bodies;

// Function to calculate the gravitational force between two bodies
void calc_force(Body *body1, Body *body2, double *fx, double *fy)
{
    // Calculate the distance between the bodies
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double r = sqrt(dx * dx + dy * dy);

    // Calculate the force between the bodies
    *fx = G * body1->mass * body2->mass * dx / (r * r * r);
    *fy = G * body1->mass * body2->mass * dy / (r * r * r);
}

// Function to update the positions and velocities of the bodies
void update(void)
{
    // Calculate the forces between all pairs of bodies
    for (int i = 0; i < num_bodies; i++) {
        for (int j = i + 1; j < num_bodies; j++) {
            double fx, fy;
            calc_force(&bodies[i], &bodies[j], &fx, &fy);
            bodies[i].x += fx * dt;
            bodies[i].y += fy * dt;
            bodies[j].x -= fx * dt;
            bodies[j].y -= fy * dt;
        }
    }
}

// Main function
int main(int argc, char **argv)
{
    // Check for the number of arguments
    if (argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: could not open input file %s\n", argv[1]);
        return 1;
    }

    // Read the number of bodies from the input file
    fscanf(input, "%d", &num_bodies);

    // Read the properties of each body from the input file
    for (int i = 0; i < num_bodies; i++) {
        fscanf(input, "%lf %lf %lf", &bodies[i].mass, &bodies[i].x, &bodies[i].y);
    }

    // Close the input file
    fclose(input);

    // Run the simulation for a specified number of time steps
    for (int i = 0; i < 10000; i++) {
        update();
    }

    // Print the final positions of the bodies to the standard output
    for (int i = 0; i < num_bodies; i++) {
        printf("%lf %lf\n", bodies[i].x, bodies[i].y);
    }

    return 0;
}