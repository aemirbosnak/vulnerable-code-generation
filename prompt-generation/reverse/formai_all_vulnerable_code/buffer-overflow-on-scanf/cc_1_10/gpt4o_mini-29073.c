//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_RESOURCES 100
#define MAX_DISTANCE 10

typedef struct {
    int fuel;
    int food;
    int metals;
    int distanceTraveled;
} Starship;

void initializeStarship(Starship *ship) {
    ship->fuel = 50;
    ship->food = 50;
    ship->metals = 10;
    ship->distanceTraveled = 0;
}

void displayStatus(Starship *ship) {
    printf("\n--- Starship Status ---\n");
    printf("Fuel: %d\n", ship->fuel);
    printf("Food: %d\n", ship->food);
    printf("Metals: %d\n", ship->metals);
    printf("Distance Traveled: %d\n", ship->distanceTraveled);
    printf("---------------------\n");
}

void travel(Starship *ship) {
    int distance;
    printf("Enter distance to travel (1 to %d): ", MAX_DISTANCE);
    scanf("%d", &distance);
  
    if (distance < 1 || distance > MAX_DISTANCE) {
        printf("Invalid distance! You cannot travel that far.\n");
    } else if (ship->fuel < distance) {
        printf("Not enough fuel to travel that distance!\n");
    } else {
        ship->fuel -= distance;
        ship->distanceTraveled += distance;
        printf("Traveling %d distance units...\n", distance);
        ship->fuel -= distance;
        
        // Random event after travel
        int event = rand() % 3;
        switch (event) {
            case 0:
                printf("You found an asteroid field! Collecting metals.\n");
                ship->metals += rand() % 5 + 1; // Between 1 and 5
                break;
            case 1:
                printf("You encountered a space storm! Losing some food.\n");
                ship->food -= rand() % 5 + 1; // Between 1 and 5
                break;
            case 2:
                printf("You discovered a planet with resources!\n");
                ship->food += rand() % 10 + 1; // Between 1 and 10
                break;
        }
    }
}

void gatherResources(Starship *ship) {
    printf("Gathering resources...\n");
    ship->metals += rand() % 5 + 1; // Collect between 1 and 5 metals
    ship->food += rand() % 10 + 1; // Collect between 1 and 10 food items
    ship->fuel += rand() % 10 + 1; // Collect between 1 and 10 fuel units
}

int main() {
    srand(time(NULL));
    
    Starship ship;
    initializeStarship(&ship);
    
    int choice;
    while (1) {
        displayStatus(&ship);
        
        printf("Choose an action:\n");
        printf("1. Travel\n");
        printf("2. Gather Resources\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                travel(&ship);
                break;
            case 2:
                gatherResources(&ship);
                break;
            case 3:
                printf("Exiting the adventure. Safe travels!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        // Check if food or fuel is depleted
        if (ship.food <= 0) {
            printf("You have run out of food! Your crew has perished.\n");
            break;
        }
        if (ship.fuel <= 0) {
            printf("You have run out of fuel! The ship is stranded.\n");
            break;
        }
    }
    
    return 0;
}