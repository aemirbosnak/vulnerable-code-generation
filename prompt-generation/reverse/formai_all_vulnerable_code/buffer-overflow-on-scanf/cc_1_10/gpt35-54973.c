//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_planets, probability, total_prob = 0, i;
    char response;
    srand(time(0)); // seed random number generator
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many planets are in your solar system? ");
    scanf("%d", &num_of_planets);
    
    printf("\nCalculating probability of alien invasion for each planet...\n");
    
    for(i=1; i<=num_of_planets; i++) {
        probability = rand() % 101; // generate random probability between 0 and 100
        total_prob += probability; // add probability to total probability
        printf("\nPlanet %d: Probability of Alien Invasion is %d%%", i, probability);
    }
    
    // calculate average probability and display final message
    float avg_prob = total_prob / (float)num_of_planets;
    printf("\n\nThe average probability of Alien Invasion for your solar system is %.2f%%", avg_prob);
    printf("\n\nDo you want to calculate Alien Invasion Probability for another solar system? (Y/N) ");
    scanf(" %c", &response);
    
    // repeat process if user wants to calculate another system
    while(response == 'Y' || response == 'y') {
        total_prob = 0;
        printf("\nHow many planets are in your solar system? ");
        scanf("%d", &num_of_planets);
        
        printf("\nCalculating probability of alien invasion for each planet...\n");
        
        for(i=1; i<=num_of_planets; i++) {
            probability = rand() % 101; // generate random probability between 0 and 100
            total_prob += probability; // add probability to total probability
            printf("\nPlanet %d: Probability of Alien Invasion is %d%%", i, probability);
        }
        
        // calculate average probability and display final message
        avg_prob = total_prob / (float)num_of_planets;
        printf("\n\nThe average probability of Alien Invasion for your solar system is %.2f%%", avg_prob);
        printf("\n\nDo you want to calculate Alien Invasion Probability for another solar system? (Y/N) ");
        scanf(" %c", &response);
    }
    
    printf("\nThank you for using the Alien Invasion Probability Calculator!");
    
    return 0;
}