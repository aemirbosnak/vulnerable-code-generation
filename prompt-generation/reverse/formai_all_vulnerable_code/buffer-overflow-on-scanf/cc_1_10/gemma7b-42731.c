//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("Welcome to the Cave of Wonders!\n");
    printf("You are in a dark cave, and the only sound is your breathing. You have a sword and a torch in your hand.\n");
    printf("What do you want to do? (help, go north, go south, go east, go west, attack, use torch)\n");

    char input;
    scanf(" %c", &input);

    switch (input)
    {
        case 'h':
            printf("You have the following commands:\n");
            printf("help - Displays this message\n");
            printf("go north - Attempts to travel north\n");
            printf("go south - Attempts to travel south\n");
            printf("go east - Attempts to travel east\n");
            printf("go west - Attempts to travel west\n");
            printf("attack - Attacks the monster\n");
            printf("use torch - Uses the torch to light up the cave\n");
            break;

        case 'g':
            printf("Please specify the direction you want to travel in (north, south, east, west): ");
            char direction;
            scanf(" %c", &direction);

            switch (direction)
            {
                case 'n':
                    printf("You traveled north.\n");
                    break;
                case 's':
                    printf("You traveled south.\n");
                    break;
                case 'e':
                    printf("You traveled east.\n");
                    break;
                case 'w':
                    printf("You traveled west.\n");
                    break;
                default:
                    printf("Invalid direction.\n");
                    break;
            }
            break;

        case 'a':
            printf("You attacked the monster. The monster is defeated.\n");
            break;

        case 'u':
            printf("You used the torch. The cave is now lit up.\n");
            break;

        default:
            printf("Invalid command.\n");
            break;
    }

    return;
}