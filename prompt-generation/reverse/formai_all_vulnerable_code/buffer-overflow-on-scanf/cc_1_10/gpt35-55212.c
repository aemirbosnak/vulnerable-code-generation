//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initializing the random number generator

    float city_population, aliens_strength, alien_attack_probability;
    int cities, aliens, destroyed = 0, surviving = 0;
    
    printf("Enter the city population and the strength of the aliens:\n");
    scanf("%f%f", &city_population, &aliens_strength);
    
    printf("Enter the number of cities you want to simulate:\n");
    scanf("%d", &cities);
    
    printf("Enter the number of aliens you want to simulate for each city:\n");
    scanf("%d", &aliens);
    
    printf("Simulating %d cities with %d aliens...\n", cities, aliens);
    
    for (int i = 1; i <= cities; i++)
    {
        printf("Simulating city %d...\n", i);
        int alien_attack_count = 0;
        for (int j = 1; j <= aliens; j++)
        {
            float alien_strength = (rand() % 10) + aliens_strength; // Generating random alien strength
            int result = (rand() % 100) + 1; // Generating random probability of the alien attacking
            
            if (result <= alien_strength) // Checking if the alien attacks
            {
                alien_attack_count++;
            }
        }
        if (alien_attack_count >= (city_population * 0.2)) // Checking if the city is destroyed
        {
            printf("City %d has been destroyed by the aliens.\n", i);
            destroyed++;
        }
        else // City is surviving
        {
            printf("City %d has survived the alien attack.\n", i);
            surviving++;
        }
    }
    printf("%d cities have been destroyed and %d cities have survived out of %d simulated cities.\n", destroyed, surviving, cities);
    alien_attack_probability = (float)destroyed / cities; // Calculating the overall probability of alien attack
    printf("The probability of an alien invasion is %f\n", alien_attack_probability);
    return 0;
}