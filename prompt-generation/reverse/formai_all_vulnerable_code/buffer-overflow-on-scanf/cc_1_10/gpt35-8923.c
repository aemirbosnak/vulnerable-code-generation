//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 5

// Function prototypes
void initializePlanets(int planets[NUM_PLANETS][2]);
void printPlanets(int planets[NUM_PLANETS][2]);

int main() {
    int planets[NUM_PLANETS][2]; // 2D array to store coordinates of planets
    int currentPlanet;
    int fuel = 1000;
    int distance;
    srand(time(NULL)); // Seed the random number generator
    
    initializePlanets(planets); // Initialize the coordinates of the planets
    printPlanets(planets); // Print the locations of the planets
    
    printf("\nWelcome to the Space Adventure game!\n");
    printf("You have 1000 units of fuel and are currently on planet Earth.\n");
    
    do {
        printf("\nWhich planet would you like to travel to?\n");
        scanf("%d", &currentPlanet);
        
        // Check if the input is valid
        if (currentPlanet < 1 || currentPlanet > 5) {
            printf("Invalid input. Please choose a number between 1 and 5.\n");
            continue;
        }
        
        // Calculate the distance to the new planet
        distance = abs(planets[currentPlanet - 1][0] - planets[0][0]) + abs(planets[currentPlanet - 1][1] - planets[0][1]);
        
        // Check if there is enough fuel to make the trip
        if (distance > fuel) {
            printf("Not enough fuel to make the trip. Please choose another planet.\n");
            continue;
        }
        
        printf("Traveling to planet %d...\n", currentPlanet);
        fuel -= distance; // Deduct fuel
        
        // Generate a random event
        switch (rand() % 3) {
            case 0:
                printf("You have discovered an abandoned spaceship and gained 500 units of fuel!\n");
                fuel += 500;
                break;
            case 1:
                printf("You have encountered hostile aliens!\n");
                fuel -= 200;
                break;
            case 2:
                printf("You have discovered a new planet and have gained 200 units of fuel!\n");
                fuel += 200;
                break;
        }
        
        printf("You now have %d units of fuel.\n", fuel);
        
    } while (currentPlanet != 1); // Keep traveling until the player returns to Earth
    
    printf("\nCongratulations, you have returned to planet Earth!\n");
    printf("Final fuel count: %d\n", fuel);
    
    return 0;
}

// Function to initialize the coordinates of the planets
void initializePlanets(int planets[NUM_PLANETS][2]) {
    planets[0][0] = 0;
    planets[0][1] = 0;
    
    for (int i = 1; i < NUM_PLANETS; i++) {
        planets[i][0] = rand() % 20 - 10; // Random x coordinate between -10 and 10
        planets[i][1] = rand() % 20 - 10; // Random y coordinate between -10 and 10
    }
}

// Function to print the locations of the planets
void printPlanets(int planets[NUM_PLANETS][2]) {
    printf("Planet\tX\tY\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%d\t%d\t%d\n", i+1, planets[i][0], planets[i][1]);
    }
}