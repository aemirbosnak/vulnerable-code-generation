//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get user input for spaceship name
void getSpaceshipName(char *spaceshipName) {
    printf("Please enter your spaceship name: ");
    scanf("%s", spaceshipName);
}

// Function to randomly generate a planet's name from a list
void generatePlanetName(char *planetName) {
    srand(time(0));
    char *planetNames[] = {"Xerxes", "Terminus", "Niraxus", "Zalanthar", "Vulcan", "Thalassa", "Avalon", "Euphoria", "Centauri", "Krynn", "Solaris", "Galaxia"};
    int randomIndex = rand() % 12;
    strcpy(planetName, planetNames[randomIndex]);
}

// Function to randomly generate a spaceship crew size (between 1 and 10)
int generateCrewSize() {
    srand(time(0));
    int crewSize = rand() % 10 + 1;
    return crewSize;
}

// Function to get user input for spaceship fuel level
void getFuelLevel(float *fuelLevel) {
    printf("Please enter your fuel level (in gallons): ");
    scanf("%f", fuelLevel);
}

// Function to calculate distance between spaceship and planet (in millions of miles)
float calculateDistance() {
    srand(time(0));
    float distance = rand() % 10000 + 1000;
    return distance;
}

// Function to simulate spaceship travel, decreasing fuel level by 10 gallons per million miles traveled
void travel(float *fuelLevel, float distance) {
    *fuelLevel -= distance / 100;
}

int main() {
    char spaceshipName[20], planetName[20];
    int crewSize = generateCrewSize();
    float fuelLevel;
    getSpaceshipName(spaceshipName);
    generatePlanetName(planetName);
    getFuelLevel(&fuelLevel);
    float distance = calculateDistance();

    // Print spaceship and mission information
    printf("Welcome to the %s mission to explore planet %s with a crew of %d.\n", spaceshipName, planetName, crewSize);
    printf("Your current fuel level is %.2f gallons.\n", fuelLevel);
    printf("The distance to the planet is %.2f million miles.\n", distance);

    // Travel to planet and update fuel level
    travel(&fuelLevel, distance);

    // Check fuel level after travel
    if (fuelLevel <= 0) {
        printf("Mission failed! Your spaceship ran out of fuel and is lost in space.\n");
    } else {
        printf("Congratulations! You have successfully reached planet %s with %.2f gallons of fuel remaining.\n", planetName, fuelLevel);
    }

    return 0;
}