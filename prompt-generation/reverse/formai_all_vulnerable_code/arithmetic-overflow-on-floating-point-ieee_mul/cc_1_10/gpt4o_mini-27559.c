//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_PLANETS 8
#define SUN_GRAVITY 10.0 // Arbitrary gravity for the simulation
#define TIME_STEP 0.1    // Time step for the simulation
#define SCALE 10.0       // Scale for orbit display

struct Planet {
    char name[20];
    double distance; // Distance from the sun
    double speed;    // Orbital speed
    double angle;    // Current angle in orbit
};

void initialize_planets(struct Planet planets[NUM_PLANETS]) {
    snprintf(planets[0].name, sizeof(planets[0].name), "Mercury"); 
    planets[0].distance = 0.39;
    planets[0].speed = 47.87;

    snprintf(planets[1].name, sizeof(planets[1].name), "Venus");
    planets[1].distance = 0.72;
    planets[1].speed = 35.02;

    snprintf(planets[2].name, sizeof(planets[2].name), "Earth");
    planets[2].distance = 1.0;
    planets[2].speed = 29.78;

    snprintf(planets[3].name, sizeof(planets[3].name), "Mars");
    planets[3].distance = 1.52;
    planets[3].speed = 24.07;

    snprintf(planets[4].name, sizeof(planets[4].name), "Jupiter");
    planets[4].distance = 5.20;
    planets[4].speed = 13.07;

    snprintf(planets[5].name, sizeof(planets[5].name), "Saturn");
    planets[5].distance = 9.58;
    planets[5].speed = 9.69;

    snprintf(planets[6].name, sizeof(planets[6].name), "Uranus");
    planets[6].distance = 19.22;
    planets[6].speed = 6.81;

    snprintf(planets[7].name, sizeof(planets[7].name), "Neptune");
    planets[7].distance = 30.05;
    planets[7].speed = 5.43;
}

void update_planet_position(struct Planet* planet) {
    planet->angle += planet->speed * TIME_STEP;
    if (planet->angle >= 360.0) {
        planet->angle -= 360.0;
    }
}

void display_solar_system(struct Planet planets[NUM_PLANETS], int tick) {
    printf("\nTick: %d\n", tick);
    printf("Sun\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        double x = planets[i].distance * cos(planets[i].angle * M_PI / 180) * SCALE;
        double y = planets[i].distance * sin(planets[i].angle * M_PI / 180) * SCALE;
        printf("%s: (%f, %f)\n", planets[i].name, x, y);
    }
    printf("\n");
}

int main() {
    struct Planet planets[NUM_PLANETS];
    initialize_planets(planets);
    
    int total_ticks = 100; // Total simulation time
    for (int tick = 0; tick < total_ticks; tick++) {
        display_solar_system(planets, tick);
        for (int i = 0; i < NUM_PLANETS; i++) {
            update_planet_position(&planets[i]);
        }
        usleep(200000); // Sleep for 200 ms to slow down the simulation
    }
    
    return 0;
}