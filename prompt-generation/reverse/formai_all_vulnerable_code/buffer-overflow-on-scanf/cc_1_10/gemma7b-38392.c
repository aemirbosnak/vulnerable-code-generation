//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int age;
    int health = 100;
    int room = 1;

    printf("Welcome to the wacky world of Zork!\n");

    // Get the player's name and age
    printf("What is your name, brave traveler? ");
    scanf("%s", name);

    printf("And how old are you, %s? ", name);
    scanf("%d", &age);

    // Create a loop to simulate the adventure
    while (health > 0)
    {
        // Display the room description
        switch (room)
        {
            case 1:
                printf("You are in a dusty tavern.\n");
                break;
            case 2:
                printf("You are in a spooky castle.\n");
                break;
            case 3:
                printf("You are in a giant cave.\n");
                break;
        }

        // Get the player's command
        printf("What do you want to do? ");
        char command[20];
        scanf("%s", command);

        // Execute the player's command
        if (strcmp(command, "north") == 0)
        {
            room = 2;
        }
        else if (strcmp(command, "south") == 0)
        {
            room = 3;
        }
        else if (strcmp(command, "east") == 0)
        {
            room = 1;
        }
        else if (strcmp(command, "west") == 0)
        {
            room = 1;
        }
        else if (strcmp(command, "attack") == 0)
        {
            health -= 20;
            printf("You attacked a goblin and it attacked you back!\n");
        }
        else
        {
            printf("I don't understand your command.\n");
        }
    }

    // Game over
    printf("Game over, %s! You have died.\n", name);

    return 0;
}