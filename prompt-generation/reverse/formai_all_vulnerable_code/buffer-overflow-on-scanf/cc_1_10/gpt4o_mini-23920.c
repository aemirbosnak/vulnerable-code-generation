//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_PLANETS 8
#define SOLAR_SYSTEM_SCALE 1000000 // for scaling purposes in output
#define TIME_STEP 1 // days

typedef struct {
    char name[20];
    double distance; // in km from sun
    double speed; // in km/day
    double angle; // current position in orbit
} Planet;

void initialize_planets(Planet planets[]) {
    Planet planet_data[NUM_PLANETS] = {
        {"Mercury", 57909176, 47.87},
        {"Venus", 108209284, 35.02},
        {"Earth", 149598262, 29.78},
        {"Mars", 227943824, 24.07},
        {"Jupiter", 778340821, 13.07},
        {"Saturn", 1426666422, 9.69},
        {"Uranus", 2870658186, 6.81},
        {"Neptune", 4498396441, 5.43},
    };

    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i] = planet_data[i];
        planets[i].angle = 0.0; // starting angle
    }
}

void update_orbit(Planet *planet) {
    planet->angle += (planet->speed / (2 * M_PI * planet->distance)) * TIME_STEP; // radians
    if (planet->angle > 2 * M_PI) {
        planet->angle -= 2 * M_PI; // wrap around the circle
    }
}

void display_solar_system(Planet planets[]) {
    printf("\nSolar System Simulation:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        double x = planets[i].distance * cos(planets[i].angle) / SOLAR_SYSTEM_SCALE;
        double y = planets[i].distance * sin(planets[i].angle) / SOLAR_SYSTEM_SCALE;

        printf("Planet: %-10s | Distance: %.2f km | Position: (%.2f, %.2f)\n", 
                planets[i].name, 
                planets[i].distance, 
                x, 
                y);
    }
    printf("\n");
}

void run_simulation(int days) {
    Planet planets[NUM_PLANETS];
    initialize_planets(planets);

    for (int day = 0; day < days; day += TIME_STEP) {
        update_orbit(&planets[0]);
        update_orbit(&planets[1]);
        update_orbit(&planets[2]);
        update_orbit(&planets[3]);
        update_orbit(&planets[4]);
        update_orbit(&planets[5]);
        update_orbit(&planets[6]);
        update_orbit(&planets[7]);

        display_solar_system(planets);
        usleep(500000); // wait for half a second to visualize
    }
}

int main() {
    int days_to_simulate;

    printf("Enter the number of days to simulate the solar system: ");
    scanf("%d", &days_to_simulate);

    run_simulation(days_to_simulate);

    return 0;
}