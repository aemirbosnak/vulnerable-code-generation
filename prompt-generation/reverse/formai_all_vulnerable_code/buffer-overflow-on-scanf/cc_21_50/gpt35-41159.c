//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to the Haunted House Simulator.\n");
    printf("---------------------------------------\n");
    printf("You are the great detective, Sherlock Holmes, investigating a supposed haunted house.\n");
    printf("Your mission is to explore the house and solve the mystery behind the strange occurrences.\n");

    // Variables to keep track of game state
    int room = 1;
    bool ghostSeen = false;
    bool treasureFound = false;

    // Loop until game is over
    while (true)
    {
        // Display room description based on room number
        switch (room)
        {
            case 1:
                printf("\nYou are in the foyer of the haunted house.\n");
                printf("There are cobwebs everywhere and a strange feeling in the air.\n");
                printf("To the east is a dark hallway and to the west is a set of stairs going down.\n");
                break;
            case 2:
                printf("\nYou are in a long hallway.\n");
                printf("You hear footsteps coming from the north and a draft from the south.\n");
                printf("To the east is a door and to the west is a window.\n");
                break;
            case 3:
                printf("\nYou are in a dusty old library.\n");
                printf("There is a ghostly apparition floating in the corner of the room.\n");
                printf("To the north is a door and to the south is a hidden staircase.\n");
                break;
            case 4:
                printf("\nYou are in a dimly lit study.\n");
                printf("There is a large desk in the center of the room and a bookshelf on the wall.\n");
                printf("To the east is a secret passage and to the west is a window.\n");
                break;
            case 5:
                printf("\nYou are in a narrow secret passageway.\n");
                printf("There is a faint light coming from the end of the passage.\n");
                printf("To the east is a door and to the west is a set of stairs going up.\n");
                break;
            case 6:
                printf("\nYou are in a dimly lit dungeon.\n");
                printf("There is a treasure chest in the center of the room.\n");
                printf("To the east is a door and to the west is a set of stairs going up.\n");
                break;
            default:
                printf("\nYou have entered an invalid room number.\n");
                break;
        }

        // Take user input for which direction to go in
        char direction[10];
        printf("\nWhich direction do you want to go in? (north, south, east, west)\n");
        scanf("%s", direction);

        // Change room based on user input
        if (strcmp(direction, "north") == 0)
        {
            if (room == 3 && !ghostSeen)
            {
                printf("\nAs you walk towards the north door, the ghostly apparition floats in front of you and disappears.\n");
                ghostSeen = true;
            }
            else
            {
                printf("\nYou cannot go north from here.\n");
            }
        }
        else if (strcmp(direction, "south") == 0)
        {
            if (room == 5 || room == 6)
            {
                // End game if treasure is found
                if (treasureFound)
                {
                    printf("\nYou have made it out of the haunted house with the treasure!\n");
                    return 0;
                }
                else
                {
                    printf("\nYou cannot go south from here.\n");
                }
            }
            else
            {
                printf("\nYou cannot go south from here.\n");
            }
        }
        else if (strcmp(direction, "east") == 0)
        {
            if (room == 1)
            {
                room = 2;
            }
            else if (room == 2)
            {
                room = 4;
            }
            else if (room == 3)
            {
                room = 5;
            }
            else if (room == 4)
            {
                printf("\nYou have found a secret passage!\n");
                room = 5;
            }
            else if (room == 5)
            {
                room = 6;
            }
            else
            {
                printf("\nYou cannot go east from here.\n");
            }
        }
        else if (strcmp(direction, "west") == 0)
        {
            if (room == 1)
            {
                printf("\nYou cannot go west from here.\n");
            }
            else if (room == 2)
            {
                printf("\nYou cannot go west from here.\n");
            }
            else if (room == 3)
            {
                printf("\nYou cannot go west from here.\n");
            }
            else if (room == 4)
            {
                room = 2;
            }
            else if (room == 5)
            {
                room = 3;
            }
            else if (room == 6)
            {
                room = 5;
            }
            else
            {
                printf("\nYou cannot go west from here.\n");
            }
        }
        else
        {
            printf("\nInvalid direction entered.\n");
        }

        // Check for treasure in current room
        if (room == 6 && !treasureFound)
        {
            printf("\nYou have found the treasure!\n");
            treasureFound = true;
        }
    }

    return 0;
}