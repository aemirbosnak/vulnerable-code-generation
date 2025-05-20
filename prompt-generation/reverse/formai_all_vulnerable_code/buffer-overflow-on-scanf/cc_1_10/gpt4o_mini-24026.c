//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Maximum size for the name of the planet
#define MAX_NAME_LENGTH 50
// Error message in case of invalid input
#define ERROR_MESSAGE "Invalid input! Please enter a number."

// Function prototypes
void getPlanetName(char *planetName);
void getProbabilities(double *probability);
double calculateInvasionChance(double probability);
void displayResults(const char *planetName, double invasionChance);

int main() {
    char planetName[MAX_NAME_LENGTH];
    double invasionProbability;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Get the planet name from the user
    getPlanetName(planetName);

    // Get invasion probabilities
    getProbabilities(&invasionProbability);

    // Calculate the chance of invasion
    double invasionChance = calculateInvasionChance(invasionProbability);

    // Display the results
    displayResults(planetName, invasionChance);

    return 0;
}

// Function to get the name of the planet from the user
void getPlanetName(char *planetName) {
    printf("Enter the name of the planet: ");
    fgets(planetName, MAX_NAME_LENGTH, stdin);
    
    // Remove newline character from string
    size_t length = strlen(planetName);
    if (length > 0 && planetName[length - 1] == '\n') {
        planetName[length - 1] = '\0';
    }
}

// Function to get the probability of invasion from the user
void getProbabilities(double *probability) {
    printf("Enter the probability of alien invasion (0-1): ");
    
    while (scanf("%lf", probability) != 1 || *probability < 0.0 || *probability > 1.0) {
        while (getchar() != '\n'); // Clear the input buffer
        printf(ERROR_MESSAGE);
        printf("\nEnter the probability of alien invasion (0-1): ");
    }
}

// Function to calculate the chance of invasion
double calculateInvasionChance(double probability) {
    return probability * (double)(rand() % 100 + 1) / 100;
}

// Function to display the results
void displayResults(const char *planetName, double invasionChance) {
    printf("\n--- Alien Invasion Probability Report ---\n");
    printf("Planet Name: %s\n", planetName);
    printf("Calculated Chance of Invasion: %.2f%%\n", invasionChance);
    
    if (invasionChance > 50.0) {
        printf("Warning! High probability of invasion!\n");
    } else {
        printf("You're safe... for now!\n");
    }
}