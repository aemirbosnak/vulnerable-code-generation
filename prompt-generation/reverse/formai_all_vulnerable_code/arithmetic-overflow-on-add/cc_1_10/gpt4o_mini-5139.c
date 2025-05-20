//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_GALAXIES 5
#define MAX_DIST 100

typedef struct {
    char* name;
    int resources;
    int distance;
} Planet;

typedef struct {
    char* name;
    Planet planets[MAX_PLANETS];
    int planet_count;
} Galaxy;

void initialize_galaxy(Galaxy* galaxy, char* name) {
    galaxy->name = name;
    galaxy->planet_count = 0;
}

void add_planet(Galaxy* galaxy, char* planet_name, int resources, int distance) {
    if (galaxy->planet_count < MAX_PLANETS) {
        galaxy->planets[galaxy->planet_count].name = planet_name;
        galaxy->planets[galaxy->planet_count].resources = resources;
        galaxy->planets[galaxy->planet_count].distance = distance;
        galaxy->planet_count++;
    }
}

void print_galaxy_info(const Galaxy* galaxy) {
    printf("Galaxy: %s\n", galaxy->name);
    printf("Planets:\n");
    for (int i = 0; i < galaxy->planet_count; i++) {
        printf("  - %s: Resources: %d, Distance: %d light-years\n", 
            galaxy->planets[i].name, 
            galaxy->planets[i].resources, 
            galaxy->planets[i].distance);
    }
}

int explore_planet(Planet* planet) {
    srand(time(0));
    int outcome = rand() % 2; // Randomly decide if the exploration is a success (1) or a failure (0)

    if (outcome) {
        printf("Exploration of %s was successful! Found %d resources!\n", 
            planet->name, planet->resources);
        return planet->resources; // Return the resources found
    } else {
        printf("Exploration of %s failed! No resources found.\n", planet->name);
        return 0; // Return 0 resources found
    }
}

int main() {
    Galaxy galaxies[MAX_GALAXIES];
    initialize_galaxy(&galaxies[0], "Andromeda");
    add_planet(&galaxies[0], "Terra Nova", 50, 10);
    add_planet(&galaxies[0], "Aqua Planeta", 30, 20);
    add_planet(&galaxies[0], "Vulcanis", 20, 5);

    initialize_galaxy(&galaxies[1], "Milky Way");
    add_planet(&galaxies[1], "Mars III", 40, 15);
    add_planet(&galaxies[1], "Jupiter Vortex", 60, 25);

    // Print galaxy information
    for (int i = 0; i < 2; i++) {
        print_galaxy_info(&galaxies[i]);
    }

    // Explore planets
    int total_resources_found = 0;
    for (int i = 0; i < MAX_GALAXIES; i++) {
        for (int j = 0; j < galaxies[i].planet_count; j++) {
            total_resources_found += explore_planet(&galaxies[i].planets[j]);
        }
    }

    printf("Total resources found from all explorations: %d\n", total_resources_found);
    return 0;
}