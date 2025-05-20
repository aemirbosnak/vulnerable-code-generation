//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_PROBABILITY 100

typedef struct City {
    char name[50];
    int population;
    int alienInfluence; // Scale from 0 to 100
} City;

void initializeCities(City cities[], int cityCount) {
    const char *cityNames[] = {
        "Metropolis", "Gotham", "Star City", "Central City", "Smallville", 
        "Coastal Town", "Riverdale", "Sunnydale", "Springfield", "Hogwarts"
    };

    for (int i = 0; i < cityCount; i++) {
        snprintf(cities[i].name, sizeof(cities[i].name), "%s", cityNames[i % 10]);
        cities[i].population = rand() % 100000 + 10000; // Population between 10,000 and 110,000
        cities[i].alienInfluence = rand() % (MAX_PROBABILITY + 1); // Influence from 0 to 100%
    }
}

float calculateInvasionProbability(City city) {
    // Simple algorithm: Probability is significantly influenced by population and alien influence
    float baseProbability = 0.05; // 5% base chance of invasion
    float populationFactor = (float)city.population / 100000; // Normalize population
    float influenceFactor = (float)city.alienInfluence / MAX_PROBABILITY; // Normalize alien influence

    // Final invasion probability calculation
    float invasionProbability = baseProbability + (populationFactor * 0.1) + (influenceFactor * 0.2);
    return invasionProbability > 1.0 ? 1.0 : invasionProbability; // Cap at 100%
}

void displayInvasionProbabilities(City cities[], int cityCount) {
    printf("\nInvasion Probability Report:\n");
    printf("-------------------------------------\n");
    printf("City Name       | Population | Influence | Probability\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < cityCount; i++) {
        float probability = calculateInvasionProbability(cities[i]);
        printf("%-15s | %-10d | %-9d | %.2f%%\n", 
               cities[i].name, 
               cities[i].population, 
               cities[i].alienInfluence, 
               probability * 100);
    }
    printf("-------------------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int cityCount;
    printf("Enter number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &cityCount);
    if (cityCount > MAX_CITIES) {
        printf("Limit exceeded, max cities set to %d.\n", MAX_CITIES);
        cityCount = MAX_CITIES;
    }

    City cities[MAX_CITIES];
    initializeCities(cities, cityCount);
    displayInvasionProbabilities(cities, cityCount);

    return 0;
}