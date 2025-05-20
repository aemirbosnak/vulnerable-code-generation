//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototype
int generateRandomNumber(int min, int max);

int main()
{
    int distance = 0;
    int steps = 0;
    int alienEncounterChance = 0;

    printf("Welcome to Procedural Space Adventure!\n");

    // get user input for distance
    while(distance < 50 || distance > 1000)
    {
        printf("Enter the distance you want to travel (between 50 and 1000 light-years): ");
        scanf("%d", &distance);

        if(distance < 50 || distance > 1000)
        {
            printf("Invalid distance input! Please try again.\n\n");
        }
    }

    // initialize random seed
    srand(time(NULL));

    // start space adventure loop
    while(steps < distance)
    {
        int randomStep = generateRandomNumber(1, 10);

        steps += randomStep;

        // check if alien encounter occurs
        alienEncounterChance += 20;
        int randomAlienEncounter = generateRandomNumber(0, 100);

        if(randomAlienEncounter < alienEncounterChance)
        {
            printf("\n=========================================\n");
            printf("\nWARNING: ALIEN ENCOUNTER DETECTED!\n");
            printf("\n=========================================\n\n");

            // determine player's encounter fate
            int randomFate = generateRandomNumber(1, 3);

            if(randomFate == 1)
            {
                printf("You have been captured by aliens and taken to their home planet. Game over!\n");
                exit(0);
            }
            else if(randomFate == 2)
            {
                printf("You have successfully defeated the aliens and continue on your space adventure.\n\n");
                alienEncounterChance = 0;
            }
            else
            {
                printf("You have managed to escape the aliens but have lost valuable supplies. Keep moving forward.\n\n");
                steps -= 10;
                alienEncounterChance = 0;
            }
        }

        printf("You have taken %d steps and have %d more to go.\n", randomStep, distance - steps);

        // generate random event
        int randomEvent = generateRandomNumber(1, 4);

        switch(randomEvent)
        {
            case 1:
                printf("The ship's engine needs repair. You lose 5 steps.\n\n");
                steps -= 5;
                break;
            case 2:
                printf("You encounter a strange asteroid field and must navigate carefully. You lose 3 steps.\n\n");
                steps -= 3;
                break;
            case 3:
                printf("A sudden solar flare disrupts communication equipment. You lose 2 steps.\n\n");
                steps -= 2;
                break;
            default:
                printf("You come across a new planet and rest for a bit. You gain 4 steps.\n\n");
                steps += 4;
                break;
        }
    }

    printf("Congratulations! You have completed the space adventure and traveled %d light-years.\n", distance);

    return 0;
}

// function definition for generating a random number between min and max
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}