//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate alien invasion probability based on user input
float calculateProbability(int sightings, int days, int population) {
    float baseProbability = (float)sightings / days;
    float populationFactor = (float)population / 1000000; // Normalizing to the population of 1 million
    float invasionProbability = baseProbability * populationFactor * 100; // Percentage

    return invasionProbability < 100 ? invasionProbability : 100; // Cap at 100%
}

// Function to display the results in a lively manner
void displayResults(int sightings, int days, int population) {
    float invasionProbability = calculateProbability(sightings, days, population);
    
    printf("\n=== Alien Invasion Probability Report ===\n");
    printf("Based on your inputs:\n");
    printf("- Sightings of UFOs: %d times\n", sightings);
    printf("- Over the last %d days\n", days);
    printf("- Population in your area: %d people\n", population);
    printf("\nThe probability of an alien invasion is: %.2f%%!\n", invasionProbability);

    if (invasionProbability > 75) {
        printf("Warning! Grab your tinfoil hats, they might be coming!\n");
    } else if (invasionProbability > 50) {
        printf("Caution advised! Keep an eye on the skies!\n");
    } else if (invasionProbability > 25) {
        printf("It's a close call... Prepare just in case!\n");
    } else {
        printf("Relax! Looks like we're safe for now...\n");
    }
}

// Function to simulate random UFO sightings for the selected number of days
void simulateSightings(int days) {
    int totalSightings = 0;
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < days; i++) {
        int sightingsToday = rand() % 5; // Up to 5 sightings a day
        totalSightings += sightingsToday;
        printf("Day %d: %d UFO sighting(s)\n", i + 1, sightingsToday);
    }
    printf("\nTotal UFO sightings over %d days: %d\n", days, totalSightings);
    
    displayResults(totalSightings, days, 5000000); // Assume a fixed population for fun
}

int main() {
    int days;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Let's find out how likely it is that aliens want to invade your area!\n\n");

    // Get user input for days simulation
    printf("Enter the number of days for UFO sightings simulation (1 to 30): ");
    scanf("%d", &days);

    // Validate input
    while (days < 1 || days > 30) {
        printf("Please enter a valid number of days (1 to 30): ");
        scanf("%d", &days);
    }

    // Simulate sightings and display results
    simulateSightings(days);

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    printf("Stay vigilant, and remember: The truth is out there!\n");

    return 0;
}