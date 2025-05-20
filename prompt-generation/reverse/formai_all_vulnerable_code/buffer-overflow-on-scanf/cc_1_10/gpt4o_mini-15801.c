//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold characteristics of an alien
typedef struct {
    char name[50];
    int intelligence;
    float technologyLevel;
    float population;
} AlienRace;

// Function to calculate the probability of an alien invasion based on various criteria
float calculateInvasionProbability(AlienRace alien) {
    // Establish base probability factors
    float baseProbability = 0.05;  // Baseline chance of invasion
    float intelligenceFactor = ((float)alien.intelligence / 100);
    float technologyFactor = alien.technologyLevel;  // Assuming technology level on a scale of 0.0 to 1.0
    float populationFactor = log(alien.population + 1);  // Scale based on population

    // Calculate probability based on criteria
    float invasionProbability = baseProbability +
                                (intelligenceFactor * 0.2) +
                                (technologyFactor * 0.5) +
                                (populationFactor * 0.3);

    // Ensure that probability does not exceed 1.0
    if (invasionProbability > 1.0) {
        invasionProbability = 1.0;
    }
    return invasionProbability;
}

// Function to display details about the alien race
void displayAlienRace(AlienRace alien) {
    printf("Alien Race: %s\n", alien.name);
    printf("Intelligence: %d\n", alien.intelligence);
    printf("Technology Level: %.2f\n", alien.technologyLevel);
    printf("Population: %.0f\n", alien.population);
}

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator...\n");
    printf("Please provide characteristics of the alien race you encountered.\n");

    AlienRace alien;

    // Input alien race details
    printf("Enter the name of the Alien Race: ");
    fgets(alien.name, sizeof(alien.name), stdin);
    alien.name[strcspn(alien.name, "\n")] = 0;  // Remove newline character

    printf("Enter their intelligence (0-100): ");
    scanf("%d", &alien.intelligence);
    
    printf("Enter their technology level (0.0 - 1.0): ");
    scanf("%f", &alien.technologyLevel);

    printf("Enter their population size: ");
    scanf("%f", &alien.population);

    // Validate inputs
    if (alien.intelligence < 0 || alien.intelligence > 100) {
        fprintf(stderr, "Intelligence must be between 0 and 100.\n");
        return EXIT_FAILURE;
    }

    if (alien.technologyLevel < 0.0 || alien.technologyLevel > 1.0) {
        fprintf(stderr, "Technology Level must be between 0.0 and 1.0.\n");
        return EXIT_FAILURE;
    }

    if (alien.population < 0) {
        fprintf(stderr, "Population must be a non-negative number.\n");
        return EXIT_FAILURE;
    }

    // Calculate and display invasion probability
    float invasionProbability = calculateInvasionProbability(alien);
    displayAlienRace(alien);

    printf("The probability of invasion from %s is: %.2f%%\n", alien.name, invasionProbability * 100);

    // Conclusion based on probability
    if (invasionProbability > 0.5) {
        printf("Watson, we are in peril! Prepare for a possible invasion!\n");
    } else {
        printf("It seems rather safe, or we may have time to prepare!\n");
    }

    return EXIT_SUCCESS;
}