//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PLANET_COUNT 5

// Structure to define a celestial body (planet)
typedef struct {
    char name[20];
    double mass;
    double position;
} Planet;

// Function declarations
void initializePlanets(Planet planets[]);
void displayPlanets(Planet planets[]);
void computeGravitationalAttraction(Planet planets[]);
double calculateDistance(double p1, double p2);
void celestialArithmetic(Planet planets[], char operation);
void randomizePositions(Planet planets[]);

int main() {
    // Seed random number generation
    srand(time(NULL));

    // Create an array of planets
    Planet planets[PLANET_COUNT];
    initializePlanets(planets);
    
    // Display initial positions and masses
    printf("Welcome to the Celestial Arithmetic Simulator!\n");
    displayPlanets(planets);

    // Perform arithmetic operations based on user input
    char operation;
    while (1) {
        printf("Choose operation (+, -, *, / or 'q' to quit): ");
        scanf(" %c", &operation);
        
        if (operation == 'q') {
            printf("Exiting the celestial simulation. Farewell, Astronaut!\n");
            break;
        }

        celestialArithmetic(planets, operation);
        randomizePositions(planets); // Randomizing positions for next iteration
    }

    return 0;
}

void initializePlanets(Planet planets[]) {
    // Define planet names and random masses
    const char *names[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter"};
    for (int i = 0; i < PLANET_COUNT; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", names[i]);
        planets[i].mass = (rand() % 100 + 1) * 1.0; // Random mass between 1-100
        planets[i].position = rand() % 100; // Random position between 0-99
    }
}

void displayPlanets(Planet planets[]) {
    printf("Current State of the Universe:\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        printf("Planet: %s, Mass: %.2lf, Position: %.2lf\n", 
                planets[i].name, planets[i].mass, planets[i].position);
    }
    printf("-------------------------------------------------------\n");
}

void celestialArithmetic(Planet planets[], char operation) {
    double result = 0.0;
    double combinedMass = 0.0;
    double combinedPosition = 0.0;

    // Perform arithmetic based on chosen operation
    for (int i = 0; i < PLANET_COUNT; i++) {
        combinedMass += planets[i].mass;
        combinedPosition += planets[i].position;
    }

    switch (operation) {
        case '+':
            result = combinedMass + combinedPosition;
            printf("The celestial addition of mass and position results in: %.2lf\n", result);
            break;
        case '-':
            result = combinedMass - combinedPosition;
            printf("The celestial subtraction of position from mass yields: %.2lf\n", result);
            break;
        case '*':
            if (combinedPosition == 0) {
                printf("Warning: Multiplication by zero risk with celestial positions.\n");
            } else {
                result = combinedMass * combinedPosition;
                printf("The celestial multiplication of mass by position results in: %.2lf\n", result);
            }
            break;
        case '/':
            if (combinedPosition == 0) {
                printf("Warning: Division by zero not possible. Celestial positions must be greater than zero.\n");
            } else {
                result = combinedMass / combinedPosition;
                printf("The celestial division of mass by position yields: %.2lf\n", result);
            }
            break;
        default:
            printf("Invalid operation! Please try again.\n");
            break;
    }
}

void randomizePositions(Planet planets[]) {
    for (int i = 0; i < PLANET_COUNT; i++) {
        planets[i].position = rand() % 100; // Randomize position for the next iteration
    }
}