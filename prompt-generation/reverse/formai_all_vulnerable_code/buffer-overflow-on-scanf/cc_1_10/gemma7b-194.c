//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i = 0, j = 0, choice = 0, is_haunted = 1, spirit_encountered = 0;

    system("clear");
    printf("Welcome to the Haunted House Simulator.\n");
    printf("--------------------\n");

    while (is_haunted)
    {
        printf("Please choose an option:\n");
        printf("1. Enter the house.\n");
        printf("2. Leave the house.\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                system("clear");
                printf("You have entered the haunted house.\n");
                printf("Please wait while I create the atmosphere...\n");

                // Simulate a haunting atmosphere
                for (i = 0; i < 5; i++)
                {
                    sleep(1);
                    printf("CREAKING SOUND...\n");
                }

                printf("You hear a disembodied voice...\n");
                printf("The air is thick with the scent of decay...\n");
                printf("Do you feel a presence?\n");

                scanf("%d", &choice);

                if (choice == 1)
                {
                    spirit_encountered = 1;
                    printf("You have encountered a spirit.\n");
                    printf("The spirit has spoken to you...\n");
                }
                break;

            case 2:
                system("clear");
                printf("You have left the haunted house.\n");
                printf("Thank you for playing.\n");
                is_haunted = 0;
                break;
        }
    }

    if (spirit_encountered)
    {
        printf("The spirit has left you a message...\n");
        printf("The message is: You will never forget your visit to the haunted house.\n");
    }

    return;
}