//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 100
#define NUM_OF_SIGHTINGS 10
#define DISASTERS 3

void displayIntro();
int getPopulation();
int getSightings();
int getDisasterCount();
float computeProbability(int population, int sightings, int disasters);
void displayResults(int population, int sightings, int disasters, float probability);
void simulateAlienInvasion(float probability);

int main() {
    srand(time(NULL)); // Initialize random seed
    displayIntro();

    int population = getPopulation();
    int sightings = getSightings();
    int disasters = getDisasterCount();

    float invasionProbability = computeProbability(population, sightings, disasters);
    displayResults(population, sightings, disasters, invasionProbability);
    simulateAlienInvasion(invasionProbability);

    return 0;
}

void displayIntro() {
    printf("************************************\n");
    printf("* Welcome to the Alien Invasion     *\n");
    printf("* Probability Calculator!           *\n");
    printf("************************************\n");
    printf("Prepare yourself, Earthling!\n");
}

int getPopulation() {
    int population;
    printf("Enter the average alien population (1-%d): ", MAX_ALIENS);
    while (1) {
        scanf("%d", &population);
        if (population >= 1 && population <= MAX_ALIENS) break;
        printf("Please enter a valid number between 1 and %d: ", MAX_ALIENS);
    }
    return population;
}

int getSightings() {
    int sightings;
    printf("Enter the number of sightings (1-%d): ", NUM_OF_SIGHTINGS);
    while (1) {
        scanf("%d", &sightings);
        if (sightings >= 1 && sightings <= NUM_OF_SIGHTINGS) break;
        printf("Please enter a valid number between 1 and %d: ", NUM_OF_SIGHTINGS);
    }
    return sightings;
}

int getDisasterCount() {
    int disasters;
    printf("Enter the number of natural disasters (0-%d): ", DISASTERS);
    while (1) {
        scanf("%d", &disasters);
        if (disasters >= 0 && disasters <= DISASTERS) break;
        printf("Please enter a valid number between 0 and %d: ", DISASTERS);
    }
    return disasters;
}

float computeProbability(int population, int sightings, int disasters) {
    float baseProbability = (float)population / (float)MAX_ALIENS;
    float sightingsImpact = (float)sightings / (float)NUM_OF_SIGHTINGS;
    float disasterImpact = (float)disasters / (float)DISASTERS;

    float probability = baseProbability * sightingsImpact * (1 + disasterImpact);
    return probability > 1.0f ? 1.0f : probability; // Ensure probability does not exceed 1
}

void displayResults(int population, int sightings, int disasters, float probability) {
    printf("\n--- Invasion Probability Results ---\n");
    printf("Average Alien Population: %d\n", population);
    printf("Number of Sightings: %d\n", sightings);
    printf("Number of Natural Disasters: %d\n", disasters);
    printf("Calculated Invasion Probability: %.2f%%\n", probability * 100);
}

void simulateAlienInvasion(float probability) {
    float randomValue = (float)rand() / (float)RAND_MAX;
    if (randomValue < probability) {
        printf("\n🚨 Alert! An alien invasion is happening! 🚀\n");
    } else {
        printf("\n🌍 Phew! No alien invasion today... for now! ☕\n");
    }
}