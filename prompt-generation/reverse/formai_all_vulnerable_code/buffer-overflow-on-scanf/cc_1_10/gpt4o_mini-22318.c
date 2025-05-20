//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

typedef struct {
    char name[50];
    int population;
    int alien_sightings;
} City;

double calculate_probability(int sightings, int population) {
    if (population == 0) {
        return 0.0; // Avoid division by zero
    }
    return (double)sightings / population;
}

void simulate_alien_invasion(City *city) {
    // Simulating alien sightings with a random number from 0 to 10
    city->alien_sightings = rand() % 11; // Random sightings from 0 to 10
}

void show_data(City *cities, int city_count) {
    printf("\nAlien Invasion Probability Report\n");
    printf("----------------------------------\n");
    printf("%-20s %-15s %-20s %-20s\n", "City", "Population", "Sightings", "Invasion Probability");
    printf("----------------------------------\n");
    for (int i = 0; i < city_count; i++) {
        double probability = calculate_probability(cities[i].alien_sightings, cities[i].population);
        printf("%-20s %-15d %-20d %-20.2f%%\n",
               cities[i].name,
               cities[i].population,
               cities[i].alien_sightings,
               probability * 100);
    }
}

void input_city_data(City *cities, int city_count) {
    for (int i = 0; i < city_count; i++) {
        printf("\nEnter data for City %d:\n", i + 1);
        printf("Enter city name: ");
        scanf(" %[^\n]%*c", cities[i].name); // Use %[^\n] to read string with spaces
        printf("Enter population: ");
        scanf("%d", &cities[i].population);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    City cities[MAX_CITIES];
    int city_count;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many cities would you like to analyze (max %d)? ", MAX_CITIES);
    scanf("%d", &city_count);

    if (city_count < 1 || city_count > MAX_CITIES) {
        printf("Please enter a valid number of cities between 1 and %d.\n", MAX_CITIES);
        return 1;
    }

    input_city_data(cities, city_count);

    for (int i = 0; i < city_count; i++) {
        simulate_alien_invasion(&cities[i]);
    }

    show_data(cities, city_count);

    printf("\nThank you for using the Alien Invasion Probability Calculator. Stay safe!\n");

    return 0;
}