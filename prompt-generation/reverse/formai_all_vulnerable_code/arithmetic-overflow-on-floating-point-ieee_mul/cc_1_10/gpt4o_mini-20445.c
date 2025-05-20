//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_SPECIES 5

typedef struct {
    char name[50];
    double intelligence;
    double technology;
    double hostility;
    double explorationProbability;
} AlienSpecies;

typedef struct {
    char name[50];
    double supportingEvidence;
    double distance;  
} Planet;

void initializeSpecies(AlienSpecies *species) {
    snprintf(species[0].name, sizeof(species[0].name), "Zyloxians");
    species[0].intelligence = 0.85;
    species[0].technology = 0.90;
    species[0].hostility = 0.75;
    species[0].explorationProbability = 0.95;

    snprintf(species[1].name, sizeof(species[1].name), "Gralaxians");
    species[1].intelligence = 0.65;
    species[1].technology = 0.70;
    species[1].hostility = 0.50;
    species[1].explorationProbability = 0.80;

    snprintf(species[2].name, sizeof(species[2].name), "Frellians");
    species[2].intelligence = 0.90;
    species[2].technology = 0.95;
    species[2].hostility = 0.85;
    species[2].explorationProbability = 0.99;

    snprintf(species[3].name, sizeof(species[3].name), "Vorasites");
    species[3].intelligence = 0.75;
    species[3].technology = 0.80;
    species[3].hostility = 0.90;
    species[3].explorationProbability = 0.70;

    snprintf(species[4].name, sizeof(species[4].name), "Zarconians");
    species[4].intelligence = 0.80;
    species[4].technology = 0.75;
    species[4].hostility = 0.60;
    species[4].explorationProbability = 0.85;
}

void initializePlanets(Planet *planets, int count) {
    for (int i = 0; i < count; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "Planet_%d", i + 1);
        planets[i].supportingEvidence = (double)(rand() % 100) / 100; 
        planets[i].distance = (double)(rand() % 1000);  
    }
}

double calculateInvasionProbability(AlienSpecies species, Planet planet) {
    double probabilityScore = 0.0;

    probabilityScore += species.intelligence * 0.3;
    probabilityScore += species.technology * 0.4;
    probabilityScore += (1.0 - species.hostility) * 0.2;
    probabilityScore *= planet.supportingEvidence;
    probabilityScore /= (1 + planet.distance / 1000);

    return probabilityScore;
}

void displayProbabilities(AlienSpecies *species, Planet *planets, int planetCount) {
    printf("\nInvasion Probability Overview:\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < MAX_SPECIES; i++) {
        for (int j = 0; j < planetCount; j++) {
            double invasionProbability = calculateInvasionProbability(species[i], planets[j]);
            printf("Species: %-15s | Planet: %-12s | Probability: %.4f\n",
                species[i].name,
                planets[j].name,
                invasionProbability);
        }
    }

    printf("-----------------------------------\n");
}

int main() {
    srand(time(NULL));
    
    AlienSpecies species[MAX_SPECIES];
    Planet planets[MAX_PLANETS];

    initializeSpecies(species);
    
    int planetCount = rand() % (MAX_PLANETS - 1) + 1; 
    initializePlanets(planets, planetCount);

    displayProbabilities(species, planets, planetCount);

    return 0;
}