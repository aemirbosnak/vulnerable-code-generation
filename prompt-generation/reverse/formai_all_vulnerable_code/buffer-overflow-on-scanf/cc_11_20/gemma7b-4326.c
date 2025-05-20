//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    printf("Welcome, traveler! Please tell me your name:");
    scanf("%s", name);

    printf("Greetings, %s! Prepare for a journey through the bizarre and hilarious text-based adventure game of 'The Quest for the Missing Sandwich'.\n", name);

    // The Quest Begins
    int location = 1;
    int inventory[] = {0, 0, 0};

    while (location)
    {
        switch (location)
        {
            case 1:
                printf("You are in a dingy tavern. The air is thick with the smell of cheap ale and despair. You have a feeling you've been here before.\n");
                break;
            case 2:
                printf("You are in the belly of a giant worm. It's not a pleasant place to be. You have a sandwich in your inventory.\n");
                break;
            case 3:
                printf("You are in a medieval castle. There's a lot of gold and jewels here. You have a sword and a shield in your inventory.\n");
                break;
            default:
                printf("You have reached the end of the road, my friend. Congratulations!\n");
                location = 0;
                break;
        }

        // What will you do?
        char command[20];
        printf("Please enter your command:");
        scanf("%s", command);

        // Processing commands...
        if (strcmp(command, "north") == 0)
        {
            location = 2;
        }
        else if (strcmp(command, "south") == 0)
        {
            location = 3;
        }
        else if (strcmp(command, "east") == 0)
        {
            location = 4;
        }
        else if (strcmp(command, "west") == 0)
        {
            location = 5;
        }
        else if (strcmp(command, "eat") == 0)
        {
            if (inventory[2] > 0)
            {
                printf("Munch munch, you're eating a sandwich!\n");
                inventory[2] -= 1;
            }
            else
            {
                printf("You have nothing to eat. Sad face.\n");
            }
        }
        else if (strcmp(command, "attack") == 0)
        {
            if (inventory[0] > 0)
            {
                printf("You swing your sword and chop the head off a goblin. Nice kill!\n");
                inventory[0] -= 1;
            }
            else
            {
                printf("You have no weapon. You're a sitting duck.\n");
            }
        }
        else if (strcmp(command, "shield") == 0)
        {
            if (inventory[1] > 0)
            {
                printf("You put on your shield and feel invincible.\n");
                inventory[1] -= 1;
            }
            else
            {
                printf("You have no shield. You're vulnerable to attacks.\n");
            }
        }
        else
        {
            printf("I do not understand your command. Please try again.\n");
        }
    }

    printf("Thank you for playing, %s. May your journey be filled with delicious sandwiches and epic battles.\n", name);

    return 0;
}