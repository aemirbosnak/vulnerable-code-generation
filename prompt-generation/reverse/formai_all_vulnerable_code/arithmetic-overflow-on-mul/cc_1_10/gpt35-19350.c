//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define G 6.67E-11 // Gravitational constant (m^3/kg s^2)
#define AU 1.5E11 // Astronomical Unit (m)
#define YEAR 31536000.0 // Length of year in seconds

// Define the properties of each planet
typedef struct planet {
    char name[10];
    double mass; // kg
    double radius; // m
    double position[3]; // m
    double velocity[3]; // m/s
} Planet;

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p2.position[0] - p1.position[0], 2) +
                pow(p2.position[1] - p1.position[1], 2) +
                pow(p2.position[2] - p1.position[2], 2));
}

// Function to calculate the gravitational force between two planets
double force(Planet p1, Planet p2) {
    return G * p1.mass * p2.mass / pow(distance(p1, p2), 2);
}

// Function to calculate the acceleration of a planet in the x,y,z directions
void acceleration(Planet* p1, Planet* p2) {
    double f = force(*p1, *p2);
    double dx = p2->position[0] - p1->position[0];
    double dy = p2->position[1] - p1->position[1];
    double dz = p2->position[2] - p1->position[2];
    double dr = distance(*p1, *p2);
    p1->velocity[0] += f * dx / (dr * p1->mass);
    p1->velocity[1] += f * dy / (dr * p1->mass);
    p1->velocity[2] += f * dz / (dr * p1->mass);
}

int main() {
    Planet sun = {"Sun", 1.989E30, 696340000.0, {0,0,0}, {0,0,0}};
    Planet earth = {"Earth", 5.972E24, 6371000.0, {0,AU,0}, {-29783.0,0,0}};
    Planet mars = {"Mars", 6.39E23, 3389500.0, {0,-1.5*AU,0}, {24130.0,0,0}};
    Planet venus = {"Venus", 4.867E24, 6051800.0, {0,-0.7*AU,0}, {35020.0,0,0}};

    Planet* planets[4] = {&earth, &mars, &venus};

    int t;
    printf("Enter the number of years you would like to simulate: ");
    scanf("%d", &t);

    // Simulate for t years
    for (int i = 0; i < t * 365; i++) {
        // Reset the acceleration of each planet to zero
        for (int j = 0; j < 3; j++) {
            planets[0]->velocity[j] = 0;
            planets[j+1]->velocity[j] = 0;
        }

        // Calculate the acceleration of each planet due to all other planets
        for (int j = 0; j < 3; j++) {
            for (int k = j+1; k < 3; k++) {
                acceleration(planets[j], planets[k]);
                acceleration(planets[k], planets[j]);
            }
            acceleration(planets[j], &sun);
        }
        acceleration(&sun, planets[0]);

        // Update the position of each planet based on its velocity and acceleration
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                planets[j]->position[k] += planets[j]->velocity[k] * YEAR;
            }
        }
    }

    // Output the final position of each planet
    printf("Final positions:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: (%e, %e, %e)\n", planets[i]->name, planets[i]->position[0], planets[i]->position[1], planets[i]->position[2]);
    }

    return 0;
}