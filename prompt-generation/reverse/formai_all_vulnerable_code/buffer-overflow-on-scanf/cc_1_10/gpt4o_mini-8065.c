//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLANETS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float distanceFromSun; // in millions of kilometers
    float size;            // in kilometers
} Planet;

void printPlanetInfo(Planet planet) {
    printf("Planet: %s\n", planet.name);
    printf("Distance from Sun: %.2f million km\n", planet.distanceFromSun);
    printf("Size: %.2f km\n", planet.size);
    printf("------------------------------\n");
}

void displaySolarSystem(Planet solarSystem[], int planetCount) {
    printf("Welcome to the Solar System Simulation!\n");
    printf("Here are the planets:\n");
    printf("------------------------------\n");
    for (int i = 0; i < planetCount; i++) {
        printPlanetInfo(solarSystem[i]);
    }
}

void addPlanet(Planet solarSystem[], int *planetCount, const char *name, 
               float distanceFromSun, float size) {
    if (*planetCount < MAX_PLANETS) {
        strcpy(solarSystem[*planetCount].name, name);
        solarSystem[*planetCount].distanceFromSun = distanceFromSun;
        solarSystem[*planetCount].size = size;
        (*planetCount)++;
    } else {
        printf("Maximum number of planets reached!\n");
    }
}

int main() {
    Planet solarSystem[MAX_PLANETS];
    int planetCount = 0;

    // Adding planets
    addPlanet(solarSystem, &planetCount, "Mercury", 57.91, 2439.7);
    addPlanet(solarSystem, &planetCount, "Venus", 108.2, 6051.8);
    addPlanet(solarSystem, &planetCount, "Earth", 149.6, 6371.0);
    addPlanet(solarSystem, &planetCount, "Mars", 227.9, 3389.5);
    addPlanet(solarSystem, &planetCount, "Jupiter", 778.3, 69911.0);
    addPlanet(solarSystem, &planetCount, "Saturn", 1427.0, 58232.0);
    addPlanet(solarSystem, &planetCount, "Uranus", 2871.0, 25362.0);
    addPlanet(solarSystem, &planetCount, "Neptune", 4497.1, 24622.0);
    
    // Display solar system
    displaySolarSystem(solarSystem, planetCount);

    // Interactive loop
    while (1) {
        int choice;
        printf("Enter the number of the planet to view details (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the simulation. Goodbye!\n");
            break;
        } else if (choice > 0 && choice <= planetCount) {
            printPlanetInfo(solarSystem[choice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
        sleep(1); // Adding a brief delay before the next prompt
    }

    return 0;
}