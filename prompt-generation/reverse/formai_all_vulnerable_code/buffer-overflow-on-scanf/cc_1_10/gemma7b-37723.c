//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char mystery[100] = "The Haunted Holms";
    int i = 0;

    printf("Welcome to the Haunted Holms!\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Hello, %s, prepare to be spooked!\n", name);

    // The mysterious events begin...
    for (i = 0; i < 10; i++)
    {
        printf("You hear a chilling sound... what is it?\n");
        char sound[20];
        scanf("%s", sound);

        if (strcmp(sound, "screaming") == 0)
        {
            printf("Your blood turns to ice as you hear a scream from within the house.\n");
        }
        else if (strcmp(sound, "footsteps") == 0)
        {
            printf("A cold wind blows through the halls, carrying the scent of decaying roses.\n");
        }
        else if (strcmp(sound, "whispering") == 0)
        {
            printf("A disembodied voice whispers secrets into your ear.\n");
        }
        else
        {
            printf("Nothing happens... for now.\n");
        }

        printf("What do you do? (type 'exit' to leave): ");
        char action[20];
        scanf("%s", action);

        if (strcmp(action, "exit") == 0)
        {
            break;
        }
    }

    printf("Thank you for visiting the Haunted Holms, %s. Hope you survived!\n", name);
    printf("The mystery of %s has been solved.", mystery);
}