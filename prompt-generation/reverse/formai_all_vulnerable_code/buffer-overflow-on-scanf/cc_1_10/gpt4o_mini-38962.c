//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLANETS 5
#define MAX_NAME_LENGTH 30
#define MAX_INFO_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char info[MAX_INFO_LENGTH];
    int resources;
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fuel;
    int cargo;
} Spaceship;

void display_planet_info(Planet *planet) {
    printf("\nPlanet: %s\n", planet->name);
    printf("Info: %s\n", planet->info);
    printf("Resources Available: %d\n", planet->resources);
}

void display_spaceship_info(Spaceship *ship) {
    printf("\nSpaceship: %s\n", ship->name);
    printf("Fuel Level: %d\n", ship->fuel);
    printf("Cargo Space: %d\n", ship->cargo);
}

void explore_planet(Spaceship *ship, Planet *planet) {
    if (ship->fuel < 10) {
        printf("Not enough fuel to explore %s!\n", planet->name);
        return;
    }

    ship->fuel -= 10;
    ship->cargo += planet->resources;
    planet->resources = 0;

    printf("Exploring %s...\n", planet->name);
    sleep(2); // Simulating exploration time
    printf("Found resources and collected them!\n");
}

void travel_to_planet(Spaceship *ship, Planet *planet) {
    if (ship->fuel < 20) {
        printf("Not enough fuel to travel to %s!\n", planet->name);
        return;
    }

    ship->fuel -= 20;
    printf("Traveling to %s...\n", planet->name);
    sleep(3); // Simulating travel time
    display_planet_info(planet);
}

void fuel_spaceship(Spaceship *ship) {
    ship->fuel += 30;
    printf("Fueling spaceship...\n");
    sleep(1); // Simulating fueling time
    printf("Fuel level increased to %d.\n", ship->fuel);
}

void display_menu() {
    printf("\n=== Space Adventure Menu ===\n");
    printf("1. View Spaceship Info\n");
    printf("2. Travel to a Planet\n");
    printf("3. Explore a Planet\n");
    printf("4. Fuel Spaceship\n");
    printf("5. Exit\n");
    printf("===========================\n");
}

int main() {
    Spaceship spaceship = {"Galactic Cruiser", 100, 0};
    Planet planets[MAX_PLANETS] = {
        {"Mars", "The Red Planet.", 50},
        {"Venus", "The Shiny Planet.", 30},
        {"Jupiter", "The Giant Planet.", 70},
        {"Saturn", "The Ringed Planet.", 40},
        {"Earth", "The Blue Planet.", 20}
    };

    int choice, planet_choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_spaceship_info(&spaceship);
                break;
            case 2:
                printf("Select a planet to travel to:\n");
                for (int i = 0; i < MAX_PLANETS; i++) {
                    printf("%d. %s\n", i + 1, planets[i].name);
                }
                printf("Enter your planet choice: ");
                scanf("%d", &planet_choice);
                if (planet_choice >= 1 && planet_choice <= MAX_PLANETS)
                    travel_to_planet(&spaceship, &planets[planet_choice - 1]);
                else
                    printf("Invalid choice. Please try again.\n");
                break;
            case 3:
                printf("Select a planet to explore:\n");
                for (int i = 0; i < MAX_PLANETS; i++) {
                    printf("%d. %s\n", i + 1, planets[i].name);
                }
                printf("Enter your planet choice: ");
                scanf("%d", &planet_choice);
                if (planet_choice >= 1 && planet_choice <= MAX_PLANETS)
                    explore_planet(&spaceship, &planets[planet_choice - 1]);
                else
                    printf("Invalid choice. Please try again.\n");
                break;
            case 4:
                fuel_spaceship(&spaceship);
                break;
            case 5:
                printf("Thank you for playing! Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}