//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void explorePlanet(int planetNumber, int fuelLevel);

int main()
{
    int fuelLevel = 100;
    int planetNumber = 1;
    char input;

    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
    printf("Your ship currently has %d units of fuel.\n", fuelLevel);

    while(planetNumber <= 5 && fuelLevel > 0)
    {
        printf("\nYou are currently on planet %d.\n", planetNumber);
        printf("Press 'e' to explore the planet or 'n' to go to the next planet.\n");

        scanf(" %c", &input);

        switch(input)
        {
            case 'e':
                explorePlanet(planetNumber, fuelLevel);
                break;
            case 'n':
                planetNumber++;
                printf("You are now on your way to planet %d.\n", planetNumber);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    if (fuelLevel <= 0)
    {
        printf("\nYou ran out of fuel and your mission has failed. Game over.\n");
    }
    else
    {
        printf("\nCongratulations! You have successfully explored all 5 planets.\n");
        printf("Your ship returned safely to Earth.\n");
    }

    return 0;
}

void explorePlanet(int planetNumber, int fuelLevel)
{
    int randNum = rand() % 100 + 1;

    if (randNum < fuelLevel)
    {
        printf("\nCongratulations! You have found a new element that will boost your fuel by 20 units.\n");
        fuelLevel += 20;
        printf("Your ship now has %d units of fuel.\n", fuelLevel);
    }
    else
    {
        printf("\nOh no! You did not find anything on this planet.\n");
        printf("Your ship still has %d units of fuel.\n", fuelLevel);
    }
}