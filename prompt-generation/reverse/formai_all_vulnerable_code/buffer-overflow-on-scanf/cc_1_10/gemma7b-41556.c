//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{

    // Alien Invasion Probability Calculator

    // Variables
    int year, month, day, hour, minute, alien_presence, alien_strength, earth_defense_strength;
    float probability, alien_invasion_likelihood;

    // Get the current year, month, day, hour, and minute
    printf("Enter the current year: ");
    scanf("%d", &year);

    printf("Enter the current month (1-12): ");
    scanf("%d", &month);

    printf("Enter the current day: ");
    scanf("%d", &day);

    printf("Enter the current hour: ");
    scanf("%d", &hour);

    printf("Enter the current minute: ");
    scanf("%d", &minute);

    // Get the alien presence and strength
    printf("Enter the alien presence (0-10): ");
    scanf("%d", &alien_presence);

    printf("Enter the alien strength (0-10): ");
    scanf("%d", &alien_strength);

    // Get the Earth defense strength
    printf("Enter the Earth defense strength (0-10): ");
    scanf("%d", &earth_defense_strength);

    // Calculate the probability of alien invasion
    probability = (0.05 * alien_presence) + (0.1 * alien_strength) - (0.02 * earth_defense_strength);

    // Calculate the alien invasion likelihood
    alien_invasion_likelihood = probability * 100;

    // Print the probability of alien invasion
    printf("The probability of alien invasion is: %.2f%%", alien_invasion_likelihood);

    return 0;
}