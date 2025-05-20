//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ALIENS 100

// Structure to represent a city
typedef struct {
    char name[50];
    int population;
    float alien_invasion_chance;
} City;

// Function to initialize the city data
void initializeCities(City cities[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter city %d name: ", i + 1);
        scanf("%s", cities[i].name);
        printf("Enter city %d population: ", i + 1);
        scanf("%d", &cities[i].population);
        cities[i].alien_invasion_chance = 0.0; // Initialize as 0
    }
}

// Function to calculate probability of alien invasion
float calculateInvasionProbability(City city) {
    if (city.population < 1000) {
        return 0.01; // Low chance for small populations
    } else if (city.population < 10000) {
        return 0.05; // Moderate chance for medium populations
    } else {
        return 0.1; // High chance for large populations
    }
}

// Function to simulate the alien invasion scenario
void simulateInvasion(City cities[], int count) {
    for (int i = 0; i < count; i++) {
        cities[i].alien_invasion_chance = calculateInvasionProbability(cities[i]);
        float invasion_result = ((float) rand() / (RAND_MAX));
        
        printf("In city %s with population %d:\n", cities[i].name, cities[i].population);
        printf("Calculated alien invasion chance: %.2f\n", cities[i].alien_invasion_chance);
        
        if (invasion_result < cities[i].alien_invasion_chance) {
            printf("Alien invasion is likely to occur!\n\n");
        } else {
            printf("Alien invasion is unlikely to occur.\n\n");
        }
    }
}

// Function to display the results of the invasion simulation
void displayResults(City cities[], int count) {
    printf("---- Summary of Alien Invasion Probabilities ----\n");
    for (int i = 0; i < count; i++) {
        printf("City: %s | Population: %d | Invasion Chance: %.2f\n", 
                cities[i].name, cities[i].population, cities[i].alien_invasion_chance);
    }
}

int main() {
    int city_count;
    City cities[MAX_CITIES];

    srand(time(NULL)); // Seed the random number generator

    printf("Enter the number of cities (1 - %d): ", MAX_CITIES);
    scanf("%d", &city_count);
    if (city_count < 1 || city_count > MAX_CITIES) {
        printf("Invalid number of cities. Exiting program.\n");
        return 1;
    }

    initializeCities(cities, city_count);
    simulateInvasion(cities, city_count);
    displayResults(cities, city_count);

    return 0;
}