//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, choice, haunted_house_simulation();

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please select an option:\n");
    printf("1. Enter the house.\n");
    printf("2. Exit the house.\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            haunted_house_simulation();
            break;
        case 2:
            printf("Thank you for visiting the haunted house simulator.\n");
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}

int haunted_house_simulation()
{
    int spooky_sounds, ghostly_presence, bloodcurdling_screams;

    printf("You have entered the haunted house.\n");

    spooky_sounds = rand() % 5;
    ghostly_presence = rand() % 3;
    bloodcurdling_screams = rand() % 2;

    switch (spooky_sounds)
    {
        case 0:
            printf("A faint scratching sound.\n");
            break;
        case 1:
            printf("A loud groan.\n");
            break;
        case 2:
            printf("A creepy whisper.\n");
            break;
        case 3:
            printf("A bloodcurdling scream.\n");
            break;
        case 4:
            printf("A ghostly moan.\n");
            break;
    }

    switch (ghostly_presence)
    {
        case 0:
            printf("You feel a cold breeze on your skin.\n");
            break;
        case 1:
            printf("You hear footsteps behind you.\n");
            break;
        case 2:
            printf("You see a ghostly figure hovering near you.\n");
            break;
    }

    switch (bloodcurdling_screams)
    {
        case 0:
            printf("You hear a scream.\n");
            break;
        case 1:
            printf("You hear a bloodcurdling scream.\n");
            break;
    }

    printf("You have escaped the haunted house.\n");

    return 0;
}