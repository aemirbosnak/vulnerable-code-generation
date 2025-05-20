//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int distance; // Distance from the start point
    int resources; // Resource level on the planet
} Planet;

typedef struct {
    Planet planets[MAX_PLANETS];
    int count;
} Galaxy;

typedef struct {
    char name[MAX_NAME_LEN];
    int resources;
    int distanceTraveled;
} Spaceship;

void initializeGalaxy(Galaxy* galaxy) {
    srand(time(0));
    galaxy->count = rand() % 10 + 5; // Generate between 5 to 15 planets

    for (int i = 0; i < galaxy->count; i++) {
        snprintf(galaxy->planets[i].name, MAX_NAME_LEN, "Planet_%d", i + 1);
        galaxy->planets[i].distance = rand() % 100; // Generate random distance
        galaxy->planets[i].resources = rand() % 100; // Generate random resources
    }
}

void displayPlanets(Galaxy* galaxy) {
    printf("Available Planets:\n");
    for (int i = 0; i < galaxy->count; i++) {
        printf("%s - Distance: %d, Resources: %d\n", 
               galaxy->planets[i].name, 
               galaxy->planets[i].distance, 
               galaxy->planets[i].resources);
    }
}

void travelToPlanet(Spaceship* spaceship, Planet* planet) {
    spaceship->distanceTraveled += planet->distance;
    spaceship->resources += planet->resources;
    printf("Traveling to %s...\n", planet->name);
    printf("Arrived at %s! Resources collected: %d\n", planet->name, planet->resources);
    printf("Total resources: %d, Distance traveled: %d\n", spaceship->resources, spaceship->distanceTraveled);
}

int main() {
    Galaxy galaxy;
    Spaceship spaceship;
    spaceship.resources = 0;
    spaceship.distanceTraveled = 0;

    printf("Enter spaceship name: ");
    fgets(spaceship.name, MAX_NAME_LEN, stdin);
    strtok(spaceship.name, "\n"); // Remove newline character

    initializeGalaxy(&galaxy);
    displayPlanets(&galaxy);

    int choice;
    while (1) {
        printf("Choose a planet to travel to (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice > galaxy.count || choice < 1) {
            printf("Invalid choice. Please try again.\n");
        } else {
            travelToPlanet(&spaceship, &galaxy.planets[choice - 1]);
        }
    }

    printf("Thank you for playing, %s! Total resources: %d, Total distance traveled: %d\n",
           spaceship.name, spaceship.resources, spaceship.distanceTraveled);
    return 0;
}