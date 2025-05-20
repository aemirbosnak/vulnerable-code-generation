//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int planets, threat_level, invasion_probability, i, j;
    srand(time(NULL)); // seeding the random number generator with current time
    
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the number of planets in the galaxy: ");
    scanf("%d", &planets);
    
    int planet_threats[planets]; // array to store the threat level of each planet
    
    for (i = 0; i < planets; i++) {
        printf("Enter the threat level (0-100) for planet %d: ", i+1);
        scanf("%d", &threat_level);
        
        if (threat_level < 0) { // validating input
            printf("Invalid threat level. Please try again.\n");
            i--; // decrementing i so that the user is prompted for the current planet again
        } else {
            planet_threats[i] = threat_level; // storing the threat level of the planet in the array
        }
    }
    
    printf("\nCalculating invasion probability...\n\n");
    invasion_probability = 0;
    
    for (i = 0; i < planets; i++) {
        for (j = i + 1; j < planets; j++) { // nested loop to compare each planet with every other planet
            int temp_probability = (planet_threats[i] + planet_threats[j]) / 2; // calculating probability for the current pair of planets
            invasion_probability += temp_probability;
            
            printf("Probability of invasion for planets %d and %d: %d%%\n", i+1, j+1, temp_probability);
        }
    }
    
    invasion_probability /= (planets * (planets-1)) / 2; // calculating the average probability of invasion for all pairs of planets
    
    printf("\nAverage probability of invasion: %d%%\n", invasion_probability);
    
    if (invasion_probability > 50) {
        printf("The galaxy is at high risk of an alien invasion!\n");
    } else {
        printf("The galaxy is safe for now.\n");
    }
    
    return 0;
}