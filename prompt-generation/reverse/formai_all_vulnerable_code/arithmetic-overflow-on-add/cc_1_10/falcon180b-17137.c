//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate alien invasion
int alien_invasion(int population, int technology_level, int military_strength) {
    int success = rand_num(0, 100);
    if (success < (population + technology_level + military_strength) / 3) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// Main function
int main() {
    int population, technology_level, military_strength, invasion_success;
    double probability;

    // Get user input
    printf("Enter the population of the planet: ");
    scanf("%d", &population);
    printf("Enter the technology level of the planet: ");
    scanf("%d", &technology_level);
    printf("Enter the military strength of the planet: ");
    scanf("%d", &military_strength);

    // Simulate 1000 alien invasions
    int invasion_count = 0;
    for (int i = 0; i < 1000; i++) {
        invasion_success = alien_invasion(population, technology_level, military_strength);
        if (invasion_success) {
            invasion_count++;
        }
    }

    // Calculate and display the probability of a successful alien invasion
    probability = (double) invasion_count / 1000;
    printf("The probability of a successful alien invasion is %.2f%%\n", probability * 100);

    return 0;
}