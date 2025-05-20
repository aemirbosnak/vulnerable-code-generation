//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define variables
    float invasion_chance;
    int human_population, alien_ships, defense_budget;
    int i;
    int lucky_numbers[5];

    // Get input from user
    printf("Enter the human population: ");
    scanf("%d", &human_population);
    printf("Enter the number of alien ships: ");
    scanf("%d", &alien_ships);
    printf("Enter the defense budget (in millions): ");
    scanf("%d", &defense_budget);

    // Calculate invasion chance
    invasion_chance = (float)alien_ships / human_population * 100;

    // Print out results
    printf("\n\nAlien Invasion Probability Calculator\n-------------------------------------\n");
    printf("Human Population: %d\n", human_population);
    printf("Number of Alien Ships: %d\n", alien_ships);
    printf("Defense Budget: $%d million\n", defense_budget);
    printf("Invasion Chance: %.2f%%\n\n", invasion_chance);

    // Generate five lucky numbers between 1-10
    srand(time(NULL));
    printf("Your lucky numbers: ");
    for(i = 0; i < 5; i++)
    {
        lucky_numbers[i] = rand() % 10 + 1;
        printf("%d ", lucky_numbers[i]);
    }
    printf("\n");

    // Check if defense budget can buy enough weapons
    if(defense_budget >= 500 && defense_budget < 1000)
    {
        printf("With this budget, you can buy enough weapons to defend against a small alien fleet.\n");
    }
    else if(defense_budget >= 1000 && defense_budget < 5000)
    {
        printf("With this budget, you can buy enough weapons to defend against a medium-sized alien fleet.\n");
    }
    else if(defense_budget >= 5000)
    {
        printf("With this budget, you can buy enough weapons to defend against a large alien fleet.\n");
    }
    else
    {
        printf("With this budget, you cannot afford to defend against an alien invasion. Consider increasing your defense budget.\n");
    }

    return 0;
}