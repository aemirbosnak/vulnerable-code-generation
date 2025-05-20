//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

typedef struct {
    char name[50];
    int population;
    int alien_activity; // Scale from 0-100
} City;

void initialize_cities(City cities[], int num_cities) {
    const char *city_names[] = {"Metropolis", "Gotham", "Central City", "Star City",
                                "National City", "Futura", "New Haven", "Arcadia", 
                                "Elysium", "Utopia", "Paradise", "Oasis"};

    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "%s %d", city_names[i % 12], (rand() % 100 + 1));
        cities[i].population = rand() % 1000000 + 10000; // Pop between 10k and 1M
        cities[i].alien_activity = rand() % 101; // Activity scale from 0 to 100
    }
}

float calculate_invasion_probability(City city) {
    float base_probability = (float)city.alien_activity / 100;
    float population_factor = (float)city.population / 1000000; // Scale factor
    float probability = base_probability * population_factor;

    // Cap the probability to a maximum of 1 (100%)
    if (probability > 1.0) {
        probability = 1.0;
    }

    return probability * 100; // Return percentage
}

void display_probabilities(City cities[], int num_cities) {
    printf("\nInvasion Probability Report:\n");
    printf("---------------------------------------------------------\n");
    printf("%-20s %-20s %-20s\n", "City", "Population", "Invasion Probability (%)");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < num_cities; i++) {
        float probability = calculate_invasion_probability(cities[i]);
        printf("%-20s %-20d %-20.2f\n", cities[i].name, cities[i].population, probability);
    }
    printf("---------------------------------------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities to analyze (max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    if (num_cities > MAX_CITIES) {
        printf("Exceeded maximum city limit. Setting to %d.\n", MAX_CITIES);
        num_cities = MAX_CITIES;
    } else if (num_cities <= 0) {
        printf("Invalid number of cities. Exiting...\n");
        return 1; // Exit on invalid number
    }

    initialize_cities(cities, num_cities);
    display_probabilities(cities, num_cities);

    return 0;
}