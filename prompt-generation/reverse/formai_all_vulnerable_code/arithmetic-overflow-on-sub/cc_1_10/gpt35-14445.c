//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANET_DISTANCE 100 // Maximum distance between planets
#define MAX_PLANET_RESOURCES 20 // Maximum resources in a planet
#define MAX_STARSHIPS 3 // Maximum number of starships the player can have

// Struct to store information about each planet
typedef struct {
    char name[20];
    int distance;
    int resources;
} Planet;

// Struct to store information about each starship
typedef struct {
    char name[20];
    int fuel;
    int resources;
    Planet current_planet;
} Starship;

// Function to simulate time passing and random events happening
void simulate_time() {
    int i, r;
    srand(time(NULL));
    for(i=0; i<4; i++) {
        r = rand() % 10;
        if(r < 5) { // 50% chance of finding resources
            printf("You found some resources!\n");
        } else if (r == 5) { // 10% chance of running out of fuel
            printf("You ran out of fuel and crashed into an asteroid!\n");
            exit(0);
        } else { // 40% chance of nothing happening
            printf("Nothing happened...\n");
        }
    }
}

int main() {

    int i, j, selected_starship, selected_planet;
    Planet planets[5] = {{"Earth", 0, 10}, {"Mars", 60, 5}, {"Jupiter", 85, 2}, {"Saturn", 90, 4}, {"Uranus", 100, 1}};
    Starship starships[MAX_STARSHIPS] = {{"Enterprise", 50, 0, planets[0]}, {"Voyager", 40, 0, planets[0]}, {"Millennium Falcon", 30, 0, planets[0]}};

    printf("Welcome to Procedural Space Adventure!\n\n");

    // Ask the user to select a starship
    printf("Please select a starship:\n");
    for(i=0; i<MAX_STARSHIPS; i++) {
        printf("%d. %s\n", i+1, starships[i].name);
    }
    scanf("%d", &selected_starship);
    selected_starship--;

    // Main game loop
    while(1) {
        printf("\nYou are currently on planet %s.\n", starships[selected_starship].current_planet.name);

        // Ask the user to select a planet to travel to
        printf("Please select a planet to travel to:\n");
        for(i=0; i<5; i++) {
            if(i != starships[selected_starship].current_planet.distance/MAX_PLANET_DISTANCE) { // The current planet is not an option
                printf("%d. %s (%d light years away, %d resources)\n", i+1, planets[i].name, planets[i].distance, planets[i].resources);
            }
        }
        scanf("%d", &selected_planet);
        selected_planet--;

        // Check if the selected planet is reachable
        if(selected_planet == starships[selected_starship].current_planet.distance/MAX_PLANET_DISTANCE) {
            printf("\nYou are already on this planet!\n");
        } else if(planets[selected_planet].distance > starships[selected_starship].fuel) {
            printf("\nYou don't have enough fuel to reach that planet!\n");
        } else {

            // Travel to the selected planet
            printf("\nTraveling to %s...\n", planets[selected_planet].name);
            simulate_time();
            printf("\nYou arrived at %s.\n", planets[selected_planet].name);

            // Collect resources from the selected planet
            starships[selected_starship].resources += planets[selected_planet].resources;
            planets[selected_planet].resources = 0;
            printf("You collected %d resources.\n", starships[selected_starship].resources);

            // Update the current planet of the selected starship
            starships[selected_starship].current_planet = planets[selected_planet];
        }

        // Check if the player has won or lost
        if(starships[selected_starship].resources >= 50) {
            printf("\nCongratulations, you have collected enough resources to save Earth!\n");
            break;
        } else if(starships[selected_starship].fuel <= 0) {
            printf("\nYou ran out of fuel and can't continue your journey...\n");
            break;
        }
    }
    return 0;
}