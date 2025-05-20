//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define functions
void planetGenerator();
void asteroidBelt();
void spaceStation();

// Define global variables
int fuel = 100;
int distance = 0;

int main()
{
    srand(time(NULL)); // Initialize random number generator

    printf("Welcome to Procedural Space Adventure!\n\n");

    while (fuel > 0 && distance < 100)
    {
        printf("Current fuel level: %d\n", fuel);
        printf("Current distance traveled: %d\n\n", distance);

        printf("What do you want to do?\n");
        printf("1) Travel to another planet\n");
        printf("2) Navigate through an asteroid belt\n");
        printf("3) Visit a space station to refuel\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                planetGenerator();
                break;
            case 2:
                asteroidBelt();
                break;
            case 3:
                spaceStation();
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    if (distance >= 100)
    {
        printf("Congratulations! You completed the journey.\n");
    }
    else
    {
        printf("Game over. You ran out of fuel.\n");
    }

    return 0;
}

void planetGenerator()
{
    int planetDistance = rand() % 50 + 1;
    distance += planetDistance;
    fuel -= planetDistance;

    int planetType = rand() % 3 + 1;

    switch (planetType)
    {
        case 1:
            printf("You landed on a habitable planet.\n");
            break;
        case 2:
            printf("You landed on a barren planet.\n");
            break;
        case 3:
            printf("You landed on an ice planet.\n");
            break;
    }

    printf("Distance traveled: %d\n", planetDistance);
    printf("Fuel consumed: %d\n\n", planetDistance);
}

void asteroidBelt()
{
    int asteroidDistance = rand() % 30 + 1;
    distance += asteroidDistance;
    fuel -= asteroidDistance;

    printf("You are navigating through an asteroid belt.\n");
    printf("Distance traveled: %d\n", asteroidDistance);
    printf("Fuel consumed: %d\n\n", asteroidDistance);
}

void spaceStation()
{
    int stationDistance = rand() % 20 + 1;
    distance += stationDistance;

    int refuelAmount = rand() % 50 + 1;
    fuel += refuelAmount;

    printf("You landed on a space station to refuel.\n");
    printf("Distance traveled: %d\n", stationDistance);
    printf("Fuel refueled: %d\n\n", refuelAmount);
}