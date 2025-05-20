//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
float calculateAlienProbability(int population, int sightings, int encounters);
void displayResults(int population, int sightings, int encounters, float probability);
void logResultsToFile(int population, int sightings, int encounters, float probability);

int main() {
    int population, sightings, encounters;
    char choice;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // Seed random number generator
    srand(time(NULL));
    
    // Input the total human population
    printf("Enter the total human population (in millions): ");
    scanf("%d", &population);

    // Input the number of reported alien sightings
    printf("Enter the number of reported alien sightings: ");
    scanf("%d", &sightings);
    
    // Input the number of direct alien encounters
    printf("Enter the number of direct alien encounters: ");
    scanf("%d", &encounters);
    
    // Calculate the probability of an alien invasion
    float probability = calculateAlienProbability(population, sightings, encounters);
    
    // Display results to user
    displayResults(population, sightings, encounters, probability);
    
    // Ask user if they want to log results into a file
    printf("Would you like to log the results to a file? (y/n): ");
    scanf(" %c", &choice); // Space before %c to consume any newline

    if (choice == 'y' || choice == 'Y') {
        logResultsToFile(population, sightings, encounters, probability);
        printf("Results successfully logged to alien_invasion_log.txt\n");
    } else {
        printf("Results were not logged.\n");
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}

// Function to calculate the probability of an alien invasion using hypothetical formula
float calculateAlienProbability(int population, int sightings, int encounters) {
    // Simple hypothetical probability calculation
    if (population == 0) return 0.0f; // Avoid division by zero
    float probability = ((float)sightings + (float)encounters * 10) / (float)(population * 10);
    
    // Ensure the probability does not exceed 1.0
    if (probability > 1.0f) {
        probability = 1.0f;
    }
    
    return probability * 100; // Return probability as a percentage
}

// Function to display the results in a user-friendly format
void displayResults(int population, int sightings, int encounters, float probability) {
    printf("\n--- Alien Invasion Probability Results ---\n");
    printf("Total Human Population: %d million\n", population);
    printf("Reported Alien Sightings: %d\n", sightings);
    printf("Direct Alien Encounters: %d\n", encounters);
    printf("Calculated Probability of Alien Invasion: %.2f%%\n", probability);
    printf("-------------------------------------------\n");
}

// Function to log results to a file
void logResultsToFile(int population, int sightings, int encounters, float probability) {
    FILE *file = fopen("alien_invasion_log.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file for logging!\n");
        return;
    }
    
    fprintf(file, "Population: %d million, Sightings: %d, Encounters: %d, Probability: %.2f%%\n",
            population, sightings, encounters, probability);
    
    fclose(file);
}