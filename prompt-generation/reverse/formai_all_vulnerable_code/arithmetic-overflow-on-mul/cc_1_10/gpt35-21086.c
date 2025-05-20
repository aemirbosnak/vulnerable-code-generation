//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculateProbability(int population, int militaryStrength, int alienStrength)
{
    int probability = ((alienStrength * 100) / (population + militaryStrength));
    return probability;
}

int main()
{
    int population, militaryStrength, alienStrength;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the current population of your city: ");
    scanf("%d", &population);

    printf("Please enter the military strength in your city: ");
    scanf("%d", &militaryStrength);

    printf("Please enter the estimated strength of the alien invasion force: ");
    scanf("%d", &alienStrength);

    srand(time(NULL));
    int random = rand() % 100 + 1;

    int probability = calculateProbability(population, militaryStrength, alienStrength);

    printf("\nThe probability of an alien invasion is %d%%.\n", probability);

    if(probability <= 20)
    {
        printf("It is highly unlikely that an alien invasion will occur.\n");
    }
    else if(probability > 20 && probability <= 50)
    {
        printf("There is a moderate chance of an alien invasion.\n");
        printf("Our advice is to stay alert and be prepared for any situation.\n");
    }
    else if(probability > 50 && probability <= 80)
    {
        printf("There is a high chance of an alien invasion.\n");
        printf("We recommend taking necessary precautions and emergency preparedness measures.\n");
    }
    else
    {
        if(random <= 50)
        {
            printf("An alien invasion is imminent!\n");
            printf("Please seek shelter immediately and follow all emergency protocols!\n");
        }
        else
        {
            printf("The probability of an alien invasion is too high!\n");
            printf("We recommend taking all necessary precautions and being prepared for any situation.\n");
        }
    }

    return 0;
}