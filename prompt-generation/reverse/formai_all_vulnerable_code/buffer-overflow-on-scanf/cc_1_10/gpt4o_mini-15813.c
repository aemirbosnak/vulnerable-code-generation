//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARAMETERS 5

// Function prototypes
double calculateInvasionProbability(double factors[MAX_PARAMETERS]);
void displayInvasionRisk(double probability);
void getInputFactors(double factors[MAX_PARAMETERS]);
void simulateInvasionEvent(double probability);

// Main function
int main() {
    double factors[MAX_PARAMETERS];
    double invasionProbability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please provide the following factors that might influence an alien invasion:\n");

    getInputFactors(factors);
    invasionProbability = calculateInvasionProbability(factors);
    displayInvasionRisk(invasionProbability);
    simulateInvasionEvent(invasionProbability);

    return 0;
}

// Function to input factors
void getInputFactors(double factors[MAX_PARAMETERS]) {
    const char* parameterNames[MAX_PARAMETERS] = {
        "Global population density (people per sq km)",
        "Technological advancement level (1-10)",
        "Historical alien sightings (number)",
        "Societal readiness for contact (1-10)",
        "Environmental stability (1-10; 10 being most stable)"
    };

    for(int i = 0; i < MAX_PARAMETERS; i++) {
        printf("%s: ", parameterNames[i]);
        scanf("%lf", &factors[i]);
    }
}

// Function to calculate invasion probability
double calculateInvasionProbability(double factors[MAX_PARAMETERS]) {
    double baseRisk = 0.1; // Base risk of invasion
    double populationWeight = 0.4;
    double techWeight = 0.2;
    double sightingsWeight = 0.3;
    double readinessWeight = 0.1;

    // Calculate weighted risk factors
    double invasionRisk = baseRisk +
                          (factors[0] * populationWeight / 100) +
                          (factors[1] * techWeight / 10) +
                          (factors[2] * sightingsWeight / 10) +
                          (factors[3] * readinessWeight / 10) -
                          (factors[4] * 0.05); // Environmental stability reduces risk

    // Normalize to a [0,1] range
    if(invasionRisk > 1.0) {
        invasionRisk = 1.0;
    } else if(invasionRisk < 0.0) {
        invasionRisk = 0.0;
    }

    return invasionRisk;
}

// Function to display invasion risk
void displayInvasionRisk(double probability) {
    printf("\nCalculated probability of alien invasion: %.2f%%\n", probability * 100);
    if(probability < 0.2) {
        printf("Invasion Risk Level: Very Low\n");
    } else if(probability < 0.5) {
        printf("Invasion Risk Level: Moderate\n");
    } else if(probability < 0.8) {
        printf("Invasion Risk Level: High\n");
    } else {
        printf("Invasion Risk Level: Very High\n");
    }
}

// Function to simulate an alien invasion event based on probability
void simulateInvasionEvent(double probability) {
    srand(time(NULL));
    double randomValue = (double)rand() / RAND_MAX; // Generate a random number between [0, 1]

    printf("\nSimulating an alien invasion event...\n");
    if(randomValue < probability) {
        printf("Alert! An alien invasion has occurred!\n");
    } else {
        printf("No invasion today. The Earth is safe for now.\n");
    }
}