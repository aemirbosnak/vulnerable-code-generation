//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Probability Calculator for Alien Invasion
// A paranoid approach to evaluate alien invasion risks.
// The universe is vast, and we must stay vigilant!

float calculate_invasion_probability(int encounters, int disasters) {
    // This function computes a speculative invasion probability
    if (encounters < 1) {
        fprintf(stderr, "Error: Invalid number of alien encounters.\n");
        exit(EXIT_FAILURE);
    }
    return (float)disasters / encounters * 100;
}

void paranoid_hypothesis() {
    // This function generates paranoid hypotheticals concerning aliens
    printf("Warning! Could these be signs of an impending alien invasion?\n");
    printf("1. Increased satellite activity!\n");
    printf("2. Unexplained crop circles in your neighborhood!\n");
    printf("3. The rising number of UFO sightings!\n");
}

void simulate_encounter(int *encounters, int *disasters) {
    // Simulate alien encounters and outcomes with paranoia!
    int simulated_encounters = rand() % 10; // Random encounters
    int simulated_disasters = rand() % (simulated_encounters + 1); // Random disasters, up to encounters
    
    *encounters += simulated_encounters;
    *disasters += simulated_disasters;
    
    printf("Simulated %d encounters with aliens, resulted in %d disasters.\n", simulated_encounters, simulated_disasters);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int total_encounters = 0; // Total alien encounters
    int total_disasters = 0; // Total disasters
    char continue_simulation = 'y';

    printf("***** ALIEN INVASION PROBABILITY CALCULATOR *****\n");
    
    while (continue_simulation == 'y') {
        paranoid_hypothesis(); // Display the warning
        simulate_encounter(&total_encounters, &total_disasters); // Simulate encounters

        // Calculate the probability of invasion based on simulated data
        float invasion_probability = calculate_invasion_probability(total_encounters, total_disasters);
        printf("Current probability of alien invasion: %.2f%%\n", invasion_probability);
        
        printf("Do you want to continue the simulation? (y/n): ");
        scanf(" %c", &continue_simulation);
        
        if (continue_simulation != 'y' && continue_simulation != 'n') {
            fprintf(stderr, "Error: Invalid input. Please enter 'y' or 'n'.\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Final total encounters: %d\n", total_encounters);
    printf("Final total disasters: %d\n", total_disasters);
    printf("Final invasion probability: %.2f%%\n", calculate_invasion_probability(total_encounters, total_disasters));
    printf("Stay alert, humanity!\n");

    return 0;
}