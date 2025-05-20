//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONSTANT 6.67430e-11 // gravitational constant

struct Body {
    double mass;
    double velocity_x;
    double velocity_y;
    double position_x;
    double position_y;
};

typedef struct Body Body;

void update_acceleration(Body *body, Body *other_body) {
    double distance = sqrt(pow((other_body->position_x - body->position_x), 2) 
                            + pow((other_body->position_y - body->position_y), 2));
    double force = (G_CONSTANT * body->mass * other_body->mass) / pow(distance, 2);
    double acceleration = force / body->mass;
    
    body->velocity_x += acceleration * ((other_body->position_x - body->position_x) / distance);
    body->velocity_y += acceleration * ((other_body->position_y - body->position_y) / distance);
}

void update_positions(Body *body) {
    body->position_x += body->velocity_x;
    body->position_y += body->velocity_y;
}

int main() {
    Body earth = {5.97e24, 0, 0, 1.5e11, 0};
    Body moon = {7.34e22, 0, 1022, 1.5e11 + 384400000, 0};
    Body mars = {6.39e23, 0, 0, 2.3e11, 0};
    Body planets[] = {earth, moon, mars};
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    double simulation_time = 86400 * 365.25; // 1 year simulation
    
    for (double time = 0; time < simulation_time; time += 86400) { // 1 day time step
        for (int i = 0; i < num_planets; i++) {
            for (int j = 0; j < num_planets; j++) {
                if (j != i) {
                    update_acceleration(&planets[i], &planets[j]);
                }
            }
        }
        for (int i = 0; i < num_planets; i++) {
            update_positions(&planets[i]);
        }
    }

    printf("Final positions:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%e, %e)\n", i+1, planets[i].position_x, planets[i].position_y);
    }

    return 0;
}