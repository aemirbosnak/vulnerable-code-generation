//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int probability = 0;
    srand(time(NULL));
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Enter the number of alien ships that have been detected in the vicinity: ");
    int alienShips;
    scanf("%d", &alienShips);
    if(alienShips <= 0)
    {
        printf("There are no alien ships detected, so the probability of an invasion is 0%%.\n");
        return 0;
    }
    printf("\nEnter the level of military readiness on a scale of 1 to 10: ");
    int readiness;
    scanf("%d", &readiness);
    if(readiness < 1 || readiness > 10)
    {
        printf("Invalid input. Military readiness must be between 1 and 10.\n");
        return 0;
    }
    probability += (alienShips * 20) / readiness;
    printf("\nEnter the number of years that have passed since the last major war: ");
    int yearsSinceWar;
    scanf("%d", &yearsSinceWar);
    if(yearsSinceWar < 0)
    {
        printf("Invalid input. Years since the last major war cannot be negative.\n");
        return 0;
    }
    if(yearsSinceWar >= 50)
    {
        probability += 30;
    }
    else if(yearsSinceWar >= 25)
    {
        probability += 20;
    }
    else if(yearsSinceWar >= 10)
    {
        probability += 10;
    }
    printf("\nEnter the average temperature of the planet in Celsius: ");
    int avgTemp;
    scanf("%d", &avgTemp);
    if(avgTemp < -273 || avgTemp > 100)
    {
        printf("Invalid input. Average temperature of the planet must be between -273 and 100 Celsius.\n");
        return 0;
    }
    probability += (100 - avgTemp) / 2;
    if(probability > 100)
    {
        probability = 100;
    }
    printf("\nBased on the input, the probability of an alien invasion is %d%%.\n", probability);
    return 0;
}