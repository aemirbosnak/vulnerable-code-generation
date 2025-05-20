//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a planet type
int generatePlanetType()
{
    return rand() % 3;
}

// Function to print planet type
void printPlanetType(int planetType)
{
    if (planetType == 0)
        printf("Rocky planet\n");
    else if (planetType == 1)
        printf("Gaseous planet\n");
    else
        printf("Ice planet\n");
}

int main()
{
    srand(time(NULL)); // Initialize random seed

    int planetCount = rand() % 10 + 1; // Generate random number of planets
    int visitedPlanets = 0;
    int fuel = 100;

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("There are %d planets in this galaxy.\n", planetCount);

    while (visitedPlanets < planetCount && fuel > 0)
    {
        int planetType = generatePlanetType();

        printf("\n");

        if (planetType == 0)
            printf("You have arrived at a rocky planet.\n");
        else if (planetType == 1)
            printf("You have arrived at a gaseous planet.\n");
        else
            printf("You have arrived at an ice planet.\n");

        printf("Do you want to land on this planet? (y/n)\n");

        char input;
        scanf(" %c", &input);

        if (input == 'y')
        {
            printf("Landing...\n");

            // Simulating landing process
            for (int i = 10; i >= 0; i--)
            {
                printf("%d seconds until landing...\n", i);
                sleep(1);
            }

            printf("You have successfully landed on the planet!\n");

            printPlanetType(planetType);

            // Simulate exploring the planet
            printf("Exploring the planet...\n");
            sleep(2);

            printf("You have discovered a new species!\n");
            printf("Do you want to collect a sample? (y/n)\n");

            scanf(" %c", &input);

            if (input == 'y')
                printf("You have collected a sample.\n");
            else
                printf("You have chosen not to collect a sample.\n");

            // Simulating taking off process
            printf("Taking off...\n");

            for (int i = 0; i <= 10; i++)
            {
                printf("%d seconds until takeoff...\n", i);
                sleep(1);
            }

            printf("You have successfully taken off from the planet!\n");

            visitedPlanets++;
        }
        else
        {
            printf("You have decided not to land on this planet.\n");
        }

        fuel--;

        printf("You have %d units of fuel remaining.\n", fuel);
    }

    if (visitedPlanets == planetCount)
        printf("Congratulations, you have visited all the planets in this galaxy!\n");
    else
        printf("\nYou have run out of fuel, ending your adventure...\n");

    return 0;
}