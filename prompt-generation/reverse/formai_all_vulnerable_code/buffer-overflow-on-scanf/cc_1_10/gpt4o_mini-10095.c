//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compute the probability of an alien invasion
double computeInvasionProbability(int sightings, int expectedEvents) {
    if (expectedEvents == 0) {
        printf("No expected events to calculate probability.\n");
        return 0.0;
    }
    return (double)sightings / expectedEvents;
}

// Function to simulate alien sightings based on random events
int simulateAlienSightings(int days) {
    int sightings = 0;
    srand(time(NULL)); // Seed the random number generator
    for (int day = 0; day < days; day++) {
        // 20% chance of sighting on any given day
        if (rand() % 100 < 20) {
            sightings++;
        }
    }
    return sightings;
}

// Function to display the probabilities and analysis
void displayResults(int sightings, int expectedEvents) {
    double probability = computeInvasionProbability(sightings, expectedEvents);
    printf("\n*** Alien Invasion Probability Analysis ***\n");
    printf("Total days observed: %d\n", expectedEvents);
    printf("Alien sightings recorded: %d\n", sightings);
    printf("Calculated probability of alien invasion: %.2f%%\n", probability * 100);
    
    if (probability >= 0.5) {
        printf("Warning: High probability of an alien invasion detected!\n");
    } else {
        printf("Alien invasion probability is currently low.\n");
    }
}

int main() {
    int days;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // Ask user for the number of days to observe alien sightings
    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);
    
    if (days <= 0) {
        printf("Please enter a valid number of days greater than zero.\n");
        return 1;
    }
    
    int expectedEvents = days; // Each day counts as one expected event
    int sightings = simulateAlienSightings(days);
    displayResults(sightings, expectedEvents);
    
    // Future predictions
    printf("\nLet's forecast the alien behavior based on calculated probability...\n");
    int futureDays = 10; // projecting next 10 days
    double futureProbability = computeInvasionProbability(sightings, expectedEvents + futureDays);
    
    printf("Projected alien sightings in the next %d days: ", futureDays);
    for (int i = 0; i < futureDays; i++) {
        if (rand() % 100 < 20) {
            printf("Sighting on day %d! ", i + 1);
        }
    }
    
    printf("\nProjected Invasion Probability after %d days: %.2f%%\n\n", futureDays, futureProbability * 100);
    
    // Conclusion based on multi-day prediction
    if (futureProbability >= 0.5) {
        printf("Alert: Potential invasion risk increases significantly in the upcoming days!\n");
    } else {
        printf("The alien threat level remains manageable.\n");
    }
    
    return 0;
}