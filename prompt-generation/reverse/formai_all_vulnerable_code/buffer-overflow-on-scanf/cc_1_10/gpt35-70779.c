//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the game
#define NUM_PLANETS 10
#define MAX_DISTANCE 100
#define MIN_DISTANCE 10
#define MAX_RESOURCE 50
#define MIN_RESOURCE 5

// Define structures for the game
typedef struct planet {
    int planet_id;
    int distance;
    int resources;
} Planet;

typedef struct spaceship {
    int fuel;
    Planet current_planet;
} Spaceship;

// Declare global variables for the game
Planet planets[NUM_PLANETS];
Spaceship spaceship;

// Function to initialize the planets
void initialize_planets() {
    // Seed random number generator
    srand(time(NULL));
    
    // Loop through all the planets and initialize them
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].planet_id = i+1;
        planets[i].distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
        planets[i].resources = rand() % (MAX_RESOURCE - MIN_RESOURCE + 1) + MIN_RESOURCE;
    }
}

// Function to print all the planets
void print_planets() {
    printf("****************************\n");
    printf("*        PLANET LIST       *\n");
    printf("****************************\n");
    printf("ID   PLANET  DISTANCE  RESOURCES\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%-4d %-7s %-8d %-9d\n", planets[i].planet_id, "Planet", planets[i].distance, planets[i].resources);
    }
    printf("\n");
}

// Function to update the spaceship's current planet
void update_spaceship_planet(int planet_id) {
    spaceship.current_planet = planets[planet_id-1];
}

// Function to print spaceship status
void print_spaceship_status() {
    printf("****************************\n");
    printf("*      SPACESHIP STATUS    *\n");
    printf("****************************\n");
    printf("CURRENT PLANET: Planet %d\n", spaceship.current_planet.planet_id);
    printf("FUEL LEVEL: %d\n", spaceship.fuel);
    printf("\n");
}

// Function to travel to a new planet
void travel_to_planet(int planet_id) {
    int distance = planets[planet_id-1].distance;
    if (spaceship.fuel < distance) {
        printf("Not enough fuel to travel to Planet %d\n\n", planet_id);
        return;
    }
    
    spaceship.fuel -= distance;
    update_spaceship_planet(planet_id);
    printf("Traveled to Planet %d\n\n", planet_id);
}

// Function for the player to harvest resources
void harvest_resources() {
    int resources = spaceship.current_planet.resources;
    spaceship.fuel += resources;
    printf("Harvested %d resources from Planet %d\n\n", resources, spaceship.current_planet.planet_id);
}

// Function to handle player input
void handle_input(int choice) {
    switch (choice) {
        case 1:
            print_planets();
            break;
        case 2:
            travel_to_planet(2);
            break;
        case 3:
            harvest_resources();
            break;
        case 4:
            print_spaceship_status();
            break;
        case 5:
            printf("Exiting Space Adventure...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n\n");
    }
}

int main() {
    printf("******************************\n");
    printf("*    WELCOME TO SPACE ADVENTURE!    *\n");
    printf("******************************\n\n");
    
    // Initialize the game
    initialize_planets();
    spaceship.fuel = 50;
    update_spaceship_planet(1);
    
    // Loop for player input
    while (1) {
        printf("OPTIONS:\n");
        printf("1. View list of planets\n");
        printf("2. Travel to Planet 2\n");
        printf("3. Harvest resources on current planet\n");
        printf("4. Check spaceship status\n");
        printf("5. Quit game\n\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        handle_input(choice);
    }
    
    return 0;
}