//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int alien_invasion_probability()
{
    int num_ships, num_fighters, year, alien_strength, earth_defense;

    printf("Please enter the number of alien ships you have encountered: ");
    scanf("%d", &num_ships);

    printf("Please enter the number of alien fighters you have encountered: ");
    scanf("%d", &num_fighters);

    printf("Please enter the year in which the invasion occurred: ");
    scanf("%d", &year);

    printf("Please enter the alien strength (1-10): ");
    scanf("%d", &alien_strength);

    printf("Please enter the Earth defense strength (1-10): ");
    scanf("%d", &earth_defense);

    int probability = 0;

    if (num_ships > 10)
    {
        probability++;
    }

    if (num_fighters > 20)
    {
        probability++;
    }

    if (year < 2000)
    {
        probability++;
    }

    if (alien_strength >= 8)
    {
        probability++;
    }

    if (earth_defense <= 6)
    {
        probability++;
    }

    return probability;
}

int main()
{
    int alien_invasion_probability_result = alien_invasion_probability();

    printf("Your alien invasion probability is: %d%%", alien_invasion_probability_result);

    return 0;
}