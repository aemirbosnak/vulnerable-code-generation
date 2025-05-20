//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11

typedef struct vector {
    double x;
    double y;
    double z;
} Vector;

typedef struct planet {
    char* name;
    double mass;
    Vector position;
    Vector velocity;
} Planet;

int main() {
    // define planets
    Planet earth = {"Earth", 5.972e24, {0, 0, 0}, {0, 0, 0}};
    Planet moon = {"Moon", 7.342e22, {384400000, 0, 0}, {0, 1022, 0}};
    
    // initialize simulation variables
    const double dt = 60; // timestep in seconds
    const double duration = 86400 * 365; // simulation duration in seconds
    const int num_steps = duration / dt; // number of simulation steps
    
    // run simulation
    for (int i = 0; i < num_steps; i++) {
        // calculate distance between planets
        Vector distance = {moon.position.x - earth.position.x,
                           moon.position.y - earth.position.y,
                           moon.position.z - earth.position.z};
        double d = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
        
        // calculate gravitational force between planets
        double f = G * earth.mass * moon.mass / pow(d, 2);
        
        // calculate gravitational acceleration
        Vector acceleration = {f / earth.mass * distance.x / d,
                               f / earth.mass * distance.y / d,
                               f / earth.mass * distance.z / d};
        
        // update velocity and position of moon
        moon.velocity.x -= acceleration.x * dt;
        moon.velocity.y -= acceleration.y * dt;
        moon.velocity.z -= acceleration.z * dt;
        moon.position.x += moon.velocity.x * dt;
        moon.position.y += moon.velocity.y * dt;
        moon.position.z += moon.velocity.z * dt;
        
        // print current position of moon
        printf("Step %d: Moon position = (%.0f, %.0f, %.0f)\n", i+1, moon.position.x, moon.position.y, moon.position.z);
    }
    
    return 0;
}