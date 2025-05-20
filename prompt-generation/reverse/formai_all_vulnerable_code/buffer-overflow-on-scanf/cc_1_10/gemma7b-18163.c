//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a list of possible actions
    char *actions[] = {"Attack", "Cast Spell", "Negotiate", "Flee"};

    // Get the player's name
    char name[20];
    printf("What is your name, brave traveler? ");
    scanf("%s", name);

    // Generate a random encounter
    int encounter = rand() % 3;

    // Describe the encounter
    switch (encounter)
    {
        case 0:
            printf("You encounter a ferocious dragon! Prepare for battle!");
            break;
        case 1:
            printf("You stumble upon a mysterious wizard's tower. The air is thick with magic.");
            break;
        case 2:
            printf("You find yourself in the middle of a raging storm. The wind howls and the waves crash against you.");
            break;
    }

    // Prompt the player for an action
    printf("What do you want to do? ( %s ) ", actions[0] - 1, actions[1] - 1, actions[2] - 1, actions[3] - 1);

    // Get the player's choice
    int choice = rand() % 4;

    // Execute the player's action
    switch (choice)
    {
        case 0:
            printf("You attack the creature. It is slain!");
            break;
        case 1:
            printf("You cast a spell on the creature. It is weakened.");
            break;
        case 2:
            printf("You negotiate with the creature. It agrees to leave you alone.");
            break;
        case 3:
            printf("You flee from the creature. You escape unscathed.");
            break;
    }

    // End the game
    printf("Thank you for playing, %s. You have bravely completed your journey.", name);

    return 0;
}