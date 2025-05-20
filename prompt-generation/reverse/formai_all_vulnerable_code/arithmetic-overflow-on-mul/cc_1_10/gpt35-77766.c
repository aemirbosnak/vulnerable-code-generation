//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// calculates the probability of an alien invasion
float calculateProbability(int numYears, int numPlanets, int techLevel);

// helper function to generate a random integer between a and b
int getRandomInt(int a, int b);

int main()
{
    int numYears, numPlanets, techLevel;
    
    // get user input for the number of years, number of potentially habitable planets, and tech level
    printf("Enter the number of years: ");
    scanf("%d", &numYears);
    
    printf("Enter the number of potentially habitable planets: ");
    scanf("%d", &numPlanets);
    
    printf("Enter the tech level (1-10): ");
    scanf("%d", &techLevel);
    
    // calculate the probability of an alien invasion and print it out
    float probability = calculateProbability(numYears, numPlanets, techLevel);
    printf("\nThe probability of an alien invasion in the next %d years is %.2f%%\n", numYears, probability);

    return 0;
}

float calculateProbability(int numYears, int numPlanets, int techLevel)
{
    // seed the random number generator
    srand(time(NULL));
    
    // calculate the base probability as a function of tech level and number of planets
    float baseProb = 10 * techLevel * numPlanets / 1000.0;
    
    // calculate the additional probability based on the number of years
    int numEncounters = numYears / 10;
    float additionalProb = 0;
    for (int i = 0; i < numEncounters; i++)
    {
        // generate a random probability between 1 and 100
        int randProb = getRandomInt(1, 100);
        
        // if the random probability is less than or equal to the tech level, there has been an encounter
        if (randProb <= techLevel)
        {
            // add an additional probability of 10% per encounter
            additionalProb += 10;
        }
    }
    
    // calculate the final probability as the sum of the base probability and the additional probability
    float finalProb = baseProb + additionalProb;
    
    // make sure the probability is not greater than 100%
    if (finalProb > 100)
    {
        finalProb = 100;
    }
    
    return finalProb;
}

int getRandomInt(int a, int b)
{
    return rand() % (b - a + 1) + a;
}