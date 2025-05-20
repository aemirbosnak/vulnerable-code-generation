//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PLANET_COUNT 8

typedef struct {
    char name[20];
    char emoji[10];
    float distanceFromSun; // in million km
    float speed; // in km/h
    int moons; // number of moons
} Planet;

void displayPlanet(Planet planet) {
    printf("🌌 Planet %s %s\n", planet.name, planet.emoji);
    printf("  Distance from Sun: %.2f million km\n", planet.distanceFromSun);
    printf("  Orbiting Speed: %.2f km/h\n", planet.speed);
    printf("  Number of Moons: %d\n", planet.moons);
    printf("  -----------------------------------\n");
}

void simulateOrbit(Planet planet) {
    printf("🚀 Simulating orbit for %s...\n", planet.name);
    for (int i = 0; i < 5; i++) {
        printf("  %s is zooming around the sun at %.2f km/h! 🌞\n", planet.name, planet.speed);
        sleep(1);
    }
}

int main() {
    Planet solarSystem[PLANET_COUNT] = {
        {"Mercury", "☿️", 57.91, 47474, 0},
        {"Venus", "♀️", 108.21, 35020, 0},
        {"Earth", "🌍", 149.6, 1670, 1},
        {"Mars", "♂️", 227.92, 86800, 2},
        {"Jupiter", "♃", 778.57, 43200, 79},
        {"Saturn", "♅", 1433.5, 34300, 83},
        {"Uranus", "♆", 2872.5, 24100, 27},
        {"Neptune", "♇", 4495.1, 21000, 14}
    };

    printf("🔭 Welcome to the Solar System Simulator! 🌌\n");
    printf("===========================================\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        displayPlanet(solarSystem[i]);
    }

    printf("🪐 Are you ready to simulate the orbits? (yes/no): ");
    char response[10];
    scanf("%s", response);

    if (strcmp(response, "yes") == 0) {
        printf("🚀 Let's blast off!\n");
        for (int i = 0; i < PLANET_COUNT; i++) {
            simulateOrbit(solarSystem[i]);
        }
        printf("🌌 All planets have successfully completed their orbit simulation!\n");
    } else {
        printf("😴 Sleeping is also a valid choice. Goodnight!\n");
    }

    printf("🛸 Thanks for visiting the Solar System Simulator! 🚀\n");
    return 0;
}