//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate probability of Alien Invasion
float alienInvasionProbabilityCalculator(int population, int militaryStrength, int technologyLevel, int previousIncidents) {
    float probability;
    float populationFactor = 0.0, militaryFactor = 0.0, techFactor = 0.0, incidentFactor = 0.0;

    // calculate population factor
    if(population > 1000000) {
        populationFactor = 0.85;
    }
    else if(population > 500000) {
        populationFactor = 0.7;
    }
    else if(population > 250000) {
        populationFactor = 0.5;
    }
    else if(population > 100000) {
        populationFactor = 0.25;
    }

    // calculate military strength factor
    if(militaryStrength > 1000) {
        militaryFactor = 0.85;
    }
    else if(militaryStrength > 500) {
        militaryFactor = 0.7;
    }
    else if(militaryStrength > 250) {
        militaryFactor = 0.5;
    }
    else if(militaryStrength > 100) {
        militaryFactor = 0.25;
    }

    // calculate technology level factor
    if(technologyLevel > 5) {
        techFactor = 0.85;
    }
    else if(technologyLevel > 3) {
        techFactor = 0.7;
    }
    else if(technologyLevel > 1) {
        techFactor = 0.5;
    }
    else if(technologyLevel >= 0) {
        techFactor = 0.25;
    }

    // calculate previous incidents factor
    if(previousIncidents > 10) {
        incidentFactor = 0.85;
    }
    else if(previousIncidents > 5) {
        incidentFactor = 0.7;
    }
    else if(previousIncidents > 1) {
        incidentFactor = 0.5;
    }
    else if(previousIncidents >= 0) {
        incidentFactor = 0.25;
    }

    // calculate final probability
    probability = ((populationFactor * militaryFactor * techFactor) + incidentFactor) * 100.0;
    return probability;
}

int main() {
    int population, militaryStrength, technologyLevel, previousIncidents;
    float probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please answer the following questions to predict the probability of an alien invasion.\n\n");

    printf("What is the current population of your city? ");
    scanf("%d", &population);

    printf("\nWhat is the military strength in your city? ");
    scanf("%d", &militaryStrength);

    printf("\nWhat is the technology level in your city? (0-5) ");
    scanf("%d", &technologyLevel);

    printf("\nHow many previous incidents of alien sightings have occurred in your city? ");
    scanf("%d", &previousIncidents);

    probability = alienInvasionProbabilityCalculator(population, militaryStrength, technologyLevel, previousIncidents);

    printf("\nBased on the data provided, the probability of an alien invasion is %.2f%%.\n", probability);
    printf("Stay vigilant and report any suspicious activity immediately!\n");

    return 0;
}