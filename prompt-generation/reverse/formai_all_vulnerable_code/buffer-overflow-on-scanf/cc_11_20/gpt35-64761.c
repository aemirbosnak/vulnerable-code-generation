//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int ghostAppear = 0;
    int playerOption;
    int creakyFloor = 0;
    int doorOpen = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are in a dark and spooky mansion.\n");
    printf("While exploring a room, you hear a creaky floorboard and the door shuts behind you.\n");
    printf("You are now trapped inside.\n");

    while (ghostAppear < 3 && !doorOpen)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Search the room\n");
        printf("2. Try to open the door\n");
        printf("3. Wait\n");

        scanf("%d", &playerOption);

        switch (playerOption)
        {
            case 1:
                printf("\nYou search the room and find nothing useful.\n");
                break;

            case 2:
                printf("\nYou try to open the door, but it is locked.\n");
                if (creakyFloor == 0)
                {
                    printf("You hear a creaky floorboard in the hallway.\n");
                    creakyFloor = 1;
                }
                else if (creakyFloor == 1)
                {
                    printf("You hear another creaky floorboard, and for a split second you see a ghostly figure in the hallway.\n");
                    ghostAppear++;
                    creakyFloor = 2;
                }
                else
                {
                    printf("You hear several creaky floorboards, and the ghostly figure slowly advances towards you...\n");
                    ghostAppear++;
                }
                break;

            case 3:
                printf("\nYou decide to wait and listen.\n");
                if (creakyFloor == 0)
                {
                    printf("You hear a creaky floorboard in the hallway.\n");
                    creakyFloor = 1;
                }
                else if (creakyFloor == 1)
                {
                    printf("You hear another creaky floorboard, and for a split second you see a ghostly figure in the hallway.\n");
                    ghostAppear++;
                    creakyFloor = 2;
                }
                else
                {
                    printf("You hear several creaky floorboards, and the ghostly figure slowly advances towards you...\n");
                    ghostAppear++;
                }
                break;

            default:
                printf("\nInvalid input, please choose option 1, 2, or 3.\n");
                break;
        }

        if (ghostAppear == 3)
        {
            printf("\nThe ghost appears in front of you, and you feel an icy chill run down your spine.\n");
            printf("You are trapped in the haunted house forever.\n");
        }

        if (rand() % 5 == 0)
        {
            doorOpen = 1;
        }
    }

    if (doorOpen == 1)
    {
        printf("\nYou hear a click, and the door opens.\n");
        printf("You have escaped the haunted house!\n");
    }

    return 0;
}