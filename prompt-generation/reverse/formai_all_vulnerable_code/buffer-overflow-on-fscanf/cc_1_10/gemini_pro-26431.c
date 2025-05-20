//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#define MAX_CONF_SIZE 1024

// Structure of Alien Invasion Probability Configuration
typedef struct AlienInvasionProbabilityConfig {
    long long int num_stars;
    double life_probability;
    double intelligence_probability;
    double technological_probability;
    double peaceful_probability;
} AlienInvasionProbabilityConfig;

// Function to load configuration from a text file
int load_config(const char* filename, AlienInvasionProbabilityConfig* config) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        return 1;
    }
    fscanf(fp, "%lld %lf %lf %lf %lf", &config->num_stars, &config->life_probability, &config->intelligence_probability,
        &config->technological_probability, &config->peaceful_probability);
    fclose(fp);
    return 0;
}

// Function to calculate Alien Invasion Probability
double calculate_invasion_probability(const AlienInvasionProbabilityConfig* config) {
    double probability = (double)config->num_stars * config->life_probability * config->intelligence_probability *
        config->technological_probability * (1 - config->peaceful_probability);
    return probability;
}

// Function to print the Alien Invasion Probability
void print_probability(double probability) {
    printf("The probability of an alien invasion is: %lf\n", probability);
}

int main() {
    AlienInvasionProbabilityConfig config;
    // Load configuration from a text file
    if (load_config("alien_invasion.cfg", &config) != 0) {
        printf("Error loading configuration file.\n");
        return 1;
    }
    // Calculate Alien Invasion Probability
    double probability = calculate_invasion_probability(&config);
    // Print the Alien Invasion Probability
    print_probability(probability);
    return 0;
}