//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of an alien invasion
double calculate_invasion_probability(int number_of_days, int sightings) {
    if (number_of_days <= 0) {
        printf("Number of days must be greater than zero.\n");
        return 0.0;
    }
    return (double)sightings / number_of_days * 100.0; // Probability as a percentage
}

// Function to simulate alien sightings
int simulate_sightings(int number_of_days) {
    srand(time(NULL)); // Seed for random number generation
    int sightings = 0;

    for (int i = 0; i < number_of_days; i++) {
        // Simulate a 1 in 10 chance of an alien sighting each day
        if (rand() % 10 == 0) {
            sightings++;
        }
    }
    return sightings;
}

// Function to display the results in a creative format
void display_results(int days, int sightings, double probability) {
    printf("🎇 Alien Invasion Probability Calculator 🎇\n");
    printf("=========================================\n");
    printf("Number of days monitored: %d\n", days);
    printf("Alien sightings recorded: %d\n", sightings);
    printf("Calculated probability of invasion: %.2f%%\n", probability);
    printf("=========================================\n");
    
    // Artistic representation based on probability
    int stars = (int)(probability / 2); // Normalize the number of stars Max 50
    printf("Invasion Risk Level: ");
    for (int i = 0; i < stars; i++) {
        printf("⭐");
    }
    printf("\n");

    if (stars >= 25) {
        printf("🚨 Warning! High probability of invasion! Prepare for contact! 🚨\n");
    } else {
        printf("🌍 Earth is safe... for now. 🌍\n");
    }
}

int main() {
    int number_of_days;
    printf("Enter the number of days you want to monitor for alien sightings: ");
    scanf("%d", &number_of_days);

    // Simulate sightings
    int sightings = simulate_sightings(number_of_days);

    // Calculate the probability of an invasion
    double probability = calculate_invasion_probability(number_of_days, sightings);

    // Display results
    display_results(number_of_days, sightings, probability);

    return 0;
}