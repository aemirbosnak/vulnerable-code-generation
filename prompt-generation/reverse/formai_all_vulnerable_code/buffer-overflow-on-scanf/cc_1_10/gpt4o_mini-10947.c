//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Declarations
void welcome();
void displayStatus(int health, int fuel, int resources);
void exploreSpace(int *health, int *fuel, int *resources);
void encounterAlien(int *health, int *resources);
void gatherResources(int *resources, int *fuel);
void reportFinalStatus(int health, int fuel, int resources);

int main() {
    srand(time(NULL)); // Seed the random number generator.

    int health = 100;  // Player's health
    int fuel = 50;     // Player's fuel
    int resources = 0; // Player's resources

    welcome(); // Display the welcome message

    while (health > 0 && fuel > 0) {
        displayStatus(health, fuel, resources); // Show player status
        exploreSpace(&health, &fuel, &resources); // Explore space
    }

    reportFinalStatus(health, fuel, resources); // Final report of player status

    return 0;
}

void welcome() {
    printf("Welcome to the Galactic Exploration Program!\n");
    printf("You are a brave captain on a mission to explore the unknown depths of space.\n");
    printf("Beware of dangers lurking in the cosmos!\n\n");
}

void displayStatus(int health, int fuel, int resources) {
    printf("Current Status:\n");
    printf("Health: %d\n", health);
    printf("Fuel: %d\n", fuel);
    printf("Resources Collected: %d\n", resources);
    printf("---------------------------------------------------\n");
}

void exploreSpace(int *health, int *fuel, int *resources) {
    printf("You set out to explore the vicinity...\n");
    (*fuel)--; // Consuming fuel on exploration

    int event = rand() % 3; // Random event choice

    switch (event) {
        case 0:
            printf("You stumbled upon a rich asteroid field!\n");
            gatherResources(resources, fuel);
            break;
        case 1:
            printf("An alien ship appears on your radar!\n");
            encounterAlien(health, resources);
            break;
        case 2:
            printf("The area is quiet and uneventful. You continue your voyage.\n");
            break;
    }
}

void encounterAlien(int *health, int *resources) {
    printf("The aliens demand tribute!\n");

    int decision;
    printf("Choose an action: (1) Comply (2) Fight (3) Negotiate: ");
    scanf("%d", &decision);
    
    if (decision == 1) {
        printf("You comply and provide some resources.\n");
        *resources -= 10; // Lose some resources
        if (*resources < 0) *resources = 0; // Prevent negative resources
    } else if (decision == 2) {
        printf("You engage in battle!\n");
        int result = rand() % 2; // Random battle outcome
        if (result == 0) {
            printf("You defeated the aliens but took damage!\n");
            *health -= 25; // Decrease health
        } else {
            printf("You were overwhelmed! Your ship is damaged!\n");
            *health -= 50; // Major health loss if defeated
        }
    } else if (decision == 3) {
        printf("You successfully negotiated and gained some resources!\n");
        *resources += 15; // Gain resources
    } else {
        printf("Invalid choice! The aliens are angered!\n");
        *health -= 10; // Add penalty to health for invalid action
    }
}

void gatherResources(int *resources, int *fuel) {
    int foundResources = rand() % 20 + 10; // Random resources between 10 to 30
    printf("You gathered %d resources!\n", foundResources);
    *resources += foundResources; // Increase resources
}

void reportFinalStatus(int health, int fuel, int resources) {
    printf("\n***** Final Status *****\n");
    printf("Final Health: %d\n", health);
    printf("Final Fuel: %d\n", fuel);
    printf("Final Resources: %d\n", resources);
    if (health <= 0) {
        printf("You have perished in your cosmic journey...\n");
    } else if (fuel <= 0) {
        printf("Your fuel has run out. You are adrift in space...\n");
    } else {
        printf("Congratulations! You've survived the adventure!\n");
    }
    printf("Thank you for playing the Galactic Exploration Program!\n");
}