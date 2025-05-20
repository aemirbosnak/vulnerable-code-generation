//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_THRUST 100
#define MAX_DISTANCE 1000
#define SPACESHIP_NAME_LENGTH 20

typedef struct {
    char name[SPACESHIP_NAME_LENGTH];
    int speed;
    int fuel;
    int distanceTravelled;
} Spaceship;

typedef struct {
    char name[20];
    int distanceFromEarth;
} Planet;

void initializeSpaceship(Spaceship* ship);
void displayMenu();
void travelToPlanet(Spaceship* ship, Planet* planet);
void refreshStatus(Spaceship* ship);
void displayPlanets(Planet* planets, int count);

int main() {
    srand(time(NULL));
    
    Spaceship spaceship;
    initializeSpaceship(&spaceship);

    Planet planets[MAX_PLANETS] = {
        {"Mars", 546},
        {"Jupiter", 778},
        {"Saturn", 1427},
        {"Venus", 261},
        {"Mercury", 91},
    };

    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayPlanets(planets, MAX_PLANETS);
            int planetChoice;
            printf("Enter the number of the planet you want to travel to: ");
            scanf("%d", &planetChoice);
            if (planetChoice > 0 && planetChoice <= MAX_PLANETS) {
                travelToPlanet(&spaceship, &planets[planetChoice - 1]);
            } else {
                printf("Invalid planet choice!\n");
            }
        } else if (choice == 2) {
            refreshStatus(&spaceship);
        } else if (choice == 3) {
            printf("Thank you for playing! Space adventure ended.\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void initializeSpaceship(Spaceship* ship) {
    printf("Enter the name of your spaceship: ");
    scanf("%s", ship->name);
    ship->speed = rand() % MAX_THRUST + 1; // Random speed between 1 and 100
    ship->fuel = MAX_THRUST; // Starting fuel is max thrust
    ship->distanceTravelled = 0;
    printf("Spaceship %s initialized with speed %d and fuel %d.\n", ship->name, ship->speed, ship->fuel);
}

void displayMenu() {
    printf("\n--- Space Adventure Menu ---\n");
    printf("1. Travel to a Planet\n");
    printf("2. Check Spaceship Status\n");
    printf("3. Exit\n");
}

void travelToPlanet(Spaceship* ship, Planet* planet) {
    printf("Traveling to %s, which is %d million kilometers away...\n", planet->name, planet->distanceFromEarth);
    
    if (ship->fuel <= 0) {
        printf("Insufficient fuel to make the journey!\n");
        return;
    }
    
    int travelTime = planet->distanceFromEarth / ship->speed; // Simple travel time estimation
    ship->distanceTravelled = planet->distanceFromEarth;

    if (travelTime > ship->fuel) {
        printf("Not enough fuel for the journey! Travel time is %d hours while you have %d hours of fuel.\n", travelTime, ship->fuel);
    } else {
        printf("Traveling...\n");
        for (int i = 0; i <= travelTime; i++) {
            printf("Hours elapsed: %d\n", i);
            sleep(1); // Simulate time passing for the travel
        }
        printf("Arrived at %s! Distance travelled: %d million kilometers.\n", planet->name, ship->distanceTravelled);
        ship->fuel -= travelTime; // Adjust fuel based on travel time
    }
}

void refreshStatus(Spaceship* ship) {
    printf("\n--- Spaceship Status ---\n");
    printf("Name: %s\n", ship->name);
    printf("Speed: %d km/h\n", ship->speed);
    printf("Remaining Fuel: %d\n", ship->fuel);
    printf("Distance Travelled: %d million kilometers\n", ship->distanceTravelled);
}

void displayPlanets(Planet* planets, int count) {
    printf("\n--- Available Planets ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (%d million kilometers away)\n", i + 1, planets[i].name, planets[i].distanceFromEarth);
    }
}