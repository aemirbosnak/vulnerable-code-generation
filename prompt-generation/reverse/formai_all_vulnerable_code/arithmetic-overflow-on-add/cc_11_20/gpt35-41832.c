//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_population, military_strength, alien_threat, invasion_probability;
    int alien_technology, planet_atmosphere, defense_plan;
    char response;

    // Collect input from user
    printf("Please enter the total population of the planet: ");
    scanf("%d", &total_population);
    printf("Please enter the military strength of the planet (in millions): ");
    scanf("%d", &military_strength);
    printf("Please rate the level of alien threat on a scale of 1-10: ");
    scanf("%d", &alien_threat);

    // Calculate initial invasion probability
    invasion_probability = (100 - (total_population + military_strength + alien_threat)) / 3;

    // Check if planet has advanced alien technology
    printf("Does the planet possess advanced alien technology? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        invasion_probability -= 15;
        alien_technology = 1;
    } else {
        alien_technology = 0;
    }

    // Check if atmosphere is favorable for alien invasion
    printf("Is the planet's atmosphere favorable for alien invasion? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        invasion_probability += 10;
        planet_atmosphere = 1;
    } else {
        planet_atmosphere = 0;
    }

    // Check if defense plan is in place
    printf("Is there a defense plan in place for alien invasion? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        invasion_probability -= 10;
        defense_plan = 1;
    } else {
        defense_plan = 0;
    }

    // Check for final invasion probability
    if (invasion_probability < 0) {
        invasion_probability = 0;
    } else if (invasion_probability > 100) {
        invasion_probability = 100;
    }

    // Print results to user
    printf("\n\n**********INVASION PROBABILITY**********\n\n");
    printf("Total population: %d\n", total_population);
    printf("Military strength: %d million\n", military_strength);
    printf("Alien threat level: %d/10\n", alien_threat);
    printf("Advanced alien technology: %s\n", (alien_technology ? "Yes" : "No"));
    printf("Favorable atmosphere: %s\n", (planet_atmosphere ? "Yes" : "No"));
    printf("Defense plan in place: %s\n", (defense_plan ? "Yes" : "No"));
    printf("Invasion probability: %d%%\n\n", invasion_probability);

    return 0;
}