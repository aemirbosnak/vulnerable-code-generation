//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int r, choice, i, j, k, l, m, n;
    char ch, name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s, to the Haunted House of Thornfield Manor.\n", name);

    printf("You wake up in a cold and dimly lit room.\n");
    printf("The only sound is your breathing and the clock ticking.\n");

    printf("Suddenly, a gust of wind blows through the windows, extinguishing the candles.\n");
    printf("A cold wind whips around you, and you feel a presence in the room.\n");

    printf("Do you want to stay in the room or try to escape? (1/2) ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You remain in the room, hoping for the wind to subside.\n");
            break;
        case 2:
            printf("You frantically search for a way to escape, but the doors and windows are bolted shut.\n");
            break;
    }

    printf("As you sit there, a cold hand brushes against your skin.\n");
    printf("You hear a whisper in your ear, 'You're not alone...'\n");

    printf("Suddenly, a mirror on the wall cracks, and a ghostly figure emerges.\n");
    printf("The figure is tall and slender, with long, flowing hair and piercing eyes.\n");

    printf("The figure turns to you and speaks, 'You have been chosen, %s. You must be the one to save us from this cursed house.\n", name);

    printf("Do you want to fight back or submit to the figure's will? (1/2) ");
    scanf("%d", &r);

    switch (r)
    {
        case 1:
            printf("You try to fight back, but the figure is too powerful. It overpowers you and takes your soul.\n");
            break;
        case 2:
            printf("You submit to the figure's will, and it takes you on a journey through the haunted house.\n");
            break;
    }

    printf("The end.\n");
}