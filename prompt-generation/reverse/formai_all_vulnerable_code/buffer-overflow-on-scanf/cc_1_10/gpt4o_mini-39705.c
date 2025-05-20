//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CREW 5
#define SHIP_NAME_LENGTH 20
#define PLANET_NAME_LENGTH 20

typedef struct {
    char name[SHIP_NAME_LENGTH];
    char crew[MAX_CREW][SHIP_NAME_LENGTH];
    int crew_count;
    char current_planet[PLANET_NAME_LENGTH];
    int fuel;
} Spaceship;

// Function prototypes
void initialize_spaceship(Spaceship *ship);
void print_spaceship_info(const Spaceship *ship);
void land_on_planet(Spaceship *ship);
void refuel(Spaceship *ship);
void adventure(Spaceship *ship);
void show_shocking_event();

int main() {
    Spaceship ship;
    initialize_spaceship(&ship);

    int option;
    do {
        printf("\n=== Welcome to the Galactic Adventure ===\n");
        print_spaceship_info(&ship);
        printf("1. Land on a planet\n");
        printf("2. Refuel your spaceship\n");
        printf("3. Go on an adventure\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                land_on_planet(&ship);
                break;
            case 2:
                refuel(&ship);
                break;
            case 3:
                adventure(&ship);
                break;
            case 4:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 4);

    return 0;
}

void initialize_spaceship(Spaceship *ship) {
    printf("Enter the name of your spaceship: ");
    scanf("%s", ship->name);
    ship->crew_count = 0;
    strcpy(ship->current_planet, "Earth");
    ship->fuel = 100; // Starting fuel
    printf("Spaceship %s initialized!\n", ship->name);
}

void print_spaceship_info(const Spaceship *ship) {
    printf("Spaceship Name: %s\n", ship->name);
    printf("Current Planet: %s\n", ship->current_planet);
    printf("Fuel Level: %d%%\n", ship->fuel);
    printf("Crew Members (%d):\n", ship->crew_count);
    for (int i = 0; i < ship->crew_count; i++) {
        printf(" - %s\n", ship->crew[i]);
    }
}

void land_on_planet(Spaceship *ship) {
    if (ship->fuel < 10) {
        printf("Not enough fuel to land on a planet!\n");
        return;
    }

    char planet[PLANET_NAME_LENGTH];
    printf("Enter the name of the planet you wish to land on: ");
    scanf("%s", planet);
    strcpy(ship->current_planet, planet);
    ship->fuel -= 10; // Landing consumes fuel
    printf("Successfully landed on %s!\n", planet);
}

void refuel(Spaceship *ship) {
    printf("Refueling...\n");
    ship->fuel = 100; // Full refuel
    printf("The spaceship is now fully refueled!\n");
}

void adventure(Spaceship *ship) {
    if (ship->crew_count < 1) {
        printf("You need at least one crew member for an adventure!\n");
        return;
    }

    printf("Your crew embarks on a thrilling adventure on %s!\n", ship->current_planet);
    show_shocking_event();
}

void show_shocking_event() {
    const char *events[] = {
        "A mysterious space portal opens nearby!",
        "You encounter a fleet of alien ships!",
        "A gigantic asteroid field appears!",
        "You find an ancient alien artifact!",
        "Your spaceship is suddenly surrounded by space pirates!"
    };
    
    srand(time(0));
    int index = rand() % (sizeof(events) / sizeof(events[0]));
    printf("SHOCKING EVENT: %s\n", events[index]);
}