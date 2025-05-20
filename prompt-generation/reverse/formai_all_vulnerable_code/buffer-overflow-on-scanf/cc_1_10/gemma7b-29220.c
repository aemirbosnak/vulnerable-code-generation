//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int alien_invasion_probability = 0;
    float probability_of_destruction = 0.0f;
    char astrological_sign = ' ';

    printf("Welcome to the Galactic Probability Calculator!\n");
    printf("Please provide your astrological sign: ");
    scanf(" %c", &astrological_sign);

    switch (astrological_sign)
    {
        case 'A':
            alien_invasion_probability = 20;
            break;
        case 'B':
            alien_invasion_probability = 30;
            break;
        case 'C':
            alien_invasion_probability = 40;
            break;
        case 'D':
            alien_invasion_probability = 50;
            break;
        case 'E':
            alien_invasion_probability = 60;
            break;
        case 'F':
            alien_invasion_probability = 70;
            break;
        case 'G':
            alien_invasion_probability = 80;
            break;
        case 'H':
            alien_invasion_probability = 90;
            break;
        case 'I':
            alien_invasion_probability = 100;
            break;
        default:
            printf("Invalid astrological sign.\n");
            break;
    }

    probability_of_destruction = (float)alien_invasion_probability / 100.0f;

    printf("Your astrological sign is: %c\n", astrological_sign);
    printf("The probability of alien invasion for your sign is: %.2f%\n", probability_of_destruction * 100);

    return 0;
}