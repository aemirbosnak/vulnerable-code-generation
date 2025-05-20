//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int choice, haunted_house_num, haunt_sound_num;
    char character_name[20];

    printf("Please enter your character's name: ");
    scanf("%s", character_name);

    printf("Welcome, %s, to the Haunted Mansion. Would you like to enter? (1/2): ", character_name);
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You have chosen to enter the haunted house. Please select a haunted house number: ");
        scanf("%d", &haunted_house_num);

        switch (haunted_house_num)
        {
            case 1:
                haunt_sound_num = 1;
                break;
            case 2:
                haunt_sound_num = 2;
                break;
            case 3:
                haunt_sound_num = 3;
                break;
            default:
                haunt_sound_num = 0;
                break;
        }

        printf("You have chosen haunted house number %d. Prepare for a spooky encounter... ", haunted_house_num);

        switch (haunt_sound_num)
        {
            case 1:
                printf("Sounds of creaking floorboards and disembodied voices...\n");
                break;
            case 2:
                printf("Screams and wails echo through the halls...\n");
                break;
            case 3:
                printf("The scent of decay and blood permeates the air...\n");
                break;
            default:
                printf("No haunting sounds.\n");
                break;
        }

        printf("Suddenly, a cold wind blows through the halls, and the hairs on your arms stand on end. You hear footsteps approaching... What do you do? (1/2): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("You flee in terror, running through the halls. You hear the footsteps receding behind you...\n");
        }
        else
        {
            printf("You confront the source of the sound, but find nothing. You are alone in the haunted house...\n");
        }
    }
    else
    {
        printf("You have chosen to leave the haunted mansion. Please come back another day... \n");
    }

    return;
}