//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
// Procedural Space Adventure example program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int currentPlanet = 1;
int currentFuel = 300;
int currentHealth = 100;

// Function prototypes
void travelToPlanet();
void refuel();
void repair();
void checkStatus();

int main() {
    // Seed random number generator
    srand(time(NULL));
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are currently on Planet %d.\n", currentPlanet);
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Refuel your ship\n");
        printf("3. Repair your ship\n");
        printf("4. Check status\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                travelToPlanet();
                break;
            case 2:
                refuel();
                break;
            case 3:
                repair();
                break;
            case 4:
                checkStatus();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to travel to a new random planet
void travelToPlanet() {
    int newPlanet = rand() % 10 + 1; // Generate random integer from 1 to 10
    if (newPlanet == currentPlanet) {
        printf("You are already on this planet!\n");
    } else {
        int distance = abs(newPlanet - currentPlanet) * 50; // Calculate distance in light-years
        if (distance > currentFuel) {
            printf("You do not have enough fuel to travel to Planet %d.\n", newPlanet);
        } else {
            currentPlanet = newPlanet;
            currentFuel -= distance;
            printf("You have traveled to Planet %d.\n", currentPlanet);
        }
    }
}

// Function to refuel the spaceship
void refuel() {
    int cost = 50 + (rand() % 50); // Generate random cost between 50 and 100 credits
    if (cost > currentFuel) {
        printf("You do not have enough credits to refuel your ship.\n");
    } else {
        currentFuel -= cost;
        printf("You have refueled your ship.\n");
    }
}

// Function to repair the spaceship
void repair() {
    int cost = 50 + (rand() % 50); // Generate random cost between 50 and 100 credits
    if (cost > currentHealth) {
        printf("You do not have enough health points to repair your ship.\n");
    } else {
        currentHealth -= cost;
        printf("You have repaired your ship.\n");
    }
}

// Function to check the status of the spaceship
void checkStatus() {
    printf("You are currently on Planet %d.\n", currentPlanet);
    printf("You have %d fuel units left.\n", currentFuel);
    printf("Your ship has %d health points remaining.\n", currentHealth);
}