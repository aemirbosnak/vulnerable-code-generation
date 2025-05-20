//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    time_t t;
    srand(time(NULL));

    int r = rand() % 3;

    switch (r)
    {
        case 0:
            printf("The front door swings open. You hear footsteps on the stairs.\n");
            break;
        case 1:
            printf("A cold wind whips through the halls, blowing out the candles.\n");
            break;
        case 2:
            printf("A disembodied voice whispers in your ear, 'Follow me...'\n");
            break;
    }

    printf("Suddenly, the lights flicker and go out. You are alone in the darkness.\n");

    r = rand() % 2;

    switch (r)
    {
        case 0:
            printf("You hear a soft moan and a cold hand brushes against your skin.\n");
            break;
        case 1:
            printf("You see a ghostly figure standing in the doorway, its eyes burning red.\n");
            break;
    }

    printf("Do you want to run?\n");

    char answer;
    scanf("%c", &answer);

    if (answer == 'y' || answer == 'Y')
    {
        printf("You sprint out of the house, fleeing into the night.\n");
    }
    else
    {
        printf("You are trapped in the haunted house, alone and terrified.\n");
    }
}