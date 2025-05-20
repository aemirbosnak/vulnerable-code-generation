//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

struct Planet {
    char name[20];
    int distance;
    int atmosphere;
};

struct Spaceship {
    char type[20];
    int fuel;
    struct Planet currentPlanet;
};

void travel(struct Spaceship *ship, struct Planet planet) {
    if (planet.atmosphere == 0) {
        printf("The planet you selected has no atmosphere and is uninhabitable.\n");
    } else if (ship->fuel < planet.distance) {
        printf("You do not have enough fuel to travel to this planet. Refuel and try again.\n");
    } else {
        ship->fuel -= planet.distance;
        ship->currentPlanet = planet;
        printf("Traveling to %s...\n", planet.name);
        printf("You have arrived at %s!\n", planet.name);
    }
}

int main() {
    struct Planet planets[] = {
        {"Mars", 100, 1},
        {"Venus", 50, 1},
        {"Jupiter", 200, 0},
        {"Saturn", 175, 0},
        {"Uranus", 250, 1}
    };
    struct Spaceship ship = {"Explorer", 1000, planets[0]};
    printf("Welcome, Detective Holmes. You have been selected to lead a space mission to investigate a series of mysterious disappearances in the outer regions of the galaxy.\n");
    printf("Your ship, the %s, is currently located on %s.\n", ship.type, ship.currentPlanet.name);
    printf("You have %d units of fuel, which is enough to travel up to %d units.\n", ship.fuel, ship.fuel);
    printf("Here are the destinations we have identified so far:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s (Distance: %d units, Atmosphere: %s)\n", i+1, planets[i].name, planets[i].distance, planets[i].atmosphere == 1 ? "Breathable" : "Uninhabitable");
    }
    int choice;
    do {
        printf("Which planet would you like to travel to? Enter a number between 1 and 5, or enter 0 to exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("Goodbye, Detective Holmes.\n");
                break;
            case 1:
                travel(&ship, planets[0]);
                break;
            case 2:
                travel(&ship, planets[1]);
                break;
            case 3:
                travel(&ship, planets[2]);
                break;
            case 4:
                travel(&ship, planets[3]);
                break;
            case 5:
                travel(&ship, planets[4]);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}