//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed for random number generator
    int rollAgain = 1, sides = 0, numberOfDice = 0, i = 0, j = 0, total = 0;

    printf("Welcome to the paranoid Dice Roller. The government is always watching!\n");
    printf("How many sides do your dice have? Remember, less is more secure.\n");
    scanf("%d", &sides);
    if (sides < 2)
    {
        printf("You are trying to cheat, aren't you? You must be a spy.\n");
        return 0;
    }

    printf("How many dice do you want to roll? More dice means more suspicion.\n");
    scanf("%d", &numberOfDice);
    if (numberOfDice <= 0)
    {
        printf("Zero dice? What kind of spy are you?\n");
        return 0;
    }

    printf("You have chosen to roll %d dice with %d sides.\n\n", numberOfDice, sides);

    while (rollAgain == 1)
    {
        total = 0;
        printf("Rolling dice...\n");

        for (i = 0; i < numberOfDice; i++)
        {
            int roll = rand() % sides + 1; // Generate a random number between 1 and the number of sides on the dice
            printf("Die %d: %d\n", i + 1, roll);
            total += roll;
        }

        printf("Total: %d\n", total);
        printf("\nRoll again? 1 for yes, 0 for no.\n");
        scanf("%d", &rollAgain);

        if (rollAgain != 1 && rollAgain != 0)
        {
            printf("You must be trying to signal your handler. Program terminated.\n");
            return 0;
        }

        printf("\n");
    }

    printf("Thank you for using the paranoid Dice Roller. I'll report your roll to the authorities.\n");

    return 0;
}