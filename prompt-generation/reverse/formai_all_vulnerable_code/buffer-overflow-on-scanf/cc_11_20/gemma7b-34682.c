//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char input[20];
    int room = 1;
    int inventory[] = {0, 0, 0, 0, 0};
    char *map[] = {"A", "B", "C", "D", "E"};

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in room %s. You have %d items in your inventory.\n", map[room], inventory[0]);

    while (1)
    {
        printf("Please enter your command: ");
        scanf("%s", input);

        if (strcmp(input, "go") == 0)
        {
            printf("Which direction do you want to go? (north, south, east, west)\n");
            scanf("%s", input);

            if (strcmp(input, "north") == 0)
            {
                if (room == 1)
                {
                    printf("You cannot go north.\n");
                }
                else
                {
                    room++;
                    printf("You have moved north to room %s. You have %d items in your inventory.\n", map[room], inventory[0]);
                }
            }
            else if (strcmp(input, "south") == 0)
            {
                if (room == 5)
                {
                    printf("You cannot go south.\n");
                }
                else
                {
                    room--;
                    printf("You have moved south to room %s. You have %d items in your inventory.\n", map[room], inventory[0]);
                }
            }
            else if (strcmp(input, "east") == 0)
            {
                printf("You cannot go east.\n");
            }
            else if (strcmp(input, "west") == 0)
            {
                printf("You cannot go west.\n");
            }
        }
        else if (strcmp(input, "look") == 0)
        {
            printf("You are in room %s. You have %d items in your inventory.\n", map[room], inventory[0]);
        }
        else if (strcmp(input, "inventory") == 0)
        {
            printf("Your inventory: ");
            for (int i = 0; i < 5; i++)
            {
                if (inventory[i] > 0)
                {
                    printf("%d ", inventory[i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}