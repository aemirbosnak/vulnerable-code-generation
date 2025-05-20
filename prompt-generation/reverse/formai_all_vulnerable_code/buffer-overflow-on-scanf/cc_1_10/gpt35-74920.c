//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    
    srand(time(0));
    
    int numPlanets = 0, numAliens = 0;
    float probInvasion = 0;
    
    while (numPlanets <= 0)
    {
        printf("Enter the number of planets in the galaxy: ");
        if(scanf("%d", &numPlanets) != 1 || numPlanets < 1)
        {
            printf("Invalid input. Please enter a positive integer greater than zero.\n\n");
            fflush(stdin);
            numPlanets = 0;
        }
    }
    
    while (numAliens <= 0)
    {
        printf("Enter the number of alien civilizations in the galaxy: ");
        if(scanf("%d", &numAliens) != 1 || numAliens < 1)
        {
            printf("Invalid input. Please enter a positive integer greater than zero.\n\n");
            fflush(stdin);
            numAliens = 0;
        }
    }
    
    probInvasion = (float)numAliens/numPlanets + (float)(rand() % 100)/100;
    
    printf("\nCalculating probability of alien invasion...\n\n");
    
    int count = 0;
    while(count < 10)
    {
        printf("...");
        sleep(1);
        count++;
    }
    
    printf("\n\nProbability of alien invasion is: ");
    if(probInvasion > 0.5)
    {
        printf("%.2f%%\n\n", probInvasion * 100);
        printf("Wow! Looks like the aliens have a good chance of invading the galaxy!\n");
        printf("Better get ready for the attack!\n");
    }
    else
    {
        printf("%.2f%%\n\n", probInvasion * 100);
        printf("Phew! It looks like we're safe from alien invasion for now!\n");
        printf("But remember to always be alert and watch the skies!\n");
    }
    
    return 0;
}