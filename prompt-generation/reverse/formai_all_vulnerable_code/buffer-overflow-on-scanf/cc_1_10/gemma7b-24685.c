//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt_house()
{
    system("cls");
    printf("The cold wind howls through the crumbling facade of the Blackwood Manor.\n");
    printf("The stench of decay permeates the air, a symphony of rotting flesh and damp earth.\n");
    printf("A sense of dread creeps into your bones as you approach the imposing structure.\n");
    printf("The front door swings open with a deafening screech, and you find yourself in...\n");

    // Randomly choose a haunted room
    int room_num = rand() % 3;

    switch (room_num)
    {
        case 0:
            printf("You have entered the Blood Room, where the crimson walls drip with blood.\n");
            break;
        case 1:
            printf("The Whispering Hall echoes with the voices of tormented souls.\n");
            break;
        case 2:
            printf("The Crypt of Shadows holds secrets beyond your comprehension.\n");
            break;
    }

    // Make the ghost appear
    printf("A ghostly figure, its decaying skin and withered limbs, turns to face you.\n");
    printf("Its eyes burn like embers, and its voice whispers threats.\n");

    // Randomly choose a spooky sound effect
    int sound_effect = rand() % 3;

    switch (sound_effect)
    {
        case 0:
            printf("The sound of chains rattling.\n");
            break;
        case 1:
            printf("The scraping of nails against wood.\n");
            break;
        case 2:
            printf("The sound of a dripping faucet.\n");
            break;
    }

    // Give the player a chance to flee
    printf("Do you want to flee? (Y/N): ");

    char flee_response;
    scanf("%c", &flee_response);

    if (flee_response == 'Y')
    {
        printf("You sprint out of the manor, leaving the ghostly figure behind.\n");
    }
    else
    {
        printf("The ghostly figure wraps its cold hand around your throat, and you meet a gruesome end.\n");
    }
}

int main()
{
    haunt_house();

    return 0;
}