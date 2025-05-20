//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of planets
#define MAX_PLANETS 10

// Define the structure for a planet
typedef struct {
    char name[20];
    int distance;
    int resources;
} Planet;

// Function to generate a random name for a planet
void generateName(char* name) {
    int i;
    for (i = 0; i < 20; i++) {
        name[i] = 'a' + rand() % 26;
    }
    name[20] = '\0';
}

// Function to generate a random distance for a planet
int generateDistance() {
    return rand() % 1000 + 1;
}

// Function to generate a random number of resources for a planet
int generateResources() {
    return rand() % 100 + 1;
}

// Function to display the planets in the galaxy
void displayGalaxy(Planet planets[]) {
    int i;
    for (i = 0; i < MAX_PLANETS; i++) {
        printf("%s - Distance: %d - Resources: %d\n", planets[i].name, planets[i].distance, planets[i].resources);
    }
}

// Function to prompt the user for input
int promptUser() {
    printf("Do you want to explore the galaxy? (y/n): ");
    char choice;
    scanf("%c", &choice);
    return choice == 'y'? 1 : 0;
}

int main() {
    srand(time(NULL));

    // Initialize the planets
    Planet planets[MAX_PLANETS];
    int numPlanets = 0;

    // Generate the planets
    while (numPlanets < MAX_PLANETS) {
        generateName(planets[numPlanets].name);
        planets[numPlanets].distance = generateDistance();
        planets[numPlanets].resources = generateResources();
        numPlanets++;
    }

    // Display the galaxy
    printf("Welcome to the galaxy!\n");
    displayGalaxy(planets);

    // Prompt the user for input
    int choice = promptUser();

    while (choice) {
        // Explore a planet
        int planetIndex = rand() % MAX_PLANETS;
        printf("You have landed on %s.\n", planets[planetIndex].name);
        printf("The planet is %d light years away from Earth.\n", planets[planetIndex].distance);
        printf("The planet has %d resources.\n", planets[planetIndex].resources);

        // Prompt the user for input
        printf("Do you want to explore another planet? (y/n): ");
        choice = promptUser();
    }

    return 0;
}