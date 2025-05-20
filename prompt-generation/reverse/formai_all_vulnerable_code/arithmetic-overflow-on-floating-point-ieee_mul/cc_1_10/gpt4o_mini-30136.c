//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_HISTORY 10
#define ALIEN_THREAT_LEVEL 100.0

// Structure to hold historical alien encounters
typedef struct {
    int year;
    int threats;
} Encounter;

// Function declarations
void getUserInput(float *population, float *technology_level, Encounter encounters[], int *count);
float calculateInvasionProbability(float population, float technology_level, Encounter encounters[], int count);
void displayResults(float probability);

int main() {
    float population;
    float technology_level;
    Encounter encounters[MAX_HISTORY];
    int count;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    getUserInput(&population, &technology_level, encounters, &count);
    
    float probability = calculateInvasionProbability(population, technology_level, encounters, count);
    
    displayResults(probability);
    
    return 0;
}

// Function to get user input
void getUserInput(float *population, float *technology_level, Encounter encounters[], int *count) {
    printf("Enter the size of the population (in billions): ");
    scanf("%f", population);
    
    printf("Enter the technological advancement level (1-10): ");
    scanf("%f", technology_level);
    
    printf("How many historical alien encounters do you want to input? (max %d): ", MAX_HISTORY);
    scanf("%d", count);
    
    if (*count > MAX_HISTORY) {
        *count = MAX_HISTORY;
    }
    
    for (int i = 0; i < *count; i++) {
        printf("Enter year of encounter %d: ", i + 1);
        scanf("%d", &encounters[i].year);
        
        printf("Enter threat level for encounter %d (1-10): ", i + 1);
        scanf("%d", &encounters[i].threats);
    }
}

// Function to calculate invasion probability
float calculateInvasionProbability(float population, float technology_level, Encounter encounters[], int count) {
    float base_probability = (population / ALIEN_THREAT_LEVEL) * (technology_level / 10.0);
    
    // Modify probability based on historical encounters
    for (int i = 0; i < count; i++) {
        base_probability += (encounters[i].threats / 10.0);
    }

    // Ensuring the probability does not exceed 1
    if (base_probability > 1.0) {
        base_probability = 1.0;
    }
    
    // Apply correlation factor for technology vs threat
    float tech_factor = (technology_level / 10.0);
    base_probability *= (1 - tech_factor);
    
    return base_probability;
}

// Function to display results
void displayResults(float probability) {
    printf("Calculated Alien Invasion Probability: %.2f%%\n", probability * 100);
    
    if (probability < 0.2) {
        printf("Low threat level. We are safe for now.\n");
    } else if (probability < 0.5) {
        printf("Moderate threat level. Keep alert!\n");
    } else {
        printf("High threat level! Prepare for potential invasion!\n");
    }
}