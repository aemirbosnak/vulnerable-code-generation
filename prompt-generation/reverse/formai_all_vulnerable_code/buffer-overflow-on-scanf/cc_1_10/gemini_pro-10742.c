//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int seed;
    int num_planets;
    int num_aliens;
    int num_invasions;
    int i, j, k;
    double probability;
    
    // Get the current time as a seed for the random number generator.
    seed = time(NULL);
    srand(seed);
    
    // Get the number of planets, aliens, and invasions from the user.
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);
    printf("Enter the number of invasions: ");
    scanf("%d", &num_invasions);
    
    // Calculate the probability of an invasion occurring.
    probability = (double)num_aliens / (double)(num_planets * num_invasions);
    
    // Print the probability of an invasion occurring.
    printf("The probability of an invasion occurring is: %f\n", probability);
    
    // Loop through the number of planets and aliens.
    for (i = 0; i < num_planets; i++)
    {
        for (j = 1; j < num_aliens; j++)
        {
            // Loop through the number of invasions.
            for (k = 0; k < num_invasions; k++)
            {
                // Calculate the probability of an invasion occurring on a particular planet.
                probability = (double)j / (double)(num_aliens * num_invasions);
                
                // Print the probability of an invasion occurring on a particular planet.
                printf("The probability of an invasion occurring on planet %d is: %f\n", i, probability);
            }
        }
    }
    
    return 0;
}