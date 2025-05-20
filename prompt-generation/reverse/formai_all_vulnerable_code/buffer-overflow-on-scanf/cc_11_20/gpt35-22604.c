//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, done = 0;
    srand(time(NULL));

    printf("You find yourself standing in front of an old abandoned building.\n");
    printf("As you walk closer, you notice that the door is slightly ajar.\n");
    printf("Do you:\n");
    printf("1) Enter the building.\n");
    printf("2) Walk away.\n");
    scanf("%d", &choice);

    if (choice == 2)
    {
        printf("You decide not to enter the building and continue walking down the street.\n");
        return 0;
    }

    printf("You push the door open and step inside.\n");
    printf("The air is musty and there's a faint smell of decay in the air.\n");

    int random_number = rand() % 3 + 1;
    char* message;

    switch (random_number)
    {
        case 1:
            message = "You hear a faint whisper in the distance.";
            break;
        case 2:
            message = "You hear footsteps coming from upstairs.";
            break;
        case 3:
            message = "You hear a loud crash from a nearby room.";
            break;
    }

    printf("%s\n", message);

    printf("Do you:\n");
    printf("1) Investigate the sound.\n");
    printf("2) Ignore the sound and continue exploring.\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You cautiously make your way towards the source of the sound.\n");
        printf("As you turn a corner, you are confronted by a ghostly figure.\n");
        printf("You scream and run towards the exit, only to find that the door is now locked.\n");
        printf("You are trapped in the haunted house...\n");
        done = 1;
    }

    while (!done)
    {
        random_number = rand() % 3 + 1;

        switch (random_number)
        {
            case 1:
                message = "You hear a faint whisper in the distance.";
                break;
            case 2:
                message = "You hear footsteps coming from upstairs.";
                break;
            case 3:
                message = "You hear a loud crash from a nearby room.";
                break;
        }

        printf("%s\n", message);

        printf("Do you:\n");
        printf("1) Investigate the sound.\n");
        printf("2) Ignore the sound and continue exploring.\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("You cautiously make your way towards the source of the sound.\n");
            printf("As you turn a corner, you are confronted by a ghostly figure.\n");
            printf("You scream and run towards the exit, only to find that the door is now locked.\n");
            printf("You are trapped in the haunted house...\n");
            done = 1;
        }
    }

    return 0;
}