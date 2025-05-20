//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int spooky_number = rand() % 11;

    printf("You have entered a haunted house.\n");
    printf("The air is thick with the scent of decaying flowers.\n");
    printf("As you explore the house, you hear whispers in the wind.\n");

    switch (spooky_number)
    {
        case 0:
            printf("You hear a soft groan and feel a cold hand brush against your skin.\n");
            break;
        case 1:
            printf("You see a ghostly figure standing in the hallway.\n");
            break;
        case 2:
            printf("You hear footsteps echoing through the house.\n");
            break;
        case 3:
            printf("You smell the scent of burning incense and feel a presence watching you.\n");
            break;
        case 4:
            printf("You see a bloodstained letter on the floor.\n");
            break;
        case 5:
            printf("You hear a voice calling your name.\n");
            break;
        case 6:
            printf("You feel a cold wind blowing on your face and hear the sound of chains rattling.\n");
            break;
        case 7:
            printf("You hear a scream and see a ghost flying towards you.\n");
            break;
        case 8:
            printf("You smell the scent of decay and hear the sound of your own heartbeat.\n");
            break;
        case 9:
            printf("You hear the sound of a clock ticking and feel a sense of dread.\n");
            break;
        case 10:
            printf("You see a mirror reflecting your own face and feel a connection to the house.\n");
            break;
    }

    printf("Do you want to leave the haunted house? (Y/N)\n");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y')
    {
        printf("You escape the haunted house.\n");
    }
    else
    {
        printf("You are trapped in the haunted house forever.\n");
    }

    return 0;
}