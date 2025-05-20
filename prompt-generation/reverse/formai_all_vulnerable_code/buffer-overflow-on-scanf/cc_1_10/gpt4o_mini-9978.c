//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CITIES 10
#define MAX_TECH_LEVEL 10
#define MAX_SIGNALS 100

// Function prototypes
double calculate_population_density(int population, double area);
double calculate_technology_effect(int tech_level);
double calculate_signal_effect(int signals_received);
double calculate_invasion_probability(double density, double tech_effect, double signal_effect);

int main() {
    int populations[MAX_CITIES];
    double areas[MAX_CITIES];
    int tech_levels[MAX_CITIES];
    int signals_received[MAX_CITIES];
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("===================================\n");
    
    // Gather data from user
    for (int i = 0; i < MAX_CITIES; i++) {
        printf("\nCity %d:\n", i + 1);
        
        printf("Enter population: ");
        scanf("%d", &populations[i]);
        
        printf("Enter area (in km²): ");
        scanf("%lf", &areas[i]);
        
        printf("Enter technology level (0 to %d): ", MAX_TECH_LEVEL);
        scanf("%d", &tech_levels[i]);
        if (tech_levels[i] < 0 || tech_levels[i] > MAX_TECH_LEVEL) {
            printf("Invalid technology level, setting to 0.\n");
            tech_levels[i] = 0;
        }
        
        printf("Enter number of alien signals received: ");
        scanf("%d", &signals_received[i]);
        if (signals_received[i] < 0 || signals_received[i] > MAX_SIGNALS) {
            printf("Invalid number of signals, setting to 0.\n");
            signals_received[i] = 0;
        }
    }
    
    // Process data and calculate probabilities
    printf("\nCalculating invasion probabilities...\n");
    printf("===================================\n");
    
    for (int i = 0; i < MAX_CITIES; i++) {
        double density = calculate_population_density(populations[i], areas[i]);
        double tech_effect = calculate_technology_effect(tech_levels[i]);
        double signal_effect = calculate_signal_effect(signals_received[i]);
        
        double invasion_probability = calculate_invasion_probability(density, tech_effect, signal_effect);
        
        printf("City %d:\n", i + 1);
        printf("Population Density: %.2f people/km²\n", density);
        printf("Technology Effect: %.2f\n", tech_effect);
        printf("Signal Effect: %.2f\n", signal_effect);
        printf("Invasion Probability: %.2f%%\n", invasion_probability * 100);
        printf("===================================\n");
    }
    
    return 0;
}

// Calculates the population density given population and area.
double calculate_population_density(int population, double area) {
    if (area <= 0) {
        return 0; // Avoid division by zero
    }
    return (double) population / area;
}

// Calculates technology effect based on a scale of 0 to MAX_TECH_LEVEL
double calculate_technology_effect(int tech_level) {
    return pow(1.1, tech_level); // Exponential technology scaling
}

// Calculates signal effect based on the number of signals received
double calculate_signal_effect(int signals_received) {
    return (double) signals_received / MAX_SIGNALS; // Proportion of signals received
}

// Final invasion probability formula
double calculate_invasion_probability(double density, double tech_effect, double signal_effect) {
    // Base invasion probability based on various factors
    return (density * 0.01 + tech_effect * 0.4 + signal_effect * 0.5);
}