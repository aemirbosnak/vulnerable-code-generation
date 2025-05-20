//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spooky_sounds(int);

int main()
{
    int choice;
    char name[20];
    time_t t;

    printf("Welcome to Spooky Manor, %s. Prepare for a fright!\n", name);

    t = time(NULL);
    srand(t);

    // Play a spooky sound randomly
    spooky_sounds(rand() % 3);

    // Choose a path
    printf("Please choose a path:\n");
    printf("1. The Bloody Corridor\n");
    printf("2. The Haunted Hallway\n");
    printf("3. The Twisted Staircase\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You chose the Bloody Corridor. Prepare for a bloodcurdling encounter!\n");
            break;
        case 2:
            printf("You chose the Haunted Hallway. Prepare for ghostly whispers and chilling shadows.\n");
            break;
        case 3:
            printf("You chose the Twisted Staircase. Prepare for a terrifying journey through time.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

void spooky_sounds(int sound_num)
{
    switch (sound_num)
    {
        case 0:
            printf("Sounds of footsteps and breathing.\n");
            break;
        case 1:
            printf("Screams and cries. Ouch!\n");
            break;
        case 2:
            printf("A dripping faucet and a ghostly moan. Eek!\n");
            break;
    }
}