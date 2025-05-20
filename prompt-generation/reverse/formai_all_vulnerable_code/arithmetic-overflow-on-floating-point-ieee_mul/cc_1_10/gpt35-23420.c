//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.674e-11 // m^3 kg^-1 s^-2
#define TIME_INTERVAL 1 // s
#define SIMULATION_TIME 100 // s
#define NUM_PLANETS 2

struct Planet {
    double mass; // kg
    double radius; // m
    double position[3]; // m
    double velocity[3]; // m s^-1
    double acceleration[3]; // m s^-2
};

void calculate_gravitational_force(struct Planet *planet1, struct Planet *planet2, double *force) {
    double distance = sqrt(pow(planet2->position[0] - planet1->position[0], 2) + pow(planet2->position[1] - planet1->position[1], 2) + pow(planet2->position[2] - planet1->position[2], 2));
    double force_magnitude = GRAVITATIONAL_CONSTANT * planet1->mass * planet2->mass / pow(distance, 2);
    force[0] = force_magnitude * (planet2->position[0] - planet1->position[0]) / distance;
    force[1] = force_magnitude * (planet2->position[1] - planet1->position[1]) / distance;
    force[2] = force_magnitude * (planet2->position[2] - planet1->position[2]) / distance;
}

void update_planet(struct Planet *planet) {
    planet->position[0] += planet->velocity[0] * TIME_INTERVAL + 0.5 * planet->acceleration[0] * pow(TIME_INTERVAL, 2);
    planet->position[1] += planet->velocity[1] * TIME_INTERVAL + 0.5 * planet->acceleration[1] * pow(TIME_INTERVAL, 2);
    planet->position[2] += planet->velocity[2] * TIME_INTERVAL + 0.5 * planet->acceleration[2] * pow(TIME_INTERVAL, 2);
    planet->velocity[0] += planet->acceleration[0] * TIME_INTERVAL;
    planet->velocity[1] += planet->acceleration[1] * TIME_INTERVAL;
    planet->velocity[2] += planet->acceleration[2] * TIME_INTERVAL;
}

int main() {
    struct Planet planets[NUM_PLANETS] = {{5.97e24, 6.38e6, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, // Earth
                                          {7.35e22, 1.74e6, {3.84e8, 0, 0}, {0, 1022, 0}, {0, 0, 0}}}; // Moon
    double force[3];
    
    for (int i = 0; i < SIMULATION_TIME / TIME_INTERVAL; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            planets[j].acceleration[0] = 0;
            planets[j].acceleration[1] = 0;
            planets[j].acceleration[2] = 0;
            for (int k = 0; k < NUM_PLANETS; k++) {
                if (j != k) {
                    calculate_gravitational_force(&planets[j], &planets[k], force);
                    planets[j].acceleration[0] += force[0] / planets[j].mass;
                    planets[j].acceleration[1] += force[1] / planets[j].mass;
                    planets[j].acceleration[2] += force[2] / planets[j].mass;
                }
            }
            update_planet(&planets[j]);
        }
    }
    
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: x=%f m, y=%f m, z=%f m, vx=%f m/s, vy=%f m/s, vz=%f m/s\n", i+1, 
               planets[i].position[0], planets[i].position[1], planets[i].position[2],
               planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
    }
    
    return 0;
}