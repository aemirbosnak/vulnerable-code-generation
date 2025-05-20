//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l;
    float probability;
    int num_aliens, num_survivors, num_attempts, num_wins;
    srand(time(NULL)); // seed the random number generator with the current time
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will calculate the probability of surviving an alien invasion with specified variables.\n\n");
    
    // get user input for number of aliens, survivors, attempts, and wins
    printf("Enter number of aliens: ");
    scanf("%d", &num_aliens);
    printf("Enter number of survivors: ");
    scanf("%d", &num_survivors);
    printf("Enter number of attempts: ");
    scanf("%d", &num_attempts);
    printf("Enter number of wins: ");
    scanf("%d", &num_wins);
    printf("\n");
    
    // calculate probability of survival based on user input
    int outcome[num_attempts];
    for (i = 0; i < num_attempts; i++) {
        int alien_health[num_aliens];
        for (j = 0; j < num_aliens; j++) {
            alien_health[j] = 100; // set initial health of each alien to 100
        }
        int num_dead = 0;
        for (k = 0; k < num_aliens; k++) {
            int survivor = rand() % num_survivors; // randomly select a survivor to attack alien
            int damage = rand() % 50 + 1; // determine amount of damage done to alien (between 1 and 50)
            alien_health[k] -= damage; // subtract damage from alien's health
            if (alien_health[k] <= 0) {
                num_dead++; // increase count of dead aliens
            }
            if (num_dead == num_aliens) {
                outcome[i] = 1; // all aliens are dead, outcome is a win
                break;
            }
            if (outcome[i] != 1 && k == (num_aliens - 1)) {
                outcome[i] = 0; // at least one alien is still alive, outcome is a loss
            }
        }
    }
    int num_wins_calculated = 0;
    for (l = 0; l < num_attempts; l++) {
        if (outcome[l] == 1) {
            num_wins_calculated++; // count number of calculated wins
        }
    }
    probability = (float)num_wins_calculated / num_attempts; // calculate probability of winning the invasion
    
    // display the results to the user
    printf("Based on your input, there is a %f%% chance of surviving an alien invasion.\n", probability*100);
    printf("Good luck!\n");
    
    return 0;
}