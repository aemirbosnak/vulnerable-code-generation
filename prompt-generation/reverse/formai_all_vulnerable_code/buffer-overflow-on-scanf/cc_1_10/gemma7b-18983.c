//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt_house()
{
    int i, j, k, rand_num;
    char str[100];

    // Create a haunted house environment
    printf("You find yourself in a crumbling haunted house.\n");
    printf("The air is thick with the scent of decay and anticipation.\n");

    // Generate random events
    rand_num = rand() % 5;
    switch (rand_num)
    {
        case 0:
            printf("Suddenly, a cold wind blows through the house, extinguishing the candles.\n");
            break;
        case 1:
            printf("A ghostly figure appears before you, its eyes glowing.\n");
            break;
        case 2:
            printf("You hear voices whispering secrets in your ear.\n");
            break;
        case 3:
            printf("A demonic presence surrounds you, its presence making you feel helpless.\n");
            break;
        case 4:
            printf("A bloodcurdling scream echoes through the house as you flee in terror.\n");
            break;
    }

    // Ask the user to enter a command
    printf("What do you want to do? (enter 'help' for instructions)\n");
    scanf("%s", str);

    // Check if the user wants to leave
    if (strcmp(str, "leave") == 0)
    {
        printf("You escape the haunted house, breathing a sigh of relief.\n");
    }
    // Otherwise, the user must deal with the haunting
    else
    {
        printf("The haunting continues, and you are trapped in the house.\n");
    }
}

int main()
{
    int i;

    // Loop to simulate multiple hauntings
    for (i = 0; i < 5; i++)
    {
        haunt_house();
    }

    return 0;
}