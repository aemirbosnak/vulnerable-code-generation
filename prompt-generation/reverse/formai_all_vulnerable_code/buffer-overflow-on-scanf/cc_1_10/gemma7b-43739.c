//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void haunted_house()
{
    system("clear");
    printf("You find yourself in a dilapidated Victorian mansion, Thornfield Hall.\n");
    printf("The air is thick with the scent of decaying roses and something else... unsettling.\n");
    printf("The only sounds are the ticking clock and your own breathing.\n");

    // Randomly generate a ghostly encounter
    int encounter = rand() % 3;

    switch (encounter)
    {
        case 0:
            printf("A cold wind whips through the halls, extinguishing the candles.\n");
            printf("Suddenly, a ghostly figure appears before you, its eyes burning like embers.\n");
            printf("The figure whispers secrets into your ear, but you can't understand what it says.\n");
            break;
        case 1:
            printf("The flickering candlelight casts long, ominous shadows on the walls.\n");
            printf("A disembodied hand reaches out from the darkness, trying to grab you.\n");
            printf("You hear voices echoing through the halls, but they fade into silence as the hand retreats.\n");
            break;
        case 2:
            printf("The scent of blood and decay fills the air.\n");
            printf("You find a bloodstained letter on the floor, detailing a gruesome murder.\n");
            printf("Suddenly, you hear a noise behind you and turn around, but there is nothing there.\n");
            break;
    }

    // Ask the player if they want to leave
    char leave = 'n';
    printf("Do you want to leave Thornfield Hall? (y/n): ");
    scanf("%c", &leave);

    // If the player wants to leave, they are transported to safety
    if (leave == 'y')
    {
        printf("You escape Thornfield Hall and breathe a sigh of relief.\n");
    }
    else
    {
        printf("You are trapped in Thornfield Hall, forever.\n");
    }
}

int main()
{
    haunted_house();

    return 0;
}