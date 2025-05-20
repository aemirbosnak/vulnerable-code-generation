//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate planet names
char* generatePlanetName() {
    char* names[] = {"Aurelia", "Galaxia", "Nebulus", "Orionis", "Serenia", "Valkyria"};
    int numNames = 6;
    int index = rand() % numNames;
    return names[index];
}

// Function to randomly generate distance between planets
int generateDistance() {
    return (rand() % 100) + 1;
}

// Function to display planet details
void displayPlanet(char* planetName, int distance) {
    printf("You have landed on planet %s, which is %d light years away.\n", planetName, distance);
}

// Function to calculate travel time
int calculateTravelTime(int distance) {
    int speed = 10;
    int time = distance / speed;
    return time;
}

int main() {
    srand(time(0));
    int currentPlanet = 1; // Starting planet
    int totalPlanets = 5; // Total number of planets to visit
    int currentFuel = 50; // Starting fuel
    int totalFuel = 100; // Total fuel available
    int totalTravelTime = 0; // Total time taken to travel
    int gameOver = 0; // Flag to indicate game over

    printf("Welcome to the Procedural Space Adventure!\n");

    // Loop through the planets
    while (currentPlanet <= totalPlanets) {
        char* planetName = generatePlanetName();
        int distance = generateDistance();
        int travelTime = calculateTravelTime(distance);

        // Check if there is enough fuel to travel
        if (currentFuel >= distance) {
            // Display planet details
            displayPlanet(planetName, distance);
            // Update travel and fuel values
            totalTravelTime += travelTime;
            currentFuel -= distance;
            printf("You have traveled for %d light years and it took %d years.\n\n", distance, travelTime);
            // Move to the next planet
            currentPlanet++;
        } else {
            printf("You do not have enough fuel to travel to the next planet.\n");
            gameOver = 1;
            break;
        }

        // Check if all planets have been visited
        if (currentPlanet > totalPlanets) {
            printf("Congratulations! You have visited all planets in the galaxy!\n");
        } else {
            // Ask if the player wants to refuel
            char choice;
            printf("Do you want to refuel? (Y/N)\n");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                int refuelAmount = totalFuel - currentFuel;
                currentFuel = totalFuel;
                printf("You have refueled and gained %d fuel.\n\n", refuelAmount);
            }
        }
    }

    // Check if the game is over
    if (gameOver) {
        printf("Game over! You ran out of fuel before reaching all planets.\n");
    } else {
        // Display total travel time
        printf("Total travel time: %d years.\n", totalTravelTime);
    }

    return 0;
}