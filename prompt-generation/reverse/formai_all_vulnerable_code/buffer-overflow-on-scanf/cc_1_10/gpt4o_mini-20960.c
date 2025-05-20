//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the game
#define MAX_FUEL 100
#define MAX_HEALTH 100
#define MAX_FOOD 100
#define SPACE_EVENTS 3
#define EVENT_FUEL 1
#define EVENT_HEALTH 2
#define EVENT_FOOD 3

// Structure to hold the player's ship status
typedef struct {
    int fuel;
    int health;
    int food;
} Ship;

// Function declarations
void displayStatus(Ship ship);
void exploreSpace(Ship* ship);
void encounterEvent(Ship* ship);
void refuel(Ship* ship);
void findSupplies(Ship* ship);
void healShip(Ship* ship);

int main() {
    Ship playerShip = {MAX_FUEL, MAX_HEALTH, MAX_FOOD};
    char choice;

    printf("Welcome to the Space Adventure Game!\n");
    printf("Your ship is ready. Let's explore the universe!\n");
    
    while (1) {
        displayStatus(playerShip);
        printf("Do you want to (e)xplore space or (q)uit? ");
        scanf(" %c", &choice);
        
        if (choice == 'e') {
            exploreSpace(&playerShip);
        } else if (choice == 'q') {
            printf("Thank you for playing! Safe travels!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
        if (playerShip.fuel <= 0) {
            printf("You have run out of fuel! You drift into the void of space...\n");
            break;
        }
        if (playerShip.health <= 0) {
            printf("Your ship has suffered too much damage and is now uninhabitable.\n");
            break;
        }
        if (playerShip.food <= 0) {
            printf("You have run out of food and can no longer sustain your crew.\n");
            break;
        }
    }
    
    return 0;
}

void displayStatus(Ship ship) {
    printf("\n--- Ship Status ---\n");
    printf("Fuel: %d/%d\n", ship.fuel, MAX_FUEL);
    printf("Health: %d/%d\n", ship.health, MAX_HEALTH);
    printf("Food: %d/%d\n", ship.food, MAX_FOOD);
    printf("--------------------\n");
}

void exploreSpace(Ship* ship) {
    ship->fuel -= 10; // Fuel cost for exploring
    printf("You are exploring the great expanse of space...\n");

    encounterEvent(ship);
}

void encounterEvent(Ship* ship) {
    srand(time(NULL)); // Seed random number generator
    int event = rand() % SPACE_EVENTS + 1;

    switch (event) {
        case EVENT_FUEL:
            printf("You found a fuel depot!\n");
            refuel(ship);
            break;
        case EVENT_HEALTH:
            printf("You came across a space doctor who offers to fix your ship!\n");
            healShip(ship);
            break;
        case EVENT_FOOD:
            printf("You discovered a supply cache stocked with food!\n");
            findSupplies(ship);
            break;
    }
}

void refuel(Ship* ship) {
    ship->fuel += 50;
    if (ship->fuel > MAX_FUEL) {
        ship->fuel = MAX_FUEL;
    }
    printf("Your fuel is now at %d/%d.\n", ship->fuel, MAX_FUEL);
}

void healShip(Ship* ship) {
    ship->health += 30;
    if (ship->health > MAX_HEALTH) {
        ship->health = MAX_HEALTH;
    }
    printf("Your ship's health is now at %d/%d.\n", ship->health, MAX_HEALTH);
}

void findSupplies(Ship* ship) {
    ship->food += 40;
    if (ship->food > MAX_FOOD) {
        ship->food = MAX_FOOD;
    }
    printf("You now have %d/%d units of food.\n", ship->food, MAX_FOOD);
}