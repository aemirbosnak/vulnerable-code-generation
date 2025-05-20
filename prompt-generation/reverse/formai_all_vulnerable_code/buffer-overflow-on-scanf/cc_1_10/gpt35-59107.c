//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int earth_population = 7000000000;
    int alien_spacecrafts = 50;
    float invasion_probability = 0.0;
    
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    
    printf("Please enter the total number of alien spacecrafts detected: ");
    scanf("%d", &alien_spacecrafts);
    
    if(alien_spacecrafts == 0) {
        printf("Phew! Looks like Earth is safe for now.\n");
        return 0;
    }
    
    invasion_probability = (float)alien_spacecrafts / (float)earth_population;
    
    printf("\nCalculating invasion probability based on the following parameters:\n");
    printf("Total alien spacecrafts detected: %d\n", alien_spacecrafts);
    printf("Earth population: %d\n", earth_population);
    
    printf("\nOne moment please...\n\n");
    
    // Simulating invasion likelihood with random events
    int i;
    for(i = 0; i < 5; i++) {
        int random_event = rand() % 10 + 1;
        switch(random_event) {
            case 1:
                invasion_probability += 0.05;
                printf("Unexpected solar flare activity increasing alien invasion probability by 5%%.\n");
                break;
            case 2:
            case 3:
                invasion_probability += 0.01;
                printf("Minor alien spaceship sightings increasing invasion probability by 1%%.\n");
                break;
            case 4:
            case 5:
                invasion_probability += 0.02;
                printf("Reports of alien communications increasing invasion probability by 2%%.\n");
                break;
            default:
                printf("No significant events detected.\n");
        }
    }
    
    printf("\nBased on current observations and simulated events, the likelihood of an alien invasion is: %.2f%%\n",invasion_probability*100);
    
    printf("\nStay vigilant, Earthlings!\n");
    
    return 0;
}