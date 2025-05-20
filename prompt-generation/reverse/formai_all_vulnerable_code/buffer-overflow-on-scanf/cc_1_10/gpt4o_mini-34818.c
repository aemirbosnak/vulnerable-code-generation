//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LEN 30
#define MAX_MESSAGE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int distance; // in light years
} Planet;

typedef struct {
    Planet planets[MAX_PLANETS];
    int planet_count;
} Galaxy;

void initialize_galaxy(Galaxy *galaxy) {
    strcpy(galaxy->planets[0].name, "Zyphoria");
    galaxy->planets[0].distance = 4;

    strcpy(galaxy->planets[1].name, "Kraglon");
    galaxy->planets[1].distance = 8;

    strcpy(galaxy->planets[2].name, "Mystara");
    galaxy->planets[2].distance = 12;

    strcpy(galaxy->planets[3].name, "Xelon");
    galaxy->planets[3].distance = 20;

    galaxy->planet_count = 4;
}

void display_planets(const Galaxy *galaxy) {
    printf("Welcome to the Galactic Explorer!\n");
    printf("We have discovered the following planets:\n");
    for (int i = 0; i < galaxy->planet_count; i++) {
        printf("%d: %s (Distance: %d light years)\n", i + 1, galaxy->planets[i].name, galaxy->planets[i].distance);
    }
}

void explore_planet(const Planet *planet) {
    printf("\nYou have decided to explore %s!\n", planet->name);
    printf("Upon arriving, you find:\n");
    // Randomly decide outcomes
    int event = rand() % 3;
    switch (event) {
        case 0:
            printf("You discover a hidden treasure chest filled with ancient artifacts!\n");
            break;
        case 1:
            printf("You encounter friendly alien lifeforms who offer to share their technology with you!\n");
            break;
        case 2:
            printf("A mysterious storm hits, and you must find shelter!\n");
            break;
    }
}

void space_adventure() {
    Galaxy galaxy;
    initialize_galaxy(&galaxy);
    
    srand(time(NULL)); // Seed randomness for exploration events

    int choice;
    do {
        display_planets(&galaxy);
        printf("Choose a planet to explore (1-%d, or 0 to exit): ", galaxy.planet_count);
        scanf("%d", &choice);
        if (choice > 0 && choice <= galaxy.planet_count) {
            explore_planet(&galaxy.planets[choice - 1]);
        } else if (choice != 0) {
            printf("Invalid choice! Please select a valid planet number.\n");
        }
    } while (choice != 0);

    printf("Thank you for exploring the galaxy with us! Safe travels!\n");
}

int main() {
    space_adventure();
    return 0;
}