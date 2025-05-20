//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: brave
// Welcome to the Solar System simulation program!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.67430e-11 // gravitational constant

// structure for planets
typedef struct {
    char name[20];
    double mass; 
    double radius;
    double x;
    double y;
    double vx;
    double vy;
} planet;

// function to calculate force exerted on a planet by another planet
void calculateForce(planet* p1, planet* p2) {
    double x_diff = p2->x - p1->x;
    double y_diff = p2->y - p1->y;
    double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    double force = (G * p1->mass * p2->mass) / (pow(distance, 2));
    double x_force = (force / distance) * x_diff;
    double y_force = (force / distance) * y_diff;
    p1->vx += x_force / p1->mass;
    p1->vy += y_force / p1->mass;
}

int main() {
    // create array of planets
    planet planets[8] = {
        {"Sun", 1.9885e+30, 696340000, 0, 0, 0, 0},
        {"Mercury", 3.283e+23, 2439700, 57909072311, 0, 0, 47870},
        {"Venus", 4.867e+24, 6051800, 108208930000, 0, 0, 35020},
        {"Earth", 5.97e+24, 6371000, 147098291000, 0, 0, 29783},
        {"Mars", 6.39e+23, 3389500, 227943824000, 0, 0, 24140},
        {"Jupiter", 1.898e+27, 71492000, 778340821000, 0, 0, 13170},
        {"Saturn", 5.683e+26, 60268000, 1426666422000, 0, 0, 9644},
        {"Uranus", 8.681e+25, 25559000, 2870658186000, 0, 0, 6798},
    };
    int time = 0; // starting time
    
    // loop through time
    while (time < 365 * 24 * 60 * 60 * 5) { // simulate for 5 years
        // loop through planets
        for (int i = 0; i < 8; i++) {
            // calculate force on planet due to other planets
            for (int j = 0; j < 8; j++) {
                if (j != i) {
                    calculateForce(&planets[i], &planets[j]);
                }
            }
            // update position of planet
            planets[i].x += planets[i].vx * 60 * 60 * 24; // convert to km/s to km/day
            planets[i].y += planets[i].vy * 60 * 60 * 24; // convert to km/s to km/day
        }
        time += 60 * 60 * 24; // increment time by 1 day
    }

    // print final positions of planets
    for (int i = 0; i < 8; i++) {
        printf("%s: (%.4f, %.4f)\n", planets[i].name, planets[i].x, planets[i].y);
    }

    return 0;
}