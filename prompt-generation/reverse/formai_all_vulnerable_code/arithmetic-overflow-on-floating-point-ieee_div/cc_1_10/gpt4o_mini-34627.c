//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>

// Function prototypes
double calculateProbability(int population, int sightings, double distance);
void displayResult(double probability);

int main() {
    int population;
    int sightings;
    double distance;
    char continueCalculating;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    do {
        // Get user input
        printf("Enter the Earth's population (in billions): ");
        scanf("%d", &population);
        
        printf("Enter the number of UFO sightings reported in the last year: ");
        scanf("%d", &sightings);
        
        printf("Enter the average distance to the nearest star system (in light-years): ");
        scanf("%lf", &distance);
        
        // Calculate the invasion probability
        double probability = calculateProbability(population, sightings, distance);
        
        // Display results
        displayResult(probability);
        
        // Ask if the user wants to continue
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &continueCalculating);
    } while(continueCalculating == 'y' || continueCalculating == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}

// Function to calculate the probability based on input parameters
double calculateProbability(int population, int sightings, double distance) {
    // Formula for calculating invasion probability
    // The more sightings and lower distance, the greater the probability
    return (sightings / (double)population) * (100 / distance);
}

// Function to display the calculated probability
void displayResult(double probability) {
    // Ensure probability does not exceed 100%
    if (probability > 100) {
        probability = 100;
    }
    printf("The calculated probability of an alien invasion is: %.2f%%\n", probability);
}