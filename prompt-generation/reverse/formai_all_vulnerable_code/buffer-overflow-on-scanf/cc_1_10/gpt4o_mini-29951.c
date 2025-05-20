//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 20
#define MAX_SPACESHIPS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type[MAX_NAME_LENGTH];
    float distance; // in light-years
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float speed; // in light-years per year
} Spaceship;

void init_planets(Planet planets[]) {
    strcpy(planets[0].name, "Xeloria");
    strcpy(planets[0].type, "Gas Giant");
    planets[0].distance = 4.2;

    strcpy(planets[1].name, "Terra");
    strcpy(planets[1].type, "Rocky");
    planets[1].distance = 0.0; // Our home planet!

    strcpy(planets[2].name, "Zyphon");
    strcpy(planets[2].type, "Oceanic");
    planets[2].distance = 7.8;

    strcpy(planets[3].name, "Skylon");
    strcpy(planets[3].type, "Desert");
    planets[3].distance = 12.5;

    strcpy(planets[4].name, "Frozon");
    strcpy(planets[4].type, "Icy");
    planets[4].distance = 22.1;    
}

void init_spaceships(Spaceship spaceships[]) {
    strcpy(spaceships[0].name, "Starlight Cruiser");
    spaceships[0].speed = 1.5; // light-years per year

    strcpy(spaceships[1].name, "Galaxy Explorer");
    spaceships[1].speed = 2.3; // light-years per year

    strcpy(spaceships[2].name, "Nebula Challenger");
    spaceships[2].speed = 3.0; // light-years per year
}

void display_planets(Planet planets[]) {
    printf("=== Available Planets ===\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("Planet: %s | Type: %s | Distance: %.2f light-years\n",
               planets[i].name, planets[i].type, planets[i].distance);
    }
}

void display_spaceships(Spaceship spaceships[]) {
    printf("=== Available Spaceships ===\n");
    for (int i = 0; i < MAX_SPACESHIPS; i++) {
        printf("Spaceship: %s | Speed: %.2f light-years/year\n",
               spaceships[i].name, spaceships[i].speed);
    }
}

int calculate_travel_time(float distance, float speed) {
    return (int)(distance / speed);
}

void start_adventure() {
    Planet planets[MAX_PLANETS];
    Spaceship spaceships[MAX_SPACESHIPS];

    init_planets(planets);
    init_spaceships(spaceships);

    display_planets(planets);
    printf("\n");

    display_spaceships(spaceships);
    printf("\n");

    int chosen_planet, chosen_spaceship;
    printf("Choose a planet to explore (0-%d): ", MAX_PLANETS - 1);
    scanf("%d", &chosen_planet);
    printf("Choose a spaceship to travel with (0-%d): ", MAX_SPACESHIPS - 1);
    scanf("%d", &chosen_spaceship);

    if (chosen_planet < 0 || chosen_planet >= MAX_PLANETS ||
        chosen_spaceship < 0 || chosen_spaceship >= MAX_SPACESHIPS) {
        printf("Invalid selection! Adventure failed!\n");
        return;
    }

    float distance = planets[chosen_planet].distance;
    float speed = spaceships[chosen_spaceship].speed;

    int travel_time = calculate_travel_time(distance, speed);
    printf("Traveling to %s on the %s...\n", planets[chosen_planet].name, spaceships[chosen_spaceship].name);
    printf("Estimated travel time: %d years!\n", travel_time);

    printf("Liftoff! Time to engage warp drive!\n");

    // Simulate travel time
    for (int i = 0; i < travel_time; i++) {
        printf("Year %d: Breathtaking views of stars and planets!\n", i + 1);
        sleep(1); // simulating year passing (uncomment this line)
    }

    printf("You've arrived at %s!\n", planets[chosen_planet].name);
    printf("Prepare for an epic adventure on the surface!\n");
}

int main() {
    printf("Welcome to the Galactic Adventure Game!\n");
    printf("Strap in, space traveler! The universe awaits.\n");

    start_adventure();

    printf("Thank you for playing! Until next time, brave explorer!\n");
    return 0;
}