//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, score = 0, lives = 3;
    char name[20];

    printf("Welcome to the Dungeon of Doom, %s!\n", name);
    printf("You are in a dark and treacherous cave.\n");
    printf("Three options appear before you:\n");

    // Option 1: Attack
    printf("1. Attack the menacing goblin with your sword.\n");

    // Option 2: Use magic to dispel the goblin's illusions.
    printf("2. Cast a spell to weaken the goblin's defenses.\n");

    // Option 3: Attempt to negotiate with the goblin.
    printf("3. Attempt to negotiate with the goblin.\n");

    printf("Please make your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You charged at the goblin with your sword, but he was too quick and dodged your attack.\n");
            break;
        case 2:
            printf("You cast a spell and the goblin's illusions dissipated, revealing a weak creature.\n");
            score++;
            break;
        case 3:
            printf("You attempted to negotiate with the goblin, but he was not willing to listen.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // Check if the player has won or lost
    if (score >= 3)
    {
        printf("Congratulations, %s! You have defeated the goblin and saved the world!\n", name);
    }
    else if (lives == 0)
    {
        printf("Game over, %s. You have run out of lives.\n", name);
    }
    else
    {
        printf("Prepare for the next battle, %s. You have %d lives left.\n", name, lives);
    }

    return 0;
}