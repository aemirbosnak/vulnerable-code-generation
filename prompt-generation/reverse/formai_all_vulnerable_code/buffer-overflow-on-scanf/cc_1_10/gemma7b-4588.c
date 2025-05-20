//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653

int main()
{
    double alien_invasion_probability, distance_from_sun, number_of_nearby_asteroids;

    printf("Greetings, traveler.\n");
    printf("Would you like to calculate the probability of an alien invasion?\n");
    printf("Yes/No (Y/N): ");

    char answer;
    scanf("%c", &answer);

    if (answer == 'Y' || answer == 'y')
    {
        printf("Please provide the following information:\n");
        printf("1. Distance from the Sun (in light-years): ");
        scanf("%lf", &distance_from_sun);

        printf("2. Number of nearby asteroids: ");
        scanf("%d", &number_of_nearby_asteroids);

        alien_invasion_probability = 0.0;

        // Calculate the probability of alien invasion based on the distance from the Sun and the number of nearby asteroids
        if (distance_from_sun < 10)
        {
            alien_invasion_probability = 0.25;
        }
        else if (distance_from_sun < 20)
        {
            alien_invasion_probability = 0.15;
        }
        else if (distance_from_sun < 30)
        {
            alien_invasion_probability = 0.05;
        }
        else
        {
            alien_invasion_probability = 0.01;
        }

        // Calculate the probability of alien invasion based on the number of nearby asteroids
        if (number_of_nearby_asteroids > 10)
        {
            alien_invasion_probability *= 2;
        }
        else if (number_of_nearby_asteroids > 20)
        {
            alien_invasion_probability *= 3;
        }
        else if (number_of_nearby_asteroids > 30)
        {
            alien_invasion_probability *= 4;
        }

        // Print the probability of alien invasion
        printf("The probability of an alien invasion is: %.2f%%", alien_invasion_probability * 100);
    }
    else
    {
        printf("Thank you for your time.\n");
    }

    return 0;
}