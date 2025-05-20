//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are entering a very old and spooky house.\n");
    printf("You don't know what to expect, but you know it won't be good.\n");

    int ghost = rand() % 2;
    int noise = rand() % 100;

    if (ghost == 1)
    {
        printf("Oh no! You see a ghost!\n");
    }
    else
    {
        printf("Phew! No ghost in sight.\n");
    }

    if (noise > 50)
    {
        printf("You hear a loud noise from upstairs. Do you want to investigate? (y/n)\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y')
        {
            printf("You walk up the creaky stairs. The noise is coming from one of the rooms.\n");
            printf("As you approach the room you feel a chill down your spine.\n");
            printf("When you open the door, you see a shadowy figure moving in the corner of the room.\n");
            printf("You quickly realize that it's just an old coat hanging on the back of a chair.\n");
        }
        else
        {
            printf("You decide not to investigate. You hear the noise again, but it feels like it's getting closer.\n");
            printf("Suddenly, you feel a cold hand on your shoulder! You turn around, but there's nobody there.\n");
            printf("You run towards the door, but it's locked! You're trapped!\n");
        }
    }
    else
    {
        printf("You hear some strange noises, but they don't sound like they are coming from inside the house.\n");
        printf("It's probably just the wind.\n");
    }

    printf("You decide to leave the house and never come back. Goodbye!\n");

    return 0;
}