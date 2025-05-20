//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_POPULATION 1000000
#define ALIEN_APPEARANCE_RATE 0.0001 // Rate at which aliens invade a planet

typedef struct {
    char name[30];
    int population;
    float alien_invasion_probability;
} Planet;

void initialize_planets(Planet planets[], int count);
void calculate_invasion_probability(Planet *planet);
void display_planet_info(const Planet planets[], int count);
float random_float(float min, float max);
void simulate_invasion(Planet *planet);

int main() {
    srand(time(NULL));
    
    int number_of_planets;
    printf("Enter the number of planets (up to %d): ", MAX_PLANETS);
    scanf("%d", &number_of_planets);

    // Limiting the number of planets to the maximum allowed
    if (number_of_planets > MAX_PLANETS) {
        printf("Maximum number of planets is %d. Reducing the count.\n", MAX_PLANETS);
        number_of_planets = MAX_PLANETS;
    } else if (number_of_planets <= 0) {
        printf("Number of planets must be positive. Setting it to 1.\n");
        number_of_planets = 1;
    }

    Planet planets[MAX_PLANETS];
    initialize_planets(planets, number_of_planets);
    display_planet_info(planets, number_of_planets);

    // Simulate aliens invading each planet
    for (int i = 0; i < number_of_planets; i++) {
        simulate_invasion(&planets[i]);
    }

    return 0;
}

void initialize_planets(Planet planets[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of planet %d: ", i + 1);
        scanf("%s", planets[i].name);
        planets[i].population = rand() % MAX_POPULATION + 1; // Random population between 1 and MAX_POPULATION
        calculate_invasion_probability(&planets[i]);
    }
}

void calculate_invasion_probability(Planet *planet) {
    // Calculate the probability of an alien invasion based on the population
    planet->alien_invasion_probability = (float)planet->population * ALIEN_APPEARANCE_RATE;
}

void display_planet_info(const Planet planets[], int count) {
    printf("\nPlanet Information:\n");
    printf("===========================================\n");
    printf("Name\t\tPopulation\tInvasion Probability\n");
    printf("===========================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s\t%-10d\t%-15.6f\n", planets[i].name, planets[i].population, planets[i].alien_invasion_probability);
    }
    printf("===========================================\n");
}

float random_float(float min, float max) {
    float range = max - min;
    return min + ((float)rand() / (float)(RAND_MAX)) * range;
}

void simulate_invasion(Planet *planet) {
    float invasion_chance = random_float(0, 1);
    if (invasion_chance < planet->alien_invasion_probability) {
        printf("Alien invasion ALERT on planet %s!\n", planet->name);
    } else {
        printf("No alien invasion on planet %s. All is well.\n", planet->name);
    }
}