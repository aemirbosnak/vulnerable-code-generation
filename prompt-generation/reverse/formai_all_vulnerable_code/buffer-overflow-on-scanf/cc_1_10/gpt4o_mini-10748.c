//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 100
#define MAX_ALIENS 1000

typedef struct {
    char name[20];
    float probability_of_invasion;
} Planet;

void initializePlanets(Planet planets[], int num_planets);
void simulateInvasion(Planet planets[], int num_planets);
void displayResults(Planet planets[], int num_planets);
void calculateAverageInvasionProbability(Planet planets[], int num_planets);

int main() {
    srand(time(NULL)); // Seed the random number generator

    int num_planets;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of planets (up to %d): ", MAX_PLANETS);
    
    // Input validation for number of planets
    while (1) {
        scanf("%d", &num_planets);
        if (num_planets > 0 && num_planets <= MAX_PLANETS) {
            break;
        } else {
            printf("Please enter a valid number of planets (1-%d): ", MAX_PLANETS);
        }
    }

    Planet planets[MAX_PLANETS];
    initializePlanets(planets, num_planets);
    simulateInvasion(planets, num_planets);
    displayResults(planets, num_planets);
    
    return 0;
}

// Function to initialize planet names and their invasion probabilities
void initializePlanets(Planet planets[], int num_planets) {
    const char *sample_planet_names[] = {
        "Mars", "Jupiter", "Venus", "Saturn", "Neptune",
        "Titan", "Europa", "Ganymede", "Enceladus", "Ceres",
        "Pluto", "Makemake", "Haumea", "Eris", "Sedna"
    };

    for (int i = 0; i < num_planets; i++) {
        snprintf(planets[i].name, sizeof(planets[i].name), "%s", sample_planet_names[i % 15]);
        planets[i].probability_of_invasion = (rand() % 10001) / 100.0; // Random probability from 0.0 to 100.0
    }
}

// Function to simulate alien invasions based on calculated probabilities
void simulateInvasion(Planet planets[], int num_planets) {
    printf("\nSimulating alien invasions...\n");
    
    for (int i = 0; i < num_planets; i++) {
        float invasion_chance = (rand() % 10001) / 100.0; // Compare with random value
        if (invasion_chance <= planets[i].probability_of_invasion) {
            printf("🔥 Invasion Alert! Aliens have invaded %s! 🔥\n", planets[i].name);
        } else {
            printf("🌌 Safe! No invasion on %s. 🌌\n", planets[i].name);
        }
    }
}

// Function to display the invasion probabilities of all planets
void displayResults(Planet planets[], int num_planets) {
    printf("\n=== Invasion Probability Summary ===\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet: %s, Invasion Probability: %.2f%%\n", 
               planets[i].name, planets[i].probability_of_invasion);
    }
    calculateAverageInvasionProbability(planets, num_planets);
}

// Function to calculate and display the average invasion probability
void calculateAverageInvasionProbability(Planet planets[], int num_planets) {
    float total_probability = 0.0;
    
    for (int i = 0; i < num_planets; i++) {
        total_probability += planets[i].probability_of_invasion;
    }

    float average_probability = total_probability / num_planets;
    printf("🚀 Average Invasion Probability across all planets: %.2f%% 🚀\n", average_probability);
}