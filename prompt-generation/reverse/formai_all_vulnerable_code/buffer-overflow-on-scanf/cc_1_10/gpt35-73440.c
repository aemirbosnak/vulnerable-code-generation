//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

/* Cryptic Space Adventure */
int main()
{
    printf("Welcome to Cryptic Space Adventure!\n");

    /* Initialize variables */
    int oxygen = 100, fuel = 100, currency = 500, health = 100,  planet_choice, code_choice;
    char name[20], answer;

    /* Get player's name */
    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    printf("Welcome aboard, %s!\n", name);

    /* Start of the adventure */
    printf("\nYou wake up in a spaceship, distant from Earth, with no memory of how you got there.\n");
    printf("You notice that your vital systems are running low and your ship is running out of fuel.\n");
    printf("You must find a planet to land on and a way to refuel your ship.\n");

    /* Planet selection */
    printf("\nYou receive a transmission from your onboard computer, which lists three planets within range of your ship.\n");
    printf("Please select a destination:\n1. Planet Zor\n2. Planet Crypt\n3. Planet Xanthe\n");
    scanf("%d", &planet_choice);

    /* Arrival at the planet */
    printf("\nYour ship touches down on Planet %d.\n", planet_choice);

    /* Random event - asteroid belt */
    if (planet_choice == 3)
    {
        printf("As you navigate through space, you enter a dense asteroid belt.\n");
        printf("You must choose the correct code to navigate through the asteroid belt.\n");
        printf("1. 2201, 4082, 4533\n2. 1223, 0000, 5231\n3. 2312, 3663, 8683\n");
        scanf("%d", &code_choice);

        if (code_choice == 3)
        {
            printf("You successfully navigate through the asteroid belt, unscathed.\n");
        }
        else
        {
            printf("Your ship is hit by several asteroids, causing significant damage to the hull and reducing your health by 20 points.\n");
            health -= 20;
        }
    }

    /* Random event - alien encounter */
    if (planet_choice == 2)
    {
        printf("As you explore the planet, you come across a group of aliens.\n");
        printf("They appear to be wary of your presence and demand that you solve a puzzle to continue.\n");
        printf("What has a heart that doesn't beat? (one word answer)\n");
        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, "artichoke") == 0)
        {
            printf("The aliens are impressed by your intelligence and give you a gift of %d currency.\n", 50);
            currency += 50;
        }
        else
        {
            printf("The aliens are displeased with your answer and attack.\n");
            printf("You manage to fend them off and escape, but your health is reduced by 30 points.\n");
            health -= 30;
        }
    }

    /* Refueling */
    fuel = 100;
    printf("\nYou find a fuel source on Planet %d and successfully refuel your ship.\n", planet_choice);

    /* Random event - oxygen leak */
    if (planet_choice == 1)
    {
        printf("As you prepare to leave the planet, you discover an oxygen leak in your ship.\n");
        printf("You must select the correct valve to repair the leak.\n");
        printf("1. Blue Valve\n2. Red Valve\n3. Green Valve\n");
        scanf("%d", &code_choice);

        if (code_choice == 2)
        {
            printf("You successfully repair the oxygen leak and continue your journey.\n");
            oxygen = 100;
        }
        else
        {
            printf("You fail to repair the oxygen leak and slowly suffocate, losing all remaining health points.\n");
            health = 0;
        }
    }

    /* End of Adventure */
    printf("\nYou arrive safely back on Earth with a full tank of fuel and a refreshed oxygen supply.\n");
    printf("Final Stats:\nName: %s\nHealth: %d\nFuel: %d\nOxygen: %d\nCurrency: %d\n", name, health, fuel, oxygen, currency);

    return 0;
}