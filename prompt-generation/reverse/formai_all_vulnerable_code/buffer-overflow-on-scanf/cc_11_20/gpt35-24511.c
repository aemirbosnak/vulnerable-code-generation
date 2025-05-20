//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
/*
Text-Based Adventure Game - Escape the Island
Author: [Your Name]
Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice1, choice2;
    printf("Welcome to Escape the Island!\n");
    printf("You find yourself stranded on a deserted island.\n");
    printf("Your goal is to find a way off the island.\n\n");

    printf("You wake up on the beach with no memory of how you got there.\n");
    printf("You see a jungle in front of you and a cliff behind you.\n\n");

    printf("What do you want to do?\n");
    printf("1. Go into the jungle\n");
    printf("2. Climb up the cliff\n");
    scanf("%d", &choice1);

    if (choice1 == 1)
    {
        printf("You enter the jungle and see two paths.\n");
        printf("One path leads to a waterfall and the other leads to a cave.\n\n");

        printf("Which path do you want to take?\n");
        printf("1. Waterfall\n");
        printf("2. Cave\n");
        scanf("%d", &choice2);

        if (choice2 == 1)
        {
            printf("You arrive at the waterfall and see a boat.\n");
            printf("It looks like it could be repaired to be seaworthy.\n\n");

            printf("What do you want to do?\n");
            printf("1. Repair the boat\n");
            printf("2. Explore around the waterfall more\n");
            scanf("%d", &choice2);

            if (choice2 == 1)
            {
                printf("You successfully repair the boat.\n");
                printf("You set sail and eventually find your way back home.\n");
            }
            else if (choice2 == 2)
            {
                printf("You explore around the waterfall and find nothing of use.\n");
                printf("Do you want to go back to the jungle or explore further?\n");
                printf("1. Go back to the jungle\n");
                printf("2. Explore further\n");
                scanf("%d", &choice2);

                if (choice2 == 1)
                {
                    main(); // restart the game
                }
                else if (choice2 == 2)
                {
                    printf("You get lost in the jungle and are never found.\n");
                }
            }
            else
            {
                printf("Invalid choice.\n");
                main(); // restart the game
            }
        }
        else if (choice2 == 2)
        {
            printf("You arrive at the cave and see a river flowing through it.\n");
            printf("You can see something shiny at the bottom of the river.\n\n");

            printf("What do you want to do?\n");
            printf("1. Swim to the bottom of the river\n");
            printf("2. Explore around the cave more\n");
            scanf("%d", &choice2);

            if (choice2 == 1)
            {
                printf("You successfully retrieve the shiny object.\n");
                printf("It is a hammer and could be used to repair something.\n\n");

                printf("What do you want to do?\n");
                printf("1. Keep exploring the cave\n");
                printf("2. Go back to the jungle\n");
                scanf("%d", &choice2);

                if (choice2 == 1)
                {
                    printf("You explore the cave some more and find a map.\n");
                    printf("The map shows where a boat is located.\n\n");

                    printf("What do you want to do?\n");
                    printf("1. Follow the map to the boat\n");
                    printf("2. Keep exploring the cave\n");
                    scanf("%d", &choice2);

                    if (choice2 == 1)
                    {
                        printf("You follow the map and arrive at the boat.\n");
                        printf("You successfully repair the boat and set sail.\n");
                        printf("You eventually find your way back home.\n");
                    }
                    else if (choice2 == 2)
                    {
                        printf("You get lost in the cave and are never found.\n");
                    }
                }
                else if (choice2 == 2)
                {
                    main(); // restart the game
                }
                else
                {
                    printf("Invalid choice.\n");
                    main(); // restart the game
                }
            }
            else if (choice2 == 2)
            {
                printf("You explore around the cave and find nothing of use.\n");
                printf("Do you want to go back to the jungle or explore further?\n");
                printf("1. Go back to the jungle\n");
                printf("2. Explore further\n");
                scanf("%d", &choice2);

                if (choice2 == 1)
                {
                    main(); // restart the game
                }
                else if (choice2 == 2)
                {
                    printf("You get lost in the cave and are never found.\n");
                }
            }
            else
            {
                printf("Invalid choice.\n");
                main(); // restart the game
            }
        }
        else
        {
            printf("Invalid choice.\n");
            main(); // restart the game
        }
    }
    else if (choice1 == 2)
    {
        printf("You climb up the cliff and see a lighthouse in the distance.\n");
        printf("The lighthouse could provide a way to signal for help.\n\n");

        printf("What do you want to do?\n");
        printf("1. Go to the lighthouse\n");
        printf("2. Explore more around the cliff\n");
        scanf("%d", &choice2);

        if (choice2 == 1)
        {
            printf("You arrive at the lighthouse and find a signal flare gun.\n");
            printf("You successfully launch the flare and are rescued.\n");
        }
        else if (choice2 == 2)
        {
            printf("You explore around the cliff and find a fishing rod.\n");
            printf("You successfully catch fish to eat and survive for a few days.\n");
            printf("However, eventually you run out of food and are never found.\n");
        }
        else
        {
            printf("Invalid choice.\n");
            main(); // restart the game
        }
    }
    else
    {
        printf("Invalid choice.\n");
        main(); // restart the game
    }

    return 0;
}